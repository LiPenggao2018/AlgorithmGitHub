/**
     binary search tree
	 （1）原则：中序遍历从小到大排序
	 （2）以下定义模板类：模板类是类模板实例化后的一个产物
*/

#pragma once
#include"Tree.h"

template<class T>                               //类型T可以作为普通成员变量的类型,T不是关键字
class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	//------------------------基本操作---------------------------
	void constructBinarySearchTree(vector<T >datas);
	Tree<T>* find(T data, Tree<T>* nodePtr);                      //T可以是数字或者字符
	Tree<T>* getRoot();
	void setRoot(Tree<T>* root);
	void insertNode(T data,Tree<T>* node);
	void visitSearchTree(Tree<T> * node);
	Tree<T> * findMin(Tree<T> *root);
	Tree<T> * findMax(Tree<T> *root);
private:
    Tree<T> *root;                         //定义根节点
};
