/**
       Tree ���ͽڵ�ṹ���������������õ�����
*/

#include"Tree.h"
#pragma once
template<class T>
Tree<T>::Tree()
{
	this->leftTree =nullptr;
	this->rightTree = nullptr;
	this->fatherTree = nullptr;
	this->height = 0;                              //ÿһ��Ҷ�ӽڵ�ĸ߶ȶ���0
}

template<class T>
Tree<T>::~Tree()
{
	
}
//---------------------------------���ĺ�����----------------------------------
template<class T>
double Tree<T>::getDoubleData()
{
	return doubleData;
}

template<class T>
void Tree<T>::setDoubleData(double data)
{
	this->doubleData = data;
}

template<class T>
string Tree<T>::getStringData()
{
	return stringData;
}

template<class T>
void Tree<T>::setStringData(string data)
{
	this->stringData = data;
}

template<class T>
Tree<T>* Tree<T>::getLeftTree()
{
	return  leftTree;
}

template<class T>
void Tree<T>::setLeftTree(Tree* leftTree)
{
	this->leftTree = leftTree;
}

template<class T>
Tree<T>* Tree<T>::getRightTree()
{
	return rightTree;
}

template<class T>
void Tree<T>::setRightTree(Tree* rightTree)
{
	this->rightTree = rightTree;
}

template<class T>
Tree<T>*Tree<T>::getFatherTree()
{
	return fatherTree;
}

template<class T>
void Tree<T>::setFatherTree(Tree* fatherTree)
{
	this->fatherTree = fatherTree;
}


template<class T>
T Tree<T>::getData()
{
	return data;
}

template<class T>
void Tree<T>::setData(T data)
{
	this->data = data;
}

template<class T>
int Tree<T>::getHeight()
{
	return height;
}

template<class T>
void Tree<T>::setHeight(int h)
{
	this->height = h;
}