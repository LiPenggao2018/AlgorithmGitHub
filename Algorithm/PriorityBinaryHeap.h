/**
        1. 优先排序，以O(1)时间找到最值，应用于系统进程优先级的调度
		2. 通过插入构造二叉堆，上移或者下移进行调整
		（注：插入元素到向量的尾部时，则上移至合适位置；删除元素时，则是删除第一个最值元素，然后将最后的元素插入的第一个去，在执行下移至合适位置）
		3. 堆排序，根据堆的删除原则可以进行堆排序
		时间复杂度为nlog(n)
*/
#pragma once
#include<vector>
using namespace std;

template <class T>
class PriorityBinaryHeap
{
public:
	PriorityBinaryHeap();
	~PriorityBinaryHeap();
	void insertHeap(T data);
	vector<T> getHeap();
	void setHeap(vector<T>heap);
	void moveUp(T data);                                               //将较小的元素上移
	T deleteGetMin();
	void downMove(int i);                                             //将第i个节点进行下移，这里的i是从1开始的节点

private:
	vector<T> binaryHeap;                                            //T 可以是map类型
};

