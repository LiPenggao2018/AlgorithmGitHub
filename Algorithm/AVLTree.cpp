
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
void  AVLTree<T>::insertAVLnode(T data, Tree<T>*rootNode)                      //��ͨ���������������AVL��
{
	Tree<T> *node = new Tree<T>();                                                                    //������ģ��ʱ������ÿ�ζ��������ɽ������
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
				   node->setFatherTree(rootNode);                                                             //����ÿ���ڵ�ָ�򸸽ڵ�ָ��
				   rootNode->setLeftTree(node);
				   rootNode = node->getLeftTree();                                                            //���ѭ��û�н�����
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
			break;                                                //����Ѿ�������ͬ�����ݣ������ٲ��룬ֱ��break;
		}
	}//���벢�����ڵ㣬����û�е���ƽ��
	//--------------------------------------------------------------------------------------------------------
	//�����нڵ�ĸ߶ȣ�ע��Ҷ�ӽڵ�ĸ߶�Ϊ0�����ڵ�����Ϊ0���߶���ߡ�
	nodeHeight(root);
	//--------------------------------------------------------------------------------------------------------

	//������Ľڵ����·�ĸ��ڵ��ƽ���Ƿ��ƻ�
	
	Tree<T> * parent ;                                         //����һ��ָ�򸸽ڵ��ָ�����
	parent = node->getFatherTree();
	int AVLdiffenence = 0;                                 //����û����������û�еõ����ڵ�
	while (parent)
	{
		AVLdiffenence = differenceHeight(parent->getFatherTree());                                //����Ϊָ��ڵ��ָ��
		if (abs(AVLdiffenence) > 1)                                                               //�����ǰ�ڵ����������ĸ߶Ȳ����1����Ըýڵ������ת
		{
			if (parent->getData() > parent->getFatherTree()->getData() && node->getData()<parent->getData())                              //ִ������˫��ת
			{
				rightLeftAdjustAVL(parent);
				//����˫��ת
				cout << "������ת" << endl;// << parent->getData();
			//	cout << parent->getLeftTree()->getData() << endl;
			}
			else if (parent->getData() < parent->getFatherTree()->getData() && node->getData()>parent->getData())                      //ִ������˫��ת
			{
				//����˫��ת
				leftRightAdjustAVL(parent);
			}
			else
			{
              	adjustAVL(parent);                                                                        //������е���ת
			}
			break;
		}
		else
		{
			parent = parent->getFatherTree();
		}
	}
	//if (root->getRightTree())
	//cout <<"����"<< root->getRightTree()->getData()<<endl;
	//visitAVLSearchTree(root);
	nodeHeight(root);
}

template <class T>
int AVLTree<T>::differenceHeight(Tree<T>*node)                               //����ڵ�Node�����������ĸ߶Ȳ�
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
void AVLTree<T>::adjustAVL(Tree<T>*node)                                //��������ӽڵ�ĸ��ڵ��ƽ�ⱻ�ƻ�
{
	if (node->getData()>node->getFatherTree()->getData())           //�����������룬����ƽ�ⱻ�ƻ�
	{
		if (node->getFatherTree()->getFatherTree())                 //�Ǹ��ڵ��ƽ�ⱻ�ƻ�
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
			//��Ϊ��ڵ�Ϊ0�����������ٴθ�ֵ
		}
		else                                                                                                                              //�����Ҫ�����Ľڵ�Ϊ���ڵ�ʱ
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
	else if (node->getData() < node->getFatherTree()->getData())     //����ƽ�ⱻ�ƻ�
	{
		if (node->getFatherTree()->getFatherTree())                                //�Ǹ��ڵ��ƽ�ⱻ�ƻ�
		{
			if (node->getFatherTree()->getData()>node->getFatherTree()->getFatherTree()->getData())
			{
				node->getFatherTree()->getFatherTree()->setRightTree(node);
			}
			else
			{
            	node->getFatherTree()->getFatherTree()->setLeftTree(node);      
			}
		                                                                                 	//������ƽ������Ľڵ㲻Ϊ��ʱ����ε�����
			if (node->getRightTree())                                                                     //�������ҽڵ�
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
		else                                                                                        //��ʧ���Ϊ���ڵ�
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

//*********************************˫��ת**********************************
template <class T>
void AVLTree<T>::rightLeftAdjustAVL(Tree<T>*node)                           //����˫����
{
	   //node�൱���м��parent�ڵ�
	   //��
	     adjustAVL(node->getLeftTree());

		//��
		 adjustAVL(node->getFatherTree());
}

template <class T>
void AVLTree<T>::leftRightAdjustAVL(Tree<T>*node)                          //����˫����
{
	    //��
	adjustAVL(node->getRightTree());

	    //��
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
	if (node)                                         //�и������
	{
	
		cout << node->getData() << ',';
		cout << node->getHeight() << endl;
		visitAVLSearchTree(node->getLeftTree());
		visitAVLSearchTree(node->getRightTree());
	}
}

template <class T>
int AVLTree<T>::nodeHeight(Tree<T>*node)                                //�������õ�ǰ�ڵ��������нڵ�ĸ߶�      
{
	if (node)
	{
		int h = 0;
		h = max(nodeHeight(node->getLeftTree()), nodeHeight(node->getRightTree())) + 1;
		node->setHeight(h);
		return h;
	}
	return -1;                                    //���Ϊ���򷵻�-1
}

template <class T>
int AVLTree<T>::max(int a, int b)
{
	return a > b ? a : b;
}