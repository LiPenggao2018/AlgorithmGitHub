/**
         ����һ��Ԫ���Ƿ������ݿ��У������ȶ����ݿ��е�Ԫ�ؽ�������Ȼ����ͨ�����ַ����в��ң�
		  �����ݿ���ȫ���洢���ڴ��У���ֱ�ӽ����ڲ����򣬶������ݽϴ�ʱ������ʹ�û��ڹ鲢˼����ⲿ����
*/
#pragma once
#include<math.h>
#include<vector>
using namespace std;


template <class T>
class SortAndFind
{
public:
	SortAndFind();
	~SortAndFind();
	vector<T> insertSort(vector<T>& nums);
	void shellSort(vector<T>&nums,int h);
	void mergeSort(vector<T>&nums,int first,int last);                                       //�鲢�����������鲢����ԭ����һ��Ϊ����ͬ�����ǿ������޵Ľ��зָ�ٺϲ�
	void mergeAB(vector<T>&nums, int firstA, int lastA, int firstB, int lastB);
	void quickSort(vector<T>&nums, int first, int last);                                                   //privotΪ�м�ıȽ�ֵ
	int findPrivotIndex(vector<T>&nums, int first, int mid, int last);
	int findQuickCenterIndex(vector<T>&nums, int first, int last,int privot);                                 
	void bucketSort(vector<T>&nums, int M);                                                          //Ͱʽ��������M��ʾͰ�ĸ�������nums�����е�ֵ����Ҫ����M
	void radixSort(vector<T>&nums);                                                                        //��������0��9ʮ��Ͱ��������
private:

};

