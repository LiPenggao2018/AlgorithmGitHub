/**
   1.对所有数据结构或算法类进行编程测试，由于全部放在main中导致测试的代码越来越多，因此通过面向对象的方法进行规范测试
   2.Test类中包含各分类，各分类中包含具体的方法进行测试
*/
#pragma once
#include<iostream>
#include<math.h>
#include<set>
#include<map>
#include<string>
#include"TestAdvancedAlgorithm.h"
// 注意：包含文件可以在同级下相对路径直接包含，也可以根据绝对路径包含，也可以通过网络地址包含。
using namespace std;

class Test
{
public:
	Test();
	~Test();

	//以下是测试类方法
	TestAdvancedAlgorithm testAdvancedAlgorithm;     //测试高级算法的方法，这里定义对象

private:

};

