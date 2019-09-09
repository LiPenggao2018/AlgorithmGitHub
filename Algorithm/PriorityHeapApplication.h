/**
                    ���ȶ��е�Ӧ��
					1.ѡ������
					2.�¼�ģ��
*/

#pragma once
#include"PriorityBinaryHeap.h"
#include<map>
#include<list>
#include<random>
#include<time.h>
using namespace std;

template <class T>
class PriorityHeapApplication
{
public:
	PriorityHeapApplication();
	~PriorityHeapApplication();
	T find_Kth_minNumber(int k);
	int bankQueue(list<map<int, int >> &customers);                                       //������Ϊƽ��ÿ��˿�������ʱ��ʹ���ʱ�䣬���Ϊ��Ҫ����K������Ա
	PriorityBinaryHeap<T> getPriorityBinaryHeap();
	void setPriorityBinaryHeap(PriorityBinaryHeap<T>  priorityBinaryHeap);

private:
	PriorityBinaryHeap<T> priorityBinaryHeap;
};


