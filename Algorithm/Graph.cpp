#include"Graph.h"
#include"EdgeWeight.cpp"
template<class T>
Graph<T>::Graph()                              //��ע���ڷ�����ʵ����һ��Ҫ�õ�ģ��T��������һ�ж���template<class T>
{
	node = new Vertex<T>();
}

template<class T>
Graph<T>::~Graph()
{

}

template<class T>
vector<vector<T>>Graph<T>::getMatrixVertex()
{
	return matrixVertex;
}

template<class T>
void Graph<T>::setMatrixVertex(vector<vector<T>>matrixVertex)
{
	this->matrixVertex = matrixVertex;
}

template<class T>
Vertex<T>* Graph<T>::getNode()
{
	return node;
}

template<class T>
void Graph<T>::setNode(Vertex<T>* node)
{
	this->node = node;
}

template<class T>
vector<T>Graph<T>::getVertices()
{
	return vertices;
}

template<class T>
void Graph<T>::setVertices(vector<T>vertices)
{
	this->vertices = vertices;
}

template<class T>
void Graph<T>::topSort(Graph<T> graph)                                        //��ͼ�����������򣬳�ʼ����Ϊ��ͷ������ͨͼ
{
	//���ͼ�и��ڵ����ȣ�
	queue<Vertex<T>*> nodeQueue;
	queue<Vertex<T>*>topQueue;                                                   //���źõ����зŵ�topQueue��
	Vertex<T> *linkNode;
	if (graph.getNode()->getIndegree() == 0)
	{
       	nodeQueue.push(graph.getNode());
	}
	while (nodeQueue.size())
	{
		linkNode = nodeQueue.front();
		topQueue.push(linkNode);
		nodeQueue.pop();
		for (int i = 0; i < linkNode->getNeighbors().size(); i++)
		{
			//���ڽӵ����ȼ�1
			linkNode->getNeighbors()[i]->setIndegree(linkNode->getNeighbors()[i]->getIndegree() - 1);
			if (linkNode->getNeighbors()[i]->getIndegree() == 0)
			{

				nodeQueue.push(linkNode->getNeighbors()[i]);
			}
		}
	}//while
	cout << "topSort: ";
	int topNumber = topQueue.size();
	for (int i = 0; i < topNumber; i++)
	{
		cout << topQueue.front()->getData() << "->";
		topQueue.pop();
	}
	cout << endl;
}

template<class T>
void Graph<T>::buildGraphNode()                                                     //����ͼ���ڽӱ�ڵ�node*�洢�ṹ
{
	T s;                                                                                                     //�洢�ýڵ��ֵ
	int weight;                                                                                          //·��Ȩֵ
	queue<Vertex<T>*> nodeQueue;
	vector<Vertex<T>*>checkNode;
	Vertex<T> *linkNode;
	int checkFlag = 0;
	cout << "please input the first node:" << endl;
	cin >> s;
	int flag = 1;
	if (s != "!")
	{
		node->setData(s);                                                                                                                       //ͼ�ĸ��ڵ�
		node->setIndegree(0);
		checkNode.push_back(node);
		nodeQueue.push(node);                                                                                                              //��ͷ���ѹ�������,�����д�ŵ��Ƕ����ָ��
	}
	while (nodeQueue.size())
	{
		linkNode = nodeQueue.front();
		nodeQueue.pop();
		vector<Vertex<T>*>neighbors;                                                                                                //��ǰ������ھӽ���ָ������      
		vector<EdgeWeight<T>*>neighborEdgeWeights;
		cout << "the relationship and weight connecting to " << linkNode->getData() << " : " << endl;
		flag = 1;
		while (flag)
		{
			cin >> s;
			if (s != "!")                                                                                                                               //��!����
			{
				cout << s << " weight = ";                                                                                                                      //���в����Ƿ�ǰ����ĵ�����ͼ�У����ڣ���ֱ�Ӹ�ֵָ�룬���򣬽����µĽڵ�
				cin >> weight;
				int temp;
				for (int j = 0; j< checkNode.size(); j++)
				{
					if (checkNode[j]->getData() == s)
					{
						checkFlag = 1;
						temp = j;
						break;
					}
				}

				Vertex<T>*adjNode = new Vertex<T>();
				if (checkFlag)
				{
					adjNode = checkNode[temp];
					neighbors.push_back(checkNode[temp]);
				}
				else
				{
				   adjNode->setData(s);
				   adjNode->setIndegree(0);
				   neighbors.push_back(adjNode);                                                                                        //�洢���ڶ���
				}
				EdgeWeight<T>*edgeWeight = new EdgeWeight<T>(linkNode, adjNode, weight);   //�洢���ڵı�Ȩֵ
				neighborEdgeWeights.push_back(edgeWeight);
				checkFlag = 0;
			}
			else
			{
				flag = 0;
			}
		}//while(adjNode)
		checkFlag = 0;
		linkNode->setNeighbors(neighbors);
		linkNode->setNeighborEdgeWeights(neighborEdgeWeights);
		for (int i = 0; i < neighbors.size(); i++)
		{
			for (int j = 0; j< checkNode.size(); j++)
			{
				if (checkNode[j]->getData() == linkNode->getNeighbors()[i]->getData())
				{
					checkFlag = 1;
					break;
				}
			}
			if (!checkFlag)
			{
				checkNode.push_back(linkNode->getNeighbors()[i]);
				nodeQueue.push(linkNode->getNeighbors()[i]);
			}
			checkFlag = 0;
		}
		neighbors.clear();                                                                                                                                        //�ֲ������Զ���ʧ������Ҳ���Բ������
		neighborEdgeWeights.clear();
	}//����node�洢�ṹ��ͼ
}

template<class T>
void Graph<T>::buildGraphMatrixVertex(int row, int col)                                         //����ͼ���ڽӾ����ά�����洢�ṹ
{
	int N = row*col;
	matrixVertex.resize(row);
	for (int i = 0; i < matrixVertex.size(); i++)
	{
		matrixVertex[i].resize(col);
	}
	vector<T>vertices;                                             //�洢���������ֵ���������κ����͵����ݣ�����ϵ������int��ʾ
	vertices.resize(N);
	cout << "please input data:" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> vertices[i];
	}
	cout << endl;
	cout << "please input relationship between data" << endl;
	for (int i = 0; i < N; i++)
	{
		cout << "please input the relationship to " << vertices[i] << endl;
		for (int j = 0; j < N; j++)
		{
			cin >> matrixVertex[i][j];
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (matrixVertex[i][j])
			{
				cout << vertices[i] << "��>" << vertices[j] << "       ";
			}
		}
		cout << endl;
	}
}

template<class T>
void Graph<T>::BFSGraph(Graph<T> graph)                                     //������ȱ���ͼ
{
	//ͨ����������ͼ�нڵ�����
	queue<Vertex<T>*> nodeQueue;
	vector<Vertex<T>*>checkNode;
	Vertex<T> *linkNode;
	int checkFlag = 0;
	checkNode.push_back(graph.getNode());
	nodeQueue.push(graph.getNode());
	while (nodeQueue.size())
	{
		linkNode = nodeQueue.front();
		linkNode->setDist(INFINITY);                                                                    //INFINITY��ʾ���޴�
	 	linkNode->setKnow(false);
		linkNode->setPath(nullptr);
		nodeQueue.pop();
		cout << linkNode->getData() << "���ڽӵ��У�";
		for (int i = 0; i < linkNode->getNeighbors().size(); i++)
		{
			cout<< linkNode->getNeighbors()[i]->getData() << ", "<<endl;
			cout << linkNode->getData() << "->" << linkNode->getNeighbors()[i]->getData() << "weight=" << linkNode->getNeighborEdgeWeights()[i]->getWeight()<<"   ";
			linkNode->getNeighbors()[i]->setIndegree(linkNode->getNeighbors()[i]->getIndegree()+1);
			for (int j = 0; j< checkNode.size(); j++)
			{
				if (checkNode[j]->getData() == linkNode->getNeighbors()[i]->getData())
				{
					checkFlag = 1;
					break;
				}
			}
			if (!checkFlag)
			{
				checkNode.push_back(linkNode->getNeighbors()[i]);
				nodeQueue.push(linkNode->getNeighbors()[i]);
			}
			checkFlag = 0;
		}
		cout << endl;
	}
}

template<class T>
Vertex<T>* Graph<T>::findVertexNode(Graph<T>graph, T s)                                                //����ָ��ڵ��ָ��
{
	//ͨ����������ͼ�нڵ�����
	queue<Vertex<T>*> nodeQueue;
	vector<Vertex<T>*>checkNode;
	Vertex<T> *linkNode;
	int checkFlag = 0;
	checkNode.push_back(graph.getNode());
	nodeQueue.push(graph.getNode());
	while (nodeQueue.size())
	{
		linkNode = nodeQueue.front();
		nodeQueue.pop();
		if (linkNode->getData() == s)
		{
			return linkNode;
		}
		else
		{
			for (int i = 0; i < linkNode->getNeighbors().size(); i++)
			{
				for (int j = 0; j < checkNode.size(); j++)
				{
					if (checkNode[j]->getData() == linkNode->getNeighbors()[i]->getData())
					{
						checkFlag = 1;
						break;
					}
				}
				if (!checkFlag)
				{
					checkNode.push_back(linkNode->getNeighbors()[i]);
					nodeQueue.push(linkNode->getNeighbors()[i]);
				}
				checkFlag = 0;
			}//for
		}//else
	}//else
	return NULL;                                          //û�ҵ�ʱ�����ؿ�ָ��
}

template<class T>
vector<Vertex<T>*> Graph<T>::unweightedShortestPath(Graph<T>graph, T s, T p)
{
	//��Ϊÿһ�ε�s�ǲ�ͬ�ģ�����ÿһ�α���ʱ��ͼ�еĶ���ľ���Ӧ��������Ϊ0
	//ͨ��������������������ÿ���ڵ�ľ���Ϊ0; knowΪfalse; ���¼����������
	Vertex<T> *v;
	v=findVertexNode(graph,s);
	if (v)                                                                          //����V�ĵ�Դ���·���㷨
	{
        queue<Vertex<T>*> nodeQueue;
	    vector<Vertex<T>*>checkNode;
	    Vertex<T> *linkNode;
		int checkFlag = 0;
	    BFSGraph(graph);
		v->setDist(0);
		v->setKnow(true);                                                                                               //�ѱ�����
		v->setPath(nullptr);
		nodeQueue.push(v);
		checkNode.push_back(v);
		while (nodeQueue.size())
		{
			linkNode = nodeQueue.front();
			nodeQueue.pop();
			for (int i = 0; i < (int)linkNode->getNeighbors().size(); i++)
			{
				if (linkNode->getNeighbors()[i]->getKnow())                                                                           //true
				{
					if (linkNode->getNeighbors()[i]->getDist() > linkNode->getDist() + 1)                           //������Խ���Ȩֵ�Ƚ�
					{
						linkNode->getNeighbors()[i]->setDist(linkNode->getDist() + 1);
						linkNode->getNeighbors()[i]->setPath(linkNode);
					}
				}
				else
				{
					linkNode->getNeighbors()[i]->setDist(linkNode->getDist() + 1);
					linkNode->getNeighbors()[i]->setPath(linkNode);
					linkNode->getNeighbors()[i]->setKnow(true);
				}
		 //���
				for (int j = 0; j < checkNode.size(); j++)
				{
					if (checkNode[j]->getData() == linkNode->getNeighbors()[i]->getData())
					{
						checkFlag = 1;
						break;
					}
				}
				if (!checkFlag)
				{
					checkNode.push_back(linkNode->getNeighbors()[i]);
					nodeQueue.push(linkNode->getNeighbors()[i]);
				}
				checkFlag = 0;
			}//for
		}//while
	}
	else
	{
		cout << s << "is not existed" << endl;
	}
	vector<Vertex<T>*>sssp;
	sssp = twoPointShortestPath(graph, p);
	return sssp;
}

template<class T>
vector<Vertex<T>*> Graph<T>::twoPointShortestPath(Graph<T>graph, T p)
{
	stack<Vertex<T>*> svp;
	vector<Vertex<T>*>sssp;
	Vertex<T>* V = findVertexNode(graph,p);
	svp.push(V);
	while (V->getPath()!=nullptr)
	{
		svp.push(V->getPath());
		V = V->getPath();
	}
	while (svp.size())
	{
		sssp.push_back(svp.top());

		svp.pop();
	}
	return sssp;
}

template<class T>
vector<Vertex<T>*>Graph<T>::weightedShortestPathDijkstra(Graph<T>graph, T s, T p)
{
	Vertex<T> *v;
	v = findVertexNode(graph, s);                                                                                        //Դ�ڵ�
	if (v)                                                                                                               //����V�ĵ�Դ���·���㷨
	{
		queue<Vertex<T>*> nodeQueue;
		vector<Vertex<T>*>checkNode;
		Vertex<T> *linkNode;
		int checkFlag = 0;
		BFSGraph(graph);
		v->setDist(0);                                                                                                              //ÿ�������Լ����Լ��ľ���Ϊ0
		v->setKnow(true);                                                                                                       //�ѱ�����       
		nodeQueue.push(v);
		checkNode.push_back(v);
		while (nodeQueue.size())
		{
			linkNode = nodeQueue.front();
			nodeQueue.pop();
			for (int i = 0; i < linkNode->getNeighbors().size(); i++)
			{
				if (linkNode->getNeighbors()[i]->getKnow())                                                                           //true
				{
					if (linkNode->getNeighbors()[i]->getDist() > linkNode->getDist() + linkNode->getNeighborEdgeWeights()[i]->getWeight())                           //������Խ���Ȩֵ�Ƚ�
					{
						linkNode->getNeighbors()[i]->setDist(linkNode->getDist() + linkNode->getNeighborEdgeWeights()[i]->getWeight());
						linkNode->getNeighbors()[i]->setPath(linkNode);                                      //�������·���ϵĸ��ڵ�
					}
				}
				else
				{
					linkNode->getNeighbors()[i]->setDist(linkNode->getDist() + linkNode->getNeighborEdgeWeights()[i]->getWeight());
					linkNode->getNeighbors()[i]->setPath(linkNode);
					linkNode->getNeighbors()[i]->setKnow(true);
				}
				//���
				for (int j = 0; j < checkNode.size(); j++)
				{
					if (checkNode[j]->getData() == linkNode->getNeighbors()[i]->getData())
					{
						checkFlag = 1;
						break;
					}
				}
				if (!checkFlag)
				{
					checkNode.push_back(linkNode->getNeighbors()[i]);
					nodeQueue.push(linkNode->getNeighbors()[i]);
				}
				checkFlag = 0;
			}//for
		}//while
	}
	else
	{
		cout << s << "is not existed" << endl;
	}
	vector<Vertex<T>*>sssp;
	sssp = twoPointShortestPath(graph, p);
	return sssp;
}

template<class T>
vector<Vertex<T>*>criticalPathUnCycle(Graph<T>graph)
{
	//1.·������
	//2.ͼ��ת��
	Vertex<T> *v;
	v = graph.getNode();                                                //�õ���ʼ�ڵ�
	if (v)                                                                          //����V�ĵ�Դ���·���㷨
	{
		v->setEC(0);                                                             //���ó�ʼ��������翪ʼʱ��Ϊ0�������ж��������ʼʱ��Ϊ�ӽڵ��м�ȥ·�����е���Сֵ
		queue<Vertex<T>*> nodeQueue;
		vector<Vertex<T>*>checkNode;
		Vertex<T> *linkNode;
		int checkFlag = 0;
		BFSGraph(graph);
		v->setDist(0);                                                          //���㲢��¼·������Ϊ0�Ľڵ�
		v->setKnow(true);                                                                                               //�ѱ�����
		v->setPath(nullptr);
		nodeQueue.push(v);
		checkNode.push_back(v);
		while (nodeQueue.size())
		{
			linkNode = nodeQueue.front();
			nodeQueue.pop();
			for (int i = 0; i < (int)linkNode->getNeighbors().size(); i++)
			{
				if (linkNode->getNeighbors()[i]->getKnow())                                                                           //�ýڵ��Ѿ������ʹ��������Ѿ��������ڵ���ӽڵ㣩true
				{
					if (linkNode->getNeighbors()[i]->getEC() < linkNode->getEC() + linkNode->getNeighborEdgeWeights()[i]->getWeight())
					{
						linkNode->getNeighbors()[i]->setEC(linkNode->getEC() + linkNode->getNeighborEdgeWeights()[i]->getWeight());     //�������ʱ��
					}
				}
				else
				{
					linkNode->getNeighbors()[i]->setEC(linkNode->getEC() + linkNode->getNeighborEdgeWeights()[i]->getWeight());
					linkNode->getNeighbors()[i]->setKnow(true);
				}
				//���
				for (int j = 0; j < checkNode.size(); j++)
				{
					if (checkNode[j]->getData() == linkNode->getNeighbors()[i]->getData())
					{
						checkFlag = 1;
						break;
					}
				}
				if (!checkFlag)
				{
					checkNode.push_back(linkNode->getNeighbors()[i]);
					nodeQueue.push(linkNode->getNeighbors()[i]);
				}
				checkFlag = 0;
			}//for
		}//while
	}
	else
	{
		cout << s << "is not existed" << endl;
	}

	//�������ÿ���ڵ���������ʱ�䣬
	//next:�������ʱ�䣿����������������������
}