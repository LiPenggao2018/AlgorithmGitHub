/**
AVL binary search tree
（1）原则：每个节点的左子树和右子树的高度最多差1的二叉查找树，
高度是从下向上，最底层的叶子节点高度为0（相当于地板）
（2）以下定义模板类：模板类是类模板实例化后的一个产物
*/
#pragma once
#include"Tree.h"
#include<math.h>

template<class T>
class AVLTree                                                                                //根据左右子树的高度差来决定是否需要进行旋转，若高度差超过1，则必须进行单旋转（左左节点）或者双旋转（左右节点）
{
public:
	AVLTree<T>();
	~AVLTree<T>();
	void insertAVLnode(T data, Tree<T>*node);                       //可通过插入操作来构造AVL树
	int differenceHeight(Tree<T>*node);                                  //计算节点Node的左右子树的高度差
	void adjustAVL(Tree<T>*node);                                            //注意：这里传递的都是指向节点的指针，并不是节点对象或者变量
	void rightLeftAdjustAVL(Tree<T>*node);                           //右左双调整
	void leftRightAdjustAVL(Tree<T>*node);                           //左右双调整
	void visitAVLSearchTree(Tree<T> * node);
	int nodeHeight(Tree<T>*node);                                           //重先设置当前节点树的所有节点的高度                       
	Tree<T> *getRoot();
	void setRoot(Tree<T> *rootNode);
	int max(int a, int b);                                         //求最大
private:
	Tree<T> *root;                                                                        //AVL树也是二叉搜索树，所有需要定义一个根结点
};

