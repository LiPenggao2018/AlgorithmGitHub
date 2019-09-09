/**
        定义图的顶点存储类，类似于Tree
		其中存储着顶点的值和一个vector向量，该向量中存储的是指向邻近结点的指针
		并将该类定义成模板，以便存储各种类型的数据
*/
#ifndef VERTEX_
#define VERTEX_
#pragma once
#include<string>
#include<iostream>
#include<vector>
using namespace std;
#include"EdgeWeight.h"
template<class T>
class Vertex
{
public:
	Vertex();
	~Vertex();
	T getData();
	void setData(T data);
	vector<Vertex*>getNeighbors();
	void setNeighbors(vector<Vertex*>neighbors);
	int getIndegree();
	void setIndegree(int indegree);
	int getDist();
	void setDist(int dist);
	Vertex<T>* getPath();
	void setPath(Vertex<T>* path);
	bool getKnow();
	void setKnow(bool know);
	vector<EdgeWeight<T>*>getNeighborEdgeWeights();
	void setNeighborEdgeWeights(vector<EdgeWeight<T>*>neighborEdgeWeights);

	int getEC();
	void setEC(int EC);
	int getLC();
	void setLC(int LC);
private:
	T data;
	vector<Vertex*>neighbors;                                                 //当前顶点的邻居结点
   vector<EdgeWeight<T>*>neighborEdgeWeights;            //每个顶点包含与它相邻 的边权值向量
	int indegree;                                                                          //当前顶点的入度，通过入度可以进行拓扑排序，(注：拓扑排序也是一直排序，对非数字进行排序)
	int dist;                                                                                  //当前顶点距离初始顶点的距离
	Vertex<T>* path;                                                                 //当前顶点的上一个路径节点
	bool know;                                                                           //是否已经遍历过
	int EC;                                                                                   //当前节点上方标志，最早完成时间
	int LC;                                                                                    //最晚完成时间，最晚完成但不影响总的工程进度
};

#endif