/**
                    优先队列的应用
					1.选择问题
					2.事件模拟
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
	int bankQueue(list<map<int, int >> &customers);                                       //输入流为平均每天顾客数到达时间和处理时间，输出为需要多少K个出纳员
	PriorityBinaryHeap<T> getPriorityBinaryHeap();
	void setPriorityBinaryHeap(PriorityBinaryHeap<T>  priorityBinaryHeap);

private:
	PriorityBinaryHeap<T> priorityBinaryHeap;
};


