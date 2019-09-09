/**
        ����ͼ�Ķ���洢�࣬������Tree
		���д洢�Ŷ����ֵ��һ��vector�������������д洢����ָ���ڽ�����ָ��
		�������ඨ���ģ�壬�Ա�洢�������͵�����
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
	vector<Vertex*>neighbors;                                                 //��ǰ������ھӽ��
   vector<EdgeWeight<T>*>neighborEdgeWeights;            //ÿ����������������� �ı�Ȩֵ����
	int indegree;                                                                          //��ǰ�������ȣ�ͨ����ȿ��Խ�����������(ע����������Ҳ��һֱ���򣬶Է����ֽ�������)
	int dist;                                                                                  //��ǰ��������ʼ����ľ���
	Vertex<T>* path;                                                                 //��ǰ�������һ��·���ڵ�
	bool know;                                                                           //�Ƿ��Ѿ�������
	int EC;                                                                                   //��ǰ�ڵ��Ϸ���־���������ʱ��
	int LC;                                                                                    //�������ʱ�䣬������ɵ���Ӱ���ܵĹ��̽���
};

#endif