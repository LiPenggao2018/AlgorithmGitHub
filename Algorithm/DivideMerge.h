/**
  1.���η�(�ֺϷ�)�㷨���������
  ���������η����ǽ���������ȷָ���Ƕ�������в��ϵĵݹ�2�֣������������ķָ
  Ȼ��ϲ�ÿһ�㲢���ظ���һ�㡣
  2. ���η�˼���Ӧ�����£�
*/
# pragma once
#include<iostream>
#include<math.h>
#include<string>
#include<vector>
#include<math.h>
#include"Point.h"
using namespace std;

class DivideMerge
{
public:
	DivideMerge();
	~DivideMerge();

	//�����Ǹ����㷨���������
	int findMedian(vector<int>& num, int first, int last);    //���η�������λ��
	int multiplicationOfLargeInteger(int num1, int num2);     //���η����������˷�
	double pow(double x,int n);                                     //���ָ��
	//----------------------------------------------------
	void quickSort(vector<int> &num,int low, int high);       //�ӷ��η��ĽǶ�������������
	int divideLR(vector<int>&num, int low, int high);
	//----------------------------------------------------
	void mergeSort(vector<int>&num, int low,int high);         //���ڷ��η�˼��ĺϲ�����
	void conquer(vector<int>&num, int low, int mid,int high);  //�ξ��ǲ���ϲ���һ������������
	//----------------------------------------------------
	vector<vector<Point>> TileBoard(int n, int m,Point point);
	void Tile(int sum, Point point,Point position);              //nΪ��ǰ����Ĵ�С�����������ٸ���������Ԫ1��1��point��ʾȱ�ٵ�������㣻position��ʾ�ָ�Ĵ󷽸�����½ǵĶ������꣨x,y��,x,y>=1;
    //----------------------------------------------------
	int countInversions(vector<int>&nums, int low, int high);    //���㷭ת���Ķ�����ΪʲôҪ�úϲ���������������򷽷��в��У�����
	int CountMergeSort(vector<int>&nums, int low, int mid, int high);
	//----------------------------------------------------
	double ClosedShortestPoint(vector<Point>&num);               //����һ�ѵ��о�����̵�������ľ��룬������
	void pointMergeSort(vector<Point>&num, int low, int high, int flag);  //�ȶ�һ�Ѷ������x������
	void pointXConquer(vector<Point>&num, int low, int mid, int high);
	void pointYConquer(vector<Point>&num, int low, int mid, int high);  
	double shortestPointMergeSort(vector<Point>&num, int low, int high);   //�ȶԶ�����зָ�
	double shortestCenterPointConquer(vector<Point>&num, int low, int mid, int high, double d); //�ٶԶ�����м������
	//-----------------------------------------------------
	vector<double> polynomialsMultiply(vector<double>&numA, int lowA, int highA, vector<double>&numB, int lowB, int highB);
	vector<double> crossAdd(vector<double> &numa, int midA, int highB, vector<double>&numb, int highA, int midB, int &d);  //ֻ�������ߴ��ݣ�����ڤ�εĸߵͽ��е��ӣ�instead of ���ݵĸ�������Ϊԭ������Ҫ�����ݴν��е���           //Ϊʲô�������������Ҫ����Ϊfriend����,����˫Ŀ�����  ��Ԫ���������һ�㲻�Ƕ���             //��2��vector�������мӷ�����

private:
	vector<vector<Point>> quardPoint;
	
};
