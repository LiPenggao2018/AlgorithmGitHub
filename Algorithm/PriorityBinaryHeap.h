/**
        1. ����������O(1)ʱ���ҵ���ֵ��Ӧ����ϵͳ�������ȼ��ĵ���
		2. ͨ�����빹�����ѣ����ƻ������ƽ��е���
		��ע������Ԫ�ص�������β��ʱ��������������λ�ã�ɾ��Ԫ��ʱ������ɾ����һ����ֵԪ�أ�Ȼ������Ԫ�ز���ĵ�һ��ȥ����ִ������������λ�ã�
		3. �����򣬸��ݶѵ�ɾ��ԭ����Խ��ж�����
		ʱ�临�Ӷ�Ϊnlog(n)
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
	void moveUp(T data);                                               //����С��Ԫ������
	T deleteGetMin();
	void downMove(int i);                                             //����i���ڵ�������ƣ������i�Ǵ�1��ʼ�Ľڵ�

private:
	vector<T> binaryHeap;                                            //T ������map����
};

