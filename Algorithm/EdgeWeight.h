/**
           1、存储图中相邻两个顶点的权值
*/
#ifndef EDGE_WEIGHT
#define EDGE_WEIGHT
#pragma once
using namespace std;
template<class T>
class Vertex;                                  //在两个模板类中声明一个即可

template<class U>
class EdgeWeight
{
public:
	EdgeWeight();
   EdgeWeight(Vertex<U>* s,Vertex<U>* p,int weight);
	~EdgeWeight();
	Vertex<U>getS();
	void setS(Vertex<U>* s);
	Vertex<U>getP();
	void setP(Vertex<U>*p);
	int getWeight();
	void setWeight(int weight);

private:
	Vertex<U>* s;
	Vertex<U>* p;
	int weight;                                    //节点s 到p之间的权值
};
#endif