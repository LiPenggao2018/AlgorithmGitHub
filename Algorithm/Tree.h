/**
     建立一颗树的类进行存储，实际上类就是结构体
*/
#pragma once
#include<string>
#include<iostream>
#include<vector>
using namespace std;
template<class T>
class Tree
{
public:
	Tree();
	~Tree();

	double getDoubleData();
	void setDoubleData(double data);
	string getStringData();
	void setStringData(string data);
	T getData();
	void setData(T data);

	Tree<T>* getLeftTree();
	void setLeftTree(Tree* leftTree);

	Tree<T>* getRightTree();
	void setRightTree(Tree* rightTree);

	Tree<T>* getFatherTree();
	void setFatherTree(Tree* fatherTree);

	int getHeight();
	void setHeight(int h);
private:
	double doubleData;
	string stringData;
	T data;
	Tree* leftTree;           
	Tree* rightTree;
	Tree* fatherTree;
	int height;                                             //叶子节点的高度为0，
};
