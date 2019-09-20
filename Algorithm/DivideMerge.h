/**
  1.分治法(分合法)算法及问题求解
  特征：分治法不是将大问题均等分割，而是对问题进行不断的递归2分（或其他比例的分割）
  然后合并每一层并返回给上一层。
  2. 分治法思想的应用如下：
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

	//以下是各类算法和问题求解
	int findMedian(vector<int>& num, int first, int last);    //分治法计算中位数
	int multiplicationOfLargeInteger(int num1, int num2);     //分治法求解大整数乘法
	double pow(double x,int n);                                     //求解指数
	//----------------------------------------------------
	void quickSort(vector<int> &num,int low, int high);       //从分治法的角度来理解快速排序
	int divideLR(vector<int>&num, int low, int high);
	//----------------------------------------------------
	void mergeSort(vector<int>&num, int low,int high);         //基于分治法思想的合并排序
	void conquer(vector<int>&num, int low, int mid,int high);  //治就是插入合并到一个数组中排序
	//----------------------------------------------------
	vector<vector<Point>> TileBoard(int n, int m,Point point);
	void Tile(int sum, Point point,Point position);              //n为当前方格的大小，即包含多少个基本方格单元1×1；point表示缺少点或已填充点；position表示分割的大方格的右下角的顶点坐标（x,y）,x,y>=1;
    //----------------------------------------------------
	int countInversions(vector<int>&nums, int low, int high);    //计算翻转数的对数，为什么要用合并排序，其他的排序或方法行不行？？？
	int CountMergeSort(vector<int>&nums, int low, int mid, int high);
	//----------------------------------------------------
	double ClosedShortestPoint(vector<Point>&num);               //计算一堆点中距离最短的两个点的距离，即顶点
	void pointMergeSort(vector<Point>&num, int low, int high, int flag);  //先对一堆顶点进行x排序存放
	void pointXConquer(vector<Point>&num, int low, int mid, int high);
	void pointYConquer(vector<Point>&num, int low, int mid, int high);  
	double shortestPointMergeSort(vector<Point>&num, int low, int high);   //先对顶点进行分割
	double shortestCenterPointConquer(vector<Point>&num, int low, int mid, int high, double d); //再对顶点进行计算距离
	//-----------------------------------------------------
	vector<double> polynomialsMultiply(vector<double>&numA, int lowA, int highA, vector<double>&numB, int lowB, int highB);
	vector<double> crossAdd(vector<double> &numa, int midA, int highB, vector<double>&numb, int highA, int midB, int &d);  //只需求解最高次幂，并按冥次的高低进行叠加，instead of 数据的个数，因为原本就是要根据幂次进行叠加           //为什么多个参数的重载要声明为friend类型,对于双目运算符  友元函数：左边一般不是对象             //对2个vector变量进行加法重载

private:
	vector<vector<Point>> quardPoint;
	
};
