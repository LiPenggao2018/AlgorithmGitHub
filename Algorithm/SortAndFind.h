/**
         查找一个元素是否在数据库中，可以先对数据库中的元素进行排序，然后在通过二分法进行查找，
		  若数据可以全部存储于内存中，则直接进行内部排序，而当数据较大时，我们使用基于归并思想的外部排序
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
	void mergeSort(vector<T>&nums,int first,int last);                                       //归并排序先排序后归并，将原数据一分为二，同理，我们可以无限的进行分割，再合并
	void mergeAB(vector<T>&nums, int firstA, int lastA, int firstB, int lastB);
	void quickSort(vector<T>&nums, int first, int last);                                                   //privot为中间的比较值
	int findPrivotIndex(vector<T>&nums, int first, int mid, int last);
	int findQuickCenterIndex(vector<T>&nums, int first, int last,int privot);                                 
	void bucketSort(vector<T>&nums, int M);                                                          //桶式排序，其中M表示桶的个数，且nums中所有的值都不要大于M
	void radixSort(vector<T>&nums);                                                                        //基数排序，0到9十个桶进行排序
private:

};

