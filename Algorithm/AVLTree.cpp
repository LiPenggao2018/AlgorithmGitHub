
#include"AVLTree.h"

template <class T>
AVLTree<T>::AVLTree()
{

}

template <class T>
AVLTree<T>::~AVLTree()
{
	
}

template <class T>
void  AVLTree<T>::insertAVLnode(T data, Tree<T>*rootNode)                      //可通过插入操作来构造AVL树
{
	Tree<T> *node = new Tree<T>();                                                                    //在运行模板时，必须每次都重新生成解决方案
	node->setData(data);
	while (rootNode)
	{
		if (rootNode->getData() > data)
		{
		   if (rootNode->getLeftTree())
			{
				rootNode = rootNode->getLeftTree();
			}
			else
			{
				   node->setFatherTree(rootNode);                                                             //设置每个节点指向父节点指针
				   rootNode->setLeftTree(node);
				   rootNode = node->getLeftTree();                                                            //你的循环没有结束！
			}
		}
		else if (rootNode->getData() < data)
		{
			if (rootNode->getRightTree())
			{
				rootNode = rootNode->getRightTree();
			}
			else
			{
				node->setFatherTree(rootNode);
				rootNode->setRightTree(node);
				rootNode = node->getRightTree();
			}
		}
		else
		{
			break;                                                //如果已经存在相同的数据，则不用再插入，直接break;
		}
	}//插入并构建节点，但是没有调整平衡
	//--------------------------------------------------------------------------------------------------------
	//求所有节点的高度，注意叶子节点的高度为0，根节点的深度为0而高度最高。
	nodeHeight(root);
	//--------------------------------------------------------------------------------------------------------

	//检查插入的节点的沿路的父节点的平衡是否被破坏
	
	Tree<T> * parent ;                                         //定义一个指向父节点的指针变量
	parent = node->getFatherTree();
	int AVLdiffenence = 0;                                 //根本没调整，由于没有得到父节点
	while (parent)
	{
		AVLdiffenence = differenceHeight(parent->getFatherTree());                                //参数为指向节点的指针
		if (abs(AVLdiffenence) > 1)                                                               //如果当前节点左右子树的高度差大于1，则对该节点进行旋转
		{
			if (parent->getData() > parent->getFatherTree()->getData() && node->getData()<parent->getData())                              //执行右左双旋转
			{
				rightLeftAdjustAVL(parent);
				//右左双旋转
				cout << "右左旋转" << endl;// << parent->getData();
			//	cout << parent->getLeftTree()->getData() << endl;
			}
			else if (parent->getData() < parent->getFatherTree()->getData() && node->getData()>parent->getData())                      //执行左右双旋转
			{
				//左右双旋转
				leftRightAdjustAVL(parent);
			}
			else
			{
              	adjustAVL(parent);                                                                        //否则进行单旋转
			}
			break;
		}
		else
		{
			parent = parent->getFatherTree();
		}
	}
	//if (root->getRightTree())
	//cout <<"根右"<< root->getRightTree()->getData()<<endl;
	//visitAVLSearchTree(root);
	nodeHeight(root);
}

template <class T>
int AVLTree<T>::differenceHeight(Tree<T>*node)                               //计算节点Node的左右子树的高度差
{
	if (node)
	{
		if (node->getLeftTree() && node->getRightTree())
		{
          return node->getLeftTree()->getHeight() - node->getRightTree()->getHeight();
		} 
		else if (node->getLeftTree())
		{
			return node->getLeftTree()->getHeight() - (-1);
		}
		else if (node->getRightTree())
		{
			return node->getRightTree()->getHeight() - (-1);
		}
	}
	else
	{
		return 1;
	}
}

template <class T>
void AVLTree<T>::adjustAVL(Tree<T>*node)                                //这里假设子节点的父节点的平衡被破坏
{
	if (node->getData()>node->getFatherTree()->getData())           //右子树被插入，右右平衡被破坏
	{
		if (node->getFatherTree()->getFatherTree())                 //非根节点的平衡被破坏
		{
			if (node->getFatherTree()->getData() < node->getFatherTree()->getFatherTree()->getData())
			{
				node->getFatherTree()->getFatherTree()->setLeftTree(node);
			}
			else
			{
                 node->getFatherTree()->getFatherTree()->setRightTree(node);
			}
			
			if (node->getLeftTree())
			{
				node->getLeftTree()->setFatherTree(node->getFatherTree());
				node->getFatherTree()->setRightTree(node->getLeftTree());
				node->setLeftTree(node->getFatherTree());
				node->setFatherTree(node->getFatherTree()->getFatherTree());
			}
			else
			{
				node->setLeftTree(node->getFatherTree());
				node->setFatherTree(node->getFatherTree()->getFatherTree());
				node->getLeftTree()->setFatherTree(node);
				node->getLeftTree()->setRightTree(nullptr);
			}
			//因为左节点为0，所以无需再次赋值
		}
		else                                                                                                                              //如果需要调整的节点为根节点时
		{
			if (node->getLeftTree())
			{
				node->getFatherTree()->setRightTree(node->getLeftTree());
				node->getLeftTree()->setFatherTree(node->getFatherTree());
			}
			else
			{
				node->getFatherTree()->setRightTree(nullptr);
			}
			node->setLeftTree(node->getFatherTree());
			node->getFatherTree()->setFatherTree(node);
			node->setFatherTree(nullptr);
			this->root = node;
		}
	}
	else if (node->getData() < node->getFatherTree()->getData())     //左左平衡被破坏
	{
		if (node->getFatherTree()->getFatherTree())                                //非根节点的平衡被破坏
		{
			if (node->getFatherTree()->getData()>node->getFatherTree()->getFatherTree()->getData())
			{
				node->getFatherTree()->getFatherTree()->setRightTree(node);
			}
			else
			{
            	node->getFatherTree()->getFatherTree()->setLeftTree(node);      
			}
		                                                                                 	//当发生平衡问题的节点不为空时，如何调整？
			if (node->getRightTree())                                                                     //若存在右节点
			{
				node->getFatherTree()->setLeftTree(node->getRightTree());
				node->getRightTree ()->setFatherTree(node->getFatherTree());
			}
			else
			{
				node->getFatherTree()->setLeftTree(nullptr);
			}
			node->setRightTree(node->getFatherTree());
			node->setFatherTree(node->getFatherTree()->getFatherTree());
			node->getRightTree()->setFatherTree(node);
		}
		else                                                                                        //若失衡的为根节点
		{
			if (node->getRightTree())
			{
				node->getFatherTree()->setLeftTree(node->getRightTree());
				node->getRightTree()->setFatherTree(node->getFatherTree());
			}
			else
			{
				node->getFatherTree()->setLeftTree(nullptr);
			}
			node->setRightTree(node->getFatherTree());
			node->getFatherTree()->setFatherTree(node);
			node->setFatherTree(nullptr);
			this->root = node;
		}
	}
}

//*********************************双旋转**********************************
template <class T>
void AVLTree<T>::rightLeftAdjustAVL(Tree<T>*node)                           //右左双调整
{
	   //node相当于中间的parent节点
	   //右
	     adjustAVL(node->getLeftTree());

		//左
		 adjustAVL(node->getFatherTree());
}

template <class T>
void AVLTree<T>::leftRightAdjustAVL(Tree<T>*node)                          //左右双调整
{
	    //左
	adjustAVL(node->getRightTree());

	    //右
	adjustAVL(node->getFatherTree());

}

template <class T>
Tree<T> *AVLTree<T>::getRoot()
{
	return root;
}

template <class T>
void AVLTree<T>::setRoot(Tree<T> *rootNode)
{
	this->root = rootNode;
}

template <class T>
void AVLTree<T>::visitAVLSearchTree(Tree<T> * node)
{
	if (node)                                         //中根序遍历
	{
	
		cout << node->getData() << ',';
		cout << node->getHeight() << endl;
		visitAVLSearchTree(node->getLeftTree());
		visitAVLSearchTree(node->getRightTree());
	}
}

template <class T>
int AVLTree<T>::nodeHeight(Tree<T>*node)                                //重先设置当前节点树的所有节点的高度      
{
	if (node)
	{
		int h = 0;
		h = max(nodeHeight(node->getLeftTree()), nodeHeight(node->getRightTree())) + 1;
		node->setHeight(h);
		return h;
	}
	return -1;                                    //如果为空则返回-1
}

template <class T>
int AVLTree<T>::max(int a, int b)
{
	return a > b ? a : b;
}