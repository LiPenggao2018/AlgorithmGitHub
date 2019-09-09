#include"PriorityHeapApplication.h"

template <class T>
PriorityHeapApplication<T>::PriorityHeapApplication()
{

}

template <class T>
PriorityHeapApplication<T>::~PriorityHeapApplication()
{

}

template <class T>
T PriorityHeapApplication<T>::find_Kth_minNumber(int k)                                   //注意，模板类的限定符一定要带上模板参数类型,无论是在什么时候和什么地方
{
       //在外面构建堆进行赋值到类的成员变量
	T kMin = 0;
	for (int i = 0; i < k; i++)
	{
		kMin = priorityBinaryHeap.deleteGetMin();
	}
	return kMin;
}

template <class T>
PriorityBinaryHeap<T>  PriorityHeapApplication<T>::getPriorityBinaryHeap()
{
	return priorityBinaryHeap;
}

template <class T>
void PriorityHeapApplication<T>::setPriorityBinaryHeap(PriorityBinaryHeap<T>  priorityBinaryHeap)
{
	this->priorityBinaryHeap = priorityBinaryHeap;
}

template <class T>
int PriorityHeapApplication<T>::bankQueue(list<map<int,int>> &customers)                         //注意：.h和.cpp必须一致，一模一样
{
	int k=0;                                                                                                                                                       	//最后求得在一天中需要k的最大值
	int tick = 0;                                                                                                                                         //时钟
	int arrive = 0;
	const int number = 480;
	int durtime = 0;                                                                                                                                 //顾客处理时间
	map<int, int>::iterator it;                                                                                                              //删除第一个元素
	while (customers.size())                                                                              //只要list里面有元素，                                                //循环执行直到没有顾客为止       map<int,int>=map<arrive,durtime>
	{
		it = customers.front().begin();                                                                 //获得map对象
		
		if (it != customers.front().end())
		{
			arrive = it->first;                                                                                                                            // first 中存储的是每位顾客的到达时间
			durtime = it->second;                                                                                                                    //second中存储的是每位顾客的处理持续时间
		}
		if (priorityBinaryHeap.getHeap().size()<=1)
		{
			priorityBinaryHeap.insertHeap(durtime);
			customers.pop_front();
		}
		else if (priorityBinaryHeap.getHeap()[1]==0)
		{
			priorityBinaryHeap.insertHeap(durtime);
			customers.pop_front();
		}
		tick++;
		vector<int>data;
		for (int i = 0; i < priorityBinaryHeap.getHeap().size(); i++)                                                    //将堆里面的元素都减一
		{
			data.push_back(priorityBinaryHeap.deleteGetMin()-1);
		}
		for (int i = 0; i < data.size(); i++)
		{
			priorityBinaryHeap.insertHeap(data[i]);                                                                                //重新建立小堆
		}
		data.clear();
		if (k < priorityBinaryHeap.getHeap().size())
		{
			k = priorityBinaryHeap.getHeap().size();
		}
	
		if (tick < number)                                             //添加新成员
		{
			unsigned seed = time(0);
			srand(seed);
			int dur = 10 + (int)(10 * rand() / (RAND_MAX + 1.0));
		    map<int, int> m;
			m.insert(pair<int, int>(tick, dur));
			customers.push_back(m);                            //将先来的顾客放到list的尾部
		}
		if (tick >= number)break;
	}//while
	return k;                                                                 //返回最大的k接待员
}