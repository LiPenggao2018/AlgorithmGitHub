/**
     ��1������һ���ѧ�ļ�������ʵ��+-�������㣬�Լ�����ֵ����㡣
	 ��2��������������ݹ������νṹ
	 ��3�����������vector,�õ���׺���ʽ
	 ��4��ͨ����һ��ջ��ֵ
*/
# pragma once
#include<iostream>
#include<vector>
#include"Tree.h"
#include"Tree.cpp"
#include<string>
using namespace std;

struct Priority                   //��������ȼ�
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

	void infixTranslatePostfix(vector<string >infix);                        //��׺���ʽת��׺���ʽ
	vector<Tree<T>*> getStackTree();
	void set(vector<Tree<T>*>stackTree);
	int calculatePriority(string ch);                                        //��ĳ������������ȼ�

	vector<string >getPostfix();

private:
	vector<Tree<T>*>stackTree;                              //����ջ�ṹ����һ�ű��ʽ�����ṹ,ջ�״��ָ��������ָ��
	vector<string >infix;
	vector<string >postfix;
	vector<string >operateStack;                           //�����ջ
	vector<Priority >priority;
};

