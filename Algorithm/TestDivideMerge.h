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

	int testFindMedian();                   // ����Ѱ����λ��
	int testFindMedian(vector<int>& num);
	int testPow();                          //���η�����pow
	void testQuickSort();
	void testMergeSort();                   //���ڷ���˼��ĺϲ�����
	void testTileBoard();                   //ͨ�����η���������ذ�
	void testCountInversions();

	void testPointMergeSort();              //���Զ�������
	void testClosedShortestPoint();         //����ƽ���ϵ�����������ľ���

	void testPolynomialsMultiply();         //���Զ���ʽ���
private:


};

