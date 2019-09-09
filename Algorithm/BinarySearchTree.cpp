/**
�ڱ���Ŀ�У����е���ͺ���������Ϊ��Դ��ģ���࣬�Է���֮�����չ���Լ�ʹ��STL�⺯��
*/
#include"BinarySearchTree.h"

template<class T>                                                                 //ģ����
BinarySearchTree<T>::BinarySearchTree()                       //�������ⶨ�壬������<����>
{

}

template<class T>
BinarySearchTree<T>::~BinarySearchTree()
{

}

template<class T>
void BinarySearchTree<T>::constructBinarySearchTree(vector<T > datas)
{
	Tree<T> *node=new Tree<T>();
	node->setData(datas[0]);                     //����һ��������Ϊ���ڵ�
	setRoot(node);
	for (int i = 1; i < (int)datas.size(); i++)
	{                                       //�Ե�һ��������Ϊ����������Ĳ�����ߣ�����С�Ĳ����ұ�
		insertNode(datas[i], root);
	}
}


template<class T>
Tree<T>* BinarySearchTree<T>::find(T data, Tree<T>* nodePtr)                      //T���������ֻ����ַ�,����������,�ҵ�ָ������ڵ�����ָ��
{
	if (nodePtr)
	{
		if (nodePtr->getData()> data)
		{
			if (nodePtr->getLeftTree())      //��������������ڵ㣬��ݹ��������
			{
			find(data, nodePtr->getLeftTree());
			}
			else
			{
				Tree<T> *t = new Tree<T>();
				t->setData(0);
				return t;                                           //���ص������������ʾδ�ҵ�
			}
		}
		else if (nodePtr->getData()< data)
		{
			if (nodePtr->getRightTree())
			{
			find(data, nodePtr->getRightTree());
			}
			else
			{
				Tree<T> *t = new Tree<T>();
				t->setData(0);
				return t;
			}
		}
		else if (nodePtr->getData()==data)
		{
			return nodePtr;                           //�ҵ��ˣ��򷵻ص�ǰ�ڵ������
		}
	}
}

template<class T>
Tree<T> * BinarySearchTree<T>::getRoot()
{
	return root;
	
}

template<class T>
void BinarySearchTree<T>::setRoot(Tree<T>* root)
{
	this->root = root;
}

template<class T>
void BinarySearchTree<T>::insertNode(T data, Tree<T>* nodePtr)
{

	if (data < nodePtr->getData())
	{
		if (nodePtr->getLeftTree())
		{
           insertNode(data, nodePtr->getLeftTree());
		}
		else
		{
			Tree<T> *node=new Tree<T>();
			node->setData(data);
			nodePtr->setLeftTree(node);
		}
	}
	else if (data>nodePtr->getData())
	{
		if (nodePtr->getRightTree())
		{
           insertNode(data, nodePtr->getRightTree());
		}
		else
		{
			Tree<T>*node=new Tree<T>();
			node->setData(data);
			nodePtr->setRightTree(node);
		}
	}
}

template<class T>
void BinarySearchTree<T>::visitSearchTree(Tree<T> * node)
{
	if (node)
	{
	
		visitSearchTree(node->getLeftTree());
		cout << node->getData()<<',';
		visitSearchTree(node->getRightTree());
	}
}

//**********************************�������������ֵ����*******************************
template<class T>                                                                                                 //ע�⣺��ʹ����ģ��ʱ��.cpp�ļ��еĺ����������template<class T>
Tree<T>* BinarySearchTree<T>::findMin(Tree<T> *root)                              //Tһ���õݹ飬һ����Ҫ�ݹ�ʵ��ree<T> * BinarySearchTree<T>::getRoot()
{                                                                                                                               //ע�⣺�ӿں�ʵ�ֱ�����ȫһ��
	if (root)                                                                                                               //�������㲻Ϊ�գ���ݹ������������Ľڵ�ֱ��Ҷ�ӽڵ�
	{
		if (root->getLeftTree())
		{
			findMin(root->getLeftTree());
		}
		else                                         //��ǰΪҶ�ӽڵ㣬��Ϊ����
		{
			return root;
		}
	}
}

template<class T>
Tree<T>* BinarySearchTree<T>::findMax(Tree<T> *root)                                       //�ǵݹ��㷨��ѭ������ջ��ʵ��
{
	
	while (true)
	{
		if (root->getRightTree())
		{
			root = root->getRightTree();
		}
		else
		{
			return root;                                                                                                          //����return ��break��������÷�
		//	break;                                                                                                                  //ע�⣺return ��ʵҲ�ǽ����˱���ѭ��
		}
	}
	
	/* 
	//---------------------��ջ������ݹ�------------------------------------
	vector<Tree<T>*> maxTree;
	while (root)
	{
		maxTree.push_back(root);
		root = root->getRightTree();
	}
	//����ʹ�õ�����ָʾβ��Ԫ��,�������������һ��ָ��
	iterator it=maxTree.end();
	return maxTree[it];
	*/
	
}
