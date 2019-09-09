/**
在本项目中，所有的类和函数都定义为开源的模板类，以方便之后的扩展，以及使用STL库函数
*/
#include"BinarySearchTree.h"

template<class T>                                                                 //模板类
BinarySearchTree<T>::BinarySearchTree()                       //函数体外定义，则类名<类型>
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
	node->setData(datas[0]);                     //将第一个数据作为根节点
	setRoot(node);
	for (int i = 1; i < (int)datas.size(); i++)
	{                                       //以第一个数据作为根，比它大的插在左边，比它小的插在右边
		insertNode(datas[i], root);
	}
}


template<class T>
Tree<T>* BinarySearchTree<T>::find(T data, Tree<T>* nodePtr)                      //T可以是数字或者字符,二叉搜索树,找到指向这个节点树的指针
{
	if (nodePtr)
	{
		if (nodePtr->getData()> data)
		{
			if (nodePtr->getLeftTree())      //如果存在左子树节点，则递归进行搜索
			{
			find(data, nodePtr->getLeftTree());
			}
			else
			{
				Tree<T> *t = new Tree<T>();
				t->setData(0);
				return t;                                           //返回的这个操作，表示未找到
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
			return nodePtr;                           //找到了，则返回当前节点的数据
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

//**********************************二叉查找树的最值查找*******************************
template<class T>                                                                                                 //注意：在使用类模板时，.cpp文件中的函数必须加上template<class T>
Tree<T>* BinarySearchTree<T>::findMin(Tree<T> *root)                              //T一个用递归，一个不要递归实现ree<T> * BinarySearchTree<T>::getRoot()
{                                                                                                                               //注意：接口和实现必须完全一致
	if (root)                                                                                                               //如果根结点不为空，则递归搜索左子树的节点直至叶子节点
	{
		if (root->getLeftTree())
		{
			findMin(root->getLeftTree());
		}
		else                                         //当前为叶子节点，即为所求
		{
			return root;
		}
	}
}

template<class T>
Tree<T>* BinarySearchTree<T>::findMax(Tree<T> *root)                                       //非递归算法：循环或者栈来实现
{
	
	while (true)
	{
		if (root->getRightTree())
		{
			root = root->getRightTree();
		}
		else
		{
			return root;                                                                                                          //返回return 和break的区别和用法
		//	break;                                                                                                                  //注意：return 其实也是结束了本次循环
		}
	}
	
	/* 
	//---------------------用栈来代替递归------------------------------------
	vector<Tree<T>*> maxTree;
	while (root)
	{
		maxTree.push_back(root);
		root = root->getRightTree();
	}
	//可以使用迭代器指示尾巴元素,迭代器本身就是一个指针
	iterator it=maxTree.end();
	return maxTree[it];
	*/
	
}
