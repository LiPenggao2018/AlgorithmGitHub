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
T PriorityHeapApplication<T>::find_Kth_minNumber(int k)                                   //ע�⣬ģ������޶���һ��Ҫ����ģ���������,��������ʲôʱ���ʲô�ط�
{
       //�����湹���ѽ��и�ֵ����ĳ�Ա����
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
int PriorityHeapApplication<T>::bankQueue(list<map<int,int>> &customers)                         //ע�⣺.h��.cpp����һ�£�һģһ��
{
	int k=0;                                                                                                                                                       	//��������һ������Ҫk�����ֵ
	int tick = 0;                                                                                                                                         //ʱ��
	int arrive = 0;
	const int number = 480;
	int durtime = 0;                                                                                                                                 //�˿ʹ���ʱ��
	map<int, int>::iterator it;                                                                                                              //ɾ����һ��Ԫ��
	while (customers.size())                                                                              //ֻҪlist������Ԫ�أ�                                                //ѭ��ִ��ֱ��û�й˿�Ϊֹ       map<int,int>=map<arrive,durtime>
	{
		it = customers.front().begin();                                                                 //���map����
		
		if (it != customers.front().end())
		{
			arrive = it->first;                                                                                                                            // first �д洢����ÿλ�˿͵ĵ���ʱ��
			durtime = it->second;                                                                                                                    //second�д洢����ÿλ�˿͵Ĵ������ʱ��
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
		for (int i = 0; i < priorityBinaryHeap.getHeap().size(); i++)                                                    //���������Ԫ�ض���һ
		{
			data.push_back(priorityBinaryHeap.deleteGetMin()-1);
		}
		for (int i = 0; i < data.size(); i++)
		{
			priorityBinaryHeap.insertHeap(data[i]);                                                                                //���½���С��
		}
		data.clear();
		if (k < priorityBinaryHeap.getHeap().size())
		{
			k = priorityBinaryHeap.getHeap().size();
		}
	
		if (tick < number)                                             //����³�Ա
		{
			unsigned seed = time(0);
			srand(seed);
			int dur = 10 + (int)(10 * rand() / (RAND_MAX + 1.0));
		    map<int, int> m;
			m.insert(pair<int, int>(tick, dur));
			customers.push_back(m);                            //�������Ĺ˿ͷŵ�list��β��
		}
		if (tick >= number)break;
	}//while
	return k;                                                                 //��������k�Ӵ�Ա
}