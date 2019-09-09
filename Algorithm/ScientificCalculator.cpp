#include"ScientificCalculator.h"

template<class T>
ScientificCalculator<T>::ScientificCalculator()
{
	Priority pri;
	pri.ch = "+";
	pri.priority = 1;                           //优先级从小到大，+ -为1级
	priority.push_back(pri);

	pri.ch = "-";
	pri.priority = 1;                           //优先级从小到大，+ -为1级
	priority.push_back(pri);

	pri.ch = "*";
	pri.priority = 2;                           //优先级从小到大，* /为2级
	priority.push_back(pri);

	pri.ch = "/";
	pri.priority = 2;                           //优先级从小到大，+ -为1级
	priority.push_back(pri);

	pri.ch = "(";
	pri.priority = 3;                           //优先级从小到大，+ -为1级
	priority.push_back(pri);

	pri.ch = ")";
	pri.priority = 0;                           //优先级从小到大，+ -为1级
	priority.push_back(pri);

}
template<class T>
ScientificCalculator<T>::~ScientificCalculator()
{

}

template<class T>
vector<Tree<T>*> ScientificCalculator<T>::getStackTree()
{
	return stackTree;
}

template<class T>
void ScientificCalculator<T>::set(vector<Tree<T>*>stackTree)
{
	this->stackTree = stackTree;
}

//------------------------------------------------------------------------------------
template<class T>
void ScientificCalculator<T>::constructTree(vector<string >postfix)
{
	//计算式的数据来自于文件读取或者键盘输入 后缀表达式建立树形结构
	Tree<T> *left, *right;
	for (int i = 0; i < postfix.size(); i++)
	{
		string ch = postfix[i];
		if (ch == "*" || ch == "+"||ch == "/" || ch == "-")
		{
			Tree<T> *treeB=new Tree<T>();
			treeB->setStringData(ch);
			right = stackTree.back();
			stackTree.pop_back();
			left = stackTree.back();
			stackTree.pop_back();
			treeB->setLeftTree(left);
			treeB->setReightTree(right);
			stackTree.push_back(treeB);   //父节点压人栈中
			
		}
		else
		{
			double data = stod(ch);              //string 转double
			Tree<T> *treeA=new Tree<T>();
			treeA->setDoubleData(data);
			stackTree.push_back(treeA);
		}
	}
	//最后栈中仅剩一个指向树根的指针

}

template<class T>
double ScientificCalculator<T>::calculateTree(vector<string >postfix)
{
	cout << endl;
	vector<double >result;
	string ch="";
	double a, b;
	for (int i = 0; i < postfix.size(); i++)
	{
		ch = postfix[i];
		if (ch == "+" || ch == "-" || ch == "*" || ch == "/")
		{
			b = result.back();
			result.pop_back();
			a = result.back();
			result.pop_back();

			if (ch == "+")
			{
				result.push_back(a + b);
				cout <<a<<"+"<<b<<"="<< a + b << endl;
				
			}
			else if (ch == "-")
			{
				result.push_back(a - b);
				cout << a << "-" << b << "=" << a - b << endl;
			}
			else if (ch == "*")
			{
				result.push_back(a * b);
				cout << a << "*" << b << "=" << a * b << endl;
			}
			else if(ch == "/")
			{
				result.push_back(a / b);
				cout << a << "/" << b << "=" << a / b << endl;
			}
		}
		else
		{
			result.push_back(stod(ch));
		}
	}
	return result[0];
}

template<class T>
void ScientificCalculator<T>::visitTree(Tree<T> *node)
{

	if (node)
	{
		visitTree(node->getLeftTree());
		if (node->getLeftTree() != nullptr&&node->getRightTree() != nullptr)
		{
			cout << node->getStringData();
		}
		else
		{
			cout << node->getDoubleData();
		}
		
		visitTree(node->getRightTree());
	}
}

//--------------------------------------------------------------------------------------
template<class T>
void ScientificCalculator<T>::infixTranslatePostfix(vector<string >infix)   //3+4/2+(5-6)*7      1.0版适用于带括号的四则运算
{


	operateStack.clear();
	for (int i = 0; i < infix.size(); i++)
	{
		cout << infix[i];
	}
	cout << endl;
	for (int i = 0; i < infix.size(); i++)                                  //前缀表达式
	{
		string ch = infix[i];
		if (ch == "*" || ch == "+" || ch == "-" || ch == "/" || ch == "(" || ch == ")")
		{
			int currentPriority = calculatePriority(ch);
			if (operateStack.size() == 0)
			{
				operateStack.push_back(ch);
			}
			else
			{
				if (currentPriority == calculatePriority(")"))                                      //如果当前是反括号）
				{
					for (int i = 0; i < operateStack.size();)
					{
						int stackTopPriority = calculatePriority(operateStack.back());
						if (stackTopPriority != calculatePriority("("))                  //匹配括号
						{
							postfix.push_back(operateStack.back());
							operateStack.pop_back();
						}
						else
						{
							operateStack.pop_back();                  //只弹出不入栈
							break;
						}
					}
				}
				else                          //当前不为右括号
				{
					for (int i = 0; i < operateStack.size();)       //这里i++都有问题
					{
						int stackTopPriority = calculatePriority(operateStack.back());
						if (stackTopPriority == calculatePriority("("))
						{
							break;
						}
						else if (currentPriority <= stackTopPriority)                      //比较原则：若比栈top运算符小，则将栈顶元素弹出  //比较优先级
						{
							postfix.push_back(operateStack.back());
							operateStack.pop_back();
						}
						else
						{
							break;
						}
					}//for
                   operateStack.push_back(ch);
				}//else
			}
		}
		else
		{
			postfix.push_back(ch);                                    //将前缀表达式中的一个字符压人后缀表达式栈中
		}
	}
	for (int i =0; i<operateStack.size();)
	{
		postfix.push_back(operateStack.back());
		operateStack.pop_back();
	}

	cout << "postfix:";
	for (int i = 0; i < postfix.size(); i++)
	{
		cout << postfix[i];
	}
	cout << endl;
}

template<class T>
int ScientificCalculator<T>::calculatePriority(string ch)
{
	for (int i = 0; i < priority.size(); i++)
	{
		if (priority[i].ch == ch)
		{
			return priority[i].priority;
		}
	}
}

template<class T>
vector<string >ScientificCalculator<T>::getPostfix()
{
	return postfix;
}

