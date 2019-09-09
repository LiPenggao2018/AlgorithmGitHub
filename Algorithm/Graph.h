/**
        ͼ���㷨
		1.ͼ�Ľ�������������
		2.ʵ������ת����ͼ��������⣺
		2.1���·���㷨����Ȩ���·������->��û�и��ߵ�����£������⸳Ȩ���·������DK�㷨->�����и��ߵ�ͼ�����·��->������ʱ�������Ȧͼ�ĸ�Ȩ���·������
		2.2ͼ����������⣬��ʵ��ͼ���㷨��Ӧ��

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
	void topSort(Graph<T> graph);                                                                                                       //��ͼ�����������򣬳�ʼ����Ϊ��ͷ������ͨͼ
	void buildGraphNode();                                                                                                                   //����ͼ���ڽӱ�ڵ�node*�洢�ṹ
	void buildGraphMatrixVertex(int row,int col);                                                                              //����ͼ���ڽӾ����ά�����洢�ṹ
	void BFSGraph(Graph<T> graph);                                                                                                  //������ȱ���ͼ
	vector<Vertex<T>*> unweightedShortestPath(Graph<T>graph, T s, T p);                                //��Ȩ��ԭ�����·������㷨��ͨ�����㷨���Լ���ĳ����s�ɵ������������������Ȩ·��
	vector<Vertex<T>*> twoPointShortestPath(Graph<T>graph, T p);
	Vertex<T>* findVertexNode(Graph<T>graph,T s);                                                                      //����ĳ���ڵ��ָ��
	vector<Vertex<T>*>weightedShortestPathDijkstra(Graph<T>graph, T s, T p);                       //��Ȩ���·��Dijkstra�㷨
	vector<Vertex<T>*>criticalPathUnCycle(Graph<T>graph);                                                     //��Ȧͼ�����ؼ�·���ķ���

private:
	                                                                                                                                                           //ͼ�ı�ʾ��Ϊ���֣���ά���������ڳ���ͼ�Ĵ洢�����ڽӱ����洢
	vector<vector<T>>matrixVertex;                                                                                                  //�ڽӾ���
	Vertex<T> *node;                                                                                                                             //node��Ϊ��ʼ��㣻node�����س��ȱߵĶ��壬ֻ��Ҫ����һ���ڵ㣬��Ϊ�ýڵ��д洢����Χ�ĵ㣬����Χ�ĵ��д洢�����ڵ���Χ�ĵ�
	vector<T> vertices;                                                                                                                          //ͼ�������洢���ݵ����飬��matrixVertex��node���������洢����֮��Ĺ�ϵ��
};                                                                                                                                                             //����һ���ڵ㣬�Ƿ���ҪT

