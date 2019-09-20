/**
  1.对高级算法进行测试的类

*/

#pragma once
#include<iostream>
#include"TestDivideMerge.h"              //测试就专门的调用测试类 都以test开头
using namespace std;

class TestAdvancedAlgorithm
{
public:
	TestAdvancedAlgorithm();
	~TestAdvancedAlgorithm();
	TestDivideMerge *testDivideMerge;      //定义一个测试对象
private:

};

