/**
     binary search tree
	 ��1��ԭ�����������С��������
	 ��2�����¶���ģ���ࣺģ��������ģ��ʵ�������һ������
*/

#pragma once
#include"Tree.h"

template<class T>                               //����T������Ϊ��ͨ��Ա����������,T���ǹؼ���
class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	//------------------------��������---------------------------
	void constructBinarySearchTree(vector<T >datas);
	Tree<T>* find(T data, Tree<T>* nodePtr);                      //T���������ֻ����ַ�
	Tree<T>* getRoot();
	void setRoot(Tree<T>* root);
	void insertNode(T data,Tree<T>* node);
	void visitSearchTree(Tree<T> * node);
	Tree<T> * findMin(Tree<T> *root);
	Tree<T> * findMax(Tree<T> *root);
private:
    Tree<T> *root;                         //������ڵ�
};
