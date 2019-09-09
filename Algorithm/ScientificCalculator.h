/**
     （1）编制一款科学的计算器，实现+-×÷运算，以及求积分等运算。
	 （2）根据输入的数据构造树形结构
	 （3）遍历输出到vector,得到后缀表达式
	 （4）通过另一个栈求值
*/
# pragma once
#include<iostream>
#include<vector>
#include"Tree.h"
#include"Tree.cpp"
#include<string>
using namespace std;

struct Priority                   //运算符优先级
{
	string ch;
	int priority;
};

template<class T>
class ScientificCalculator
{
public:
	ScientificCalculator<T>();
	~ScientificCalculator<T>();
	void constructTree(vector<string >postfix);
	double calculateTree(vector<string >postfix);
	void visitTree(Tree<T> * node);

	void infixTranslatePostfix(vector<string >infix);                        //中缀表达式转后缀表达式
	vector<Tree<T>*> getStackTree();
	void set(vector<Tree<T>*>stackTree);
	int calculatePriority(string ch);                                        //求某个运算符的优先级

	vector<string >getPostfix();

private:
	vector<Tree<T>*>stackTree;                              //借用栈结构构造一颗表达式的树结构,栈底存放指向树根的指针
	vector<string >infix;
	vector<string >postfix;
	vector<string >operateStack;                           //运算符栈
	vector<Priority >priority;
};

