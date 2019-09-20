#pragma once
#include<iostream>
#include<math.h>
#include"DivideMerge.h"
using namespace std;

class TestDivideMerge
{
public:
	TestDivideMerge();
	~TestDivideMerge();

	int testFindMedian();                   // 测试寻找中位数
	int testFindMedian(vector<int>& num);
	int testPow();                          //分治法计算pow
	void testQuickSort();
	void testMergeSort();                   //基于分治思想的合并排序
	void testTileBoard();                   //通过分治法来贴方格地板
	void testCountInversions();

	void testPointMergeSort();              //测试顶点排序
	void testClosedShortestPoint();         //测试平面上点的最短两个点的距离

	void testPolynomialsMultiply();         //测试多项式相乘
private:


};

