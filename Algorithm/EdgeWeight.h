/**
           1���洢ͼ���������������Ȩֵ
*/
#ifndef EDGE_WEIGHT
#define EDGE_WEIGHT
#pragma once
using namespace std;
template<class T>
class Vertex;                                  //������ģ����������һ������

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
	int weight;                                    //�ڵ�s ��p֮���Ȩֵ
};
#endif