#include"ScientificCalculator.h"

template<class T>
ScientificCalculator<T>::ScientificCalculator()
{
	Priority pri;
	pri.ch = "+";
	pri.priority = 1;                           //���ȼ���С����+ -Ϊ1��
	priority.push_back(pri);

	pri.ch = "-";
	pri.priority = 1;                           //���ȼ���С����+ -Ϊ1��
	priority.push_back(pri);

	pri.ch = "*";
	pri.priority = 2;                           //���ȼ���С����* /Ϊ2��
	priority.push_back(pri);

	pri.ch = "/";
	pri.priority = 2;                           //���ȼ���С����+ -Ϊ1��
	priority.push_back(pri);

	pri.ch = "(";
	pri.priority = 3;                           //���ȼ���С����+ -Ϊ1��
	priority.push_back(pri);

	pri.ch = ")";
	pri.priority = 0;                           //���ȼ���С����+ -Ϊ1��
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
	//����ʽ�������������ļ���ȡ���߼������� ��׺���ʽ�������νṹ
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
			stackTree.push_back(treeB);   //���ڵ�ѹ��ջ��
			
		}
		else
		{
			double data = stod(ch);              //string תdouble
			Tree<T> *treeA=new Tree<T>();
			treeA->setDoubleData(data);
			stackTree.push_back(treeA);
		}
	}
	//���ջ�н�ʣһ��ָ��������ָ��

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
void ScientificCalculator<T>::infixTranslatePostfix(vector<string >infix)   //3+4/2+(5-6)*7      1.0�������ڴ����ŵ���������
{


	operateStack.clear();
	for (int i = 0; i < infix.size(); i++)
	{
		cout << infix[i];
	}
	cout << endl;
	for (int i = 0; i < infix.size(); i++)                                  //ǰ׺���ʽ
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
				if (currentPriority == calculatePriority(")"))                                      //�����ǰ�Ƿ����ţ�
				{
					for (int i = 0; i < operateStack.size();)
					{
						int stackTopPriority = calculatePriority(operateStack.back());
						if (stackTopPriority != calculatePriority("("))                  //ƥ������
						{
							postfix.push_back(operateStack.back());
							operateStack.pop_back();
						}
						else
						{
							operateStack.pop_back();                  //ֻ��������ջ
							break;
						}
					}
				}
				else                          //��ǰ��Ϊ������
				{
					for (int i = 0; i < operateStack.size();)       //����i++��������
					{
						int stackTopPriority = calculatePriority(operateStack.back());
						if (stackTopPriority == calculatePriority("("))
						{
							break;
						}
						else if (currentPriority <= stackTopPriority)                      //�Ƚ�ԭ������ջtop�����С����ջ��Ԫ�ص���  //�Ƚ����ȼ�
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
			postfix.push_back(ch);                                    //��ǰ׺���ʽ�е�һ���ַ�ѹ�˺�׺���ʽջ��
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

