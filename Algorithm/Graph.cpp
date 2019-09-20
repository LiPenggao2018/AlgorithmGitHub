#include"Graph.h"
#include"EdgeWeight.cpp"
template<class T>
Graph<T>::Graph()                              //特注：在方法的实现中一定要用到模板T，并在上一行定义template<class T>
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
void Graph<T>::topSort(Graph<T> graph)                                        //对图进行拓扑排序，初始条件为带头结点的连通图
{
	//输出图中各节点的入度：
	queue<Vertex<T>*> nodeQueue;
	queue<Vertex<T>*>topQueue;                                                   //将排好的序列放到topQueue中
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
			//对邻接点的入度减1
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
void Graph<T>::buildGraphNode()                                                     //构建图的邻接表节点node*存储结构
{
	T s;                                                                                                     //存储该节点的值
	int weight;                                                                                          //路径权值
	queue<Vertex<T>*> nodeQueue;
	vector<Vertex<T>*>checkNode;
	Vertex<T> *linkNode;
	int checkFlag = 0;
	cout << "please input the first node:" << endl;
	cin >> s;
	int flag = 1;
	if (s != "!")
	{
		node->setData(s);                                                                                                                       //图的根节点
		node->setIndegree(0);
		checkNode.push_back(node);
		nodeQueue.push(node);                                                                                                              //将头结点压入队列中,队列中存放的是顶点的指针
	}
	while (nodeQueue.size())
	{
		linkNode = nodeQueue.front();
		nodeQueue.pop();
		vector<Vertex<T>*>neighbors;                                                                                                //当前顶点的邻居结点的指针数组      
		vector<EdgeWeight<T>*>neighborEdgeWeights;
		cout << "the relationship and weight connecting to " << linkNode->getData() << " : " << endl;
		flag = 1;
		while (flag)
		{
			cin >> s;
			if (s != "!")                                                                                                                               //以!结束
			{
				cout << s << " weight = ";                                                                                                                      //进行查找是否当前输入的点已在图中，若在，则直接赋值指针，否则，建立新的节点
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
				   neighbors.push_back(adjNode);                                                                                        //存储相邻顶点
				}
				EdgeWeight<T>*edgeWeight = new EdgeWeight<T>(linkNode, adjNode, weight);   //存储相邻的边权值
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
		neighbors.clear();                                                                                                                                        //局部变量自动消失，这里也可以不用清除
		neighborEdgeWeights.clear();
	}//创建node存储结构的图
}

template<class T>
void Graph<T>::buildGraphMatrixVertex(int row, int col)                                         //构建图的邻接矩阵二维向量存储结构
{
	int N = row*col;
	matrixVertex.resize(row);
	for (int i = 0; i < matrixVertex.size(); i++)
	{
		matrixVertex[i].resize(col);
	}
	vector<T>vertices;                                             //存储顶点的数据值，可以是任何类型的数据，而关系我们用int表示
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
				cout << vertices[i] << "—>" << vertices[j] << "       ";
			}
		}
		cout << endl;
	}
}

template<class T>
void Graph<T>::BFSGraph(Graph<T> graph)                                     //广度优先遍历图
{
	//通过遍历来求图中节点的入度
	queue<Vertex<T>*> nodeQueue;
	vector<Vertex<T>*>checkNode;
	Vertex<T> *linkNode;
	int checkFlag = 0;
	checkNode.push_back(graph.getNode());
	nodeQueue.push(graph.getNode());
	while (nodeQueue.size())
	{
		linkNode = nodeQueue.front();
		linkNode->setDist(INFINITY);                                                                    //INFINITY表示无限大
	 	linkNode->setKnow(false);
		linkNode->setPath(nullptr);
		nodeQueue.pop();
		cout << linkNode->getData() << "的邻接点有：";
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
Vertex<T>* Graph<T>::findVertexNode(Graph<T>graph, T s)                                                //返回指向节点的指针
{
	//通过遍历来求图中节点的入度
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
	return NULL;                                          //没找到时，返回空指针
}

template<class T>
vector<Vertex<T>*> Graph<T>::unweightedShortestPath(Graph<T>graph, T s, T p)
{
	//因为每一次的s是不同的，所以每一次遍历时，图中的顶点的距离应重新设置为0
	//通过遍历，可以重新设置每个节点的距离为0; know为false; 重新计算各点的入度
	Vertex<T> *v;
	v=findVertexNode(graph,s);
	if (v)                                                                          //查找V的单源最短路径算法
	{
        queue<Vertex<T>*> nodeQueue;
	    vector<Vertex<T>*>checkNode;
	    Vertex<T> *linkNode;
		int checkFlag = 0;
	    BFSGraph(graph);
		v->setDist(0);
		v->setKnow(true);                                                                                               //已被遍历
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
					if (linkNode->getNeighbors()[i]->getDist() > linkNode->getDist() + 1)                           //这里可以进行权值比较
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
		 //检查
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
	v = findVertexNode(graph, s);                                                                                        //源节点
	if (v)                                                                                                               //查找V的单源最短路径算法
	{
		queue<Vertex<T>*> nodeQueue;
		vector<Vertex<T>*>checkNode;
		Vertex<T> *linkNode;
		int checkFlag = 0;
		BFSGraph(graph);
		v->setDist(0);                                                                                                              //每个顶点自己到自己的距离为0
		v->setKnow(true);                                                                                                       //已被遍历       
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
					if (linkNode->getNeighbors()[i]->getDist() > linkNode->getDist() + linkNode->getNeighborEdgeWeights()[i]->getWeight())                           //这里可以进行权值比较
					{
						linkNode->getNeighbors()[i]->setDist(linkNode->getDist() + linkNode->getNeighborEdgeWeights()[i]->getWeight());
						linkNode->getNeighbors()[i]->setPath(linkNode);                                      //设置最短路径上的父节点
					}
				}
				else
				{
					linkNode->getNeighbors()[i]->setDist(linkNode->getDist() + linkNode->getNeighborEdgeWeights()[i]->getWeight());
					linkNode->getNeighbors()[i]->setPath(linkNode);
					linkNode->getNeighbors()[i]->setKnow(true);
				}
				//检查
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
	//1.路径分析
	//2.图形转换
	Vertex<T> *v;
	v = graph.getNode();                                                //得到开始节点
	if (v)                                                                          //查找V的单源最短路径算法
	{
		v->setEC(0);                                                             //设置初始顶点的最早开始时间为0，而所有顶点的最晚开始时间为子节点中减去路径长中的最小值
		queue<Vertex<T>*> nodeQueue;
		vector<Vertex<T>*>checkNode;
		Vertex<T> *linkNode;
		int checkFlag = 0;
		BFSGraph(graph);
		v->setDist(0);                                                          //计算并记录路径距离为0的节点
		v->setKnow(true);                                                                                               //已被遍历
		v->setPath(nullptr);
		nodeQueue.push(v);
		checkNode.push_back(v);
		while (nodeQueue.size())
		{
			linkNode = nodeQueue.front();
			nodeQueue.pop();
			for (int i = 0; i < (int)linkNode->getNeighbors().size(); i++)
			{
				if (linkNode->getNeighbors()[i]->getKnow())                                                                           //该节点已经被访问过（可能已经是其他节点的子节点）true
				{
					if (linkNode->getNeighbors()[i]->getEC() < linkNode->getEC() + linkNode->getNeighborEdgeWeights()[i]->getWeight())
					{
						linkNode->getNeighbors()[i]->setEC(linkNode->getEC() + linkNode->getNeighborEdgeWeights()[i]->getWeight());     //最早完成时间
					}
				}
				else
				{
					linkNode->getNeighbors()[i]->setEC(linkNode->getEC() + linkNode->getNeighborEdgeWeights()[i]->getWeight());
					linkNode->getNeighbors()[i]->setKnow(true);
				}
				//检查
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

	//以上求得每个节点的最早完成时间，
	//next:最晚完成时间？？？？？？？？？？？？
}