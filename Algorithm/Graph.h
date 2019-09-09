/**
        图论算法
		1.图的建立和拓扑排序
		2.实际问题转化成图的求解问题：
		2.1最短路径算法：无权最短路径问题->在没有负边的情况下，如何求解赋权最短路径问题DK算法->求解带有负边的图的最短路径->以线性时间求解无圈图的赋权最短路径问题
		2.2图的最大流问题，其实是图的算法的应用

*/
#pragma once
#include<vector>
#include<queue>
#include<stack>
#include"Vertex.h"
#include"Vertex.cpp"
using namespace std;
template<class T>
class Graph
{
public:
	Graph<T>();
	~Graph<T>();
	vector<vector<T>> getMatrixVertex();
	void setMatrixVertex(vector<vector<T>>matrixVertex);
	Vertex<T>* getNode();
	void setNode(Vertex<T>* node);
	vector<T>getVertices();
	void setVertices(vector<T>vertices);
	void topSort(Graph<T> graph);                                                                                                       //对图进行拓扑排序，初始条件为带头结点的连通图
	void buildGraphNode();                                                                                                                   //构建图的邻接表节点node*存储结构
	void buildGraphMatrixVertex(int row,int col);                                                                              //构建图的邻接矩阵二维向量存储结构
	void BFSGraph(Graph<T> graph);                                                                                                  //广度优先遍历图
	vector<Vertex<T>*> unweightedShortestPath(Graph<T>graph, T s, T p);                                //无权单原点最短路径求解算法，通过该算法可以计算某个顶s可到达的其他顶点的最短无权路径
	vector<Vertex<T>*> twoPointShortestPath(Graph<T>graph, T p);
	Vertex<T>* findVertexNode(Graph<T>graph,T s);                                                                      //查找某个节点的指针
	vector<Vertex<T>*>weightedShortestPathDijkstra(Graph<T>graph, T s, T p);                       //赋权最短路径Dijkstra算法
	vector<Vertex<T>*>criticalPathUnCycle(Graph<T>graph);                                                     //无圈图用作关键路径的分析

private:
	                                                                                                                                                           //图的表示分为两种：二维向量适用于稠密图的存储；用邻接表来存储
	vector<vector<T>>matrixVertex;                                                                                                  //邻接矩阵
	Vertex<T> *node;                                                                                                                             //node即为开始结点；node中隐藏出度边的定义，只需要定义一个节点，因为该节点中存储着周围的点，而周围的点有存储着相邻的周围的点
	vector<T> vertices;                                                                                                                          //图中用来存储数据的数组，而matrixVertex和node则是用来存储顶点之间的关系，
};                                                                                                                                                             //定义一个节点，是否需要T

