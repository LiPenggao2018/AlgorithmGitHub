#include"PriorityBinaryHeap.h"

template <class T>
PriorityBinaryHeap<T>::PriorityBinaryHeap()                                                        //类必须为绿色，则表示限定
{
	binaryHeap.push_back(0);
}

template <class T>
PriorityBinaryHeap<T>::~PriorityBinaryHeap()
{

}

template <class T>
void PriorityBinaryHeap<T>::insertHeap(T data)
{
	if (binaryHeap.size()>1)
	{
		binaryHeap.push_back(data);                                                   //先插入到尾部，再进行调整
		moveUp(data);
	}
	else
	{
		binaryHeap.push_back(data);                                               
	}
	
}

template <class T>
vector<T> PriorityBinaryHeap<T>::getHeap()
{
	return binaryHeap;
}

template <class T>
void PriorityBinaryHeap<T>::setHeap(vector<T>heap)
{
	this->binaryHeap = heap;
}

template <class T>
void PriorityBinaryHeap<T>::moveUp(T data)                                              //将较小的元素上移,这里将最后的元素上移至合适的位置
{
	int n = binaryHeap.size()-1;
	int i = n / 2;
	while (binaryHeap[i] > data&&i)
	{
		binaryHeap[n] = binaryHeap[i];
		n = i;
		i = i / 2;
	}
	binaryHeap[n] = data;
}

template <class T>
T PriorityBinaryHeap<T>::deleteGetMin()
{
	T data = binaryHeap[1];
	downMove(1);
	return data;

}

template <class T>
void PriorityBinaryHeap<T>::downMove(int i)
{
	int n = binaryHeap.size();
	T data = binaryHeap[n - 1];
	binaryHeap.pop_back();
	n--;                                                                 // ***注意pop_back()后向量的大小减小一个，因为n是在pop_back()之前，所以这里的n需要减去1
	while (2*i<n)
	{
	 if (i * 2 + 1 < n)
	 {
		if (binaryHeap[i * 2] < binaryHeap[i * 2 + 1])
		{
			if (data > binaryHeap[i * 2])
			{
            	binaryHeap[i] = move(binaryHeap[i * 2]);
		    	i = i * 2;
			}
			else
			{
				binaryHeap[i] = data;
				break;
			}
		}//if
		else
		{
			if (data > binaryHeap[i * 2+1])
			{
				binaryHeap[i] = binaryHeap[i * 2 + 1];
				i = i * 2+1;
			}
			else
			{
				binaryHeap[i] = data;
				break;
			}
		}
	 }
	 else                        //i=2*n;         说明只有一个左子树
	 {
		 if (data > binaryHeap[i * 2])
		 {
			 binaryHeap[i] = binaryHeap[i * 2];
			 i = i * 2;
		 }
		 else
		 {
			 binaryHeap[i] = data;
			 break;
		 }
	 }
	}//while
	if (binaryHeap.size()>1)
	{
        binaryHeap[i] = data;
	}
	
}