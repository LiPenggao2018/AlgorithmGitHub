/**
AVL binary search tree
��1��ԭ��ÿ���ڵ�����������������ĸ߶�����1�Ķ����������
�߶��Ǵ������ϣ���ײ��Ҷ�ӽڵ�߶�Ϊ0���൱�ڵذ壩
��2�����¶���ģ���ࣺģ��������ģ��ʵ�������һ������
*/
#pragma once
#include"Tree.h"
#include<math.h>

template<class T>
class AVLTree                                                                                //�������������ĸ߶Ȳ��������Ƿ���Ҫ������ת�����߶Ȳ��1���������е���ת������ڵ㣩����˫��ת�����ҽڵ㣩
{
public:
	AVLTree<T>();
	~AVLTree<T>();
	void insertAVLnode(T data, Tree<T>*node);                       //��ͨ���������������AVL��
	int differenceHeight(Tree<T>*node);                                  //����ڵ�Node�����������ĸ߶Ȳ�
	void adjustAVL(Tree<T>*node);                                            //ע�⣺���ﴫ�ݵĶ���ָ��ڵ��ָ�룬�����ǽڵ������߱���
	void rightLeftAdjustAVL(Tree<T>*node);                           //����˫����
	void leftRightAdjustAVL(Tree<T>*node);                           //����˫����
	void visitAVLSearchTree(Tree<T> * node);
	int nodeHeight(Tree<T>*node);                                           //�������õ�ǰ�ڵ��������нڵ�ĸ߶�                       
	Tree<T> *getRoot();
	void setRoot(Tree<T> *rootNode);
	int max(int a, int b);                                         //�����
private:
	Tree<T> *root;                                                                        //AVL��Ҳ�Ƕ�����������������Ҫ����һ�������
};

