#include"SortAndFind.h"

template <class T>
SortAndFind<T>::SortAndFind()
{

}

template <class T>
SortAndFind<T>::~SortAndFind()
{

}


template <class T>
vector<T> SortAndFind<T>::insertSort(vector<T>& nums)
{
	//插入排序的思想是将后面的元素依次插入到前面数据的合适位置，通过每次与前一个元素作比较，向前插入到最合适的位置，按照非递减排序
	T data;
	//只有当数据量大于1才具有排序的意义
	for (int i = 1; i < nums.size(); i++)
	{
		data = nums[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (nums[j]>data)
			{
				nums[j+1] = nums[j];
			 	nums[j] = data;                                               //通过移动来代替交换
			}
			else
			{
				break;
			}
		}
	}
	return nums;
}

template <class T>
void SortAndFind<T>::shellSort(vector<T>&nums,int h)                        //h为增量
{
  /*	T data;
	for (h; h >= 1; h /= 2)
	{
		for (int i = h; i < nums.size(); i += h)
		{
			data = nums[i];
			for (int j = i - h; j >= 0; j -= h)
			{
				if (nums[j]>data)
				{
					nums[j + h] = nums[j];
					nums[j] = data;
				}
				else
				{
					break;
				}
			}//for(j)
		}//for(i)
	}//for(h)
	*/
	if (h <= nums.size() / 2)                 //若小于一半时，则继续递归下去，然后在执行以下语句
	{
		shellSort(nums, h * 2);
	}
	
		T data;
		for (int i = h; i < nums.size(); i+=h)
		{
			data = nums[i];
			for (int j = i - h; j >=0; j-=h)
			{
				if (nums[j]>data)
				{
					nums[j+h] = nums[j];
					nums[j] = data;
				}
				else
				{
					break;
				}
			}
		}
}


//******************************归并排序************************************
template <class T>
void SortAndFind<T>::mergeSort(vector<T>&nums, int first, int last)
{
	/**
	             采用的思想是分治法，
	*/
	int mid = (first + last) / 2;
	if (first +1< last)
	{
			mergeSort(nums, first, mid);                            //左部分
			mergeSort(nums, mid + 1, last);                      //右部分
			//两边排完顺序后，在执行合并操作,从first 到last 这段数据进行合并操作
	}
	//不用递归就合并
	mergeAB(nums, first, mid, mid + 1, last);
}

template <class T>
void SortAndFind<T>::mergeAB(vector<T>&nums, int firstA, int lastA, int firstB, int lastB)
{
	vector<T>mergeC;
	int i = firstA;
	int j = lastB;
	while (firstA <= lastA&&firstB <= lastB)
	{
		if (nums[firstA] < nums[firstB])
		{
			mergeC.push_back(nums[firstA]);
			++firstA;
		}
		else if (nums[firstA] > nums[firstB])
		{
			mergeC.push_back(nums[firstB]);
			++firstB;
		}
		else
		{
			mergeC.push_back(nums[firstA]);
			mergeC.push_back(nums[firstB]);
			++firstA;
			++firstB;
		}
	}//while(all)
	if (firstA > lastA&&firstB <= lastB)
	{
		while (firstB <= lastB)
		{
			mergeC.push_back(nums[firstB]);
			++firstB;
		}
	}
	else if (firstA <= lastA&&firstB > lastB)
	{
		while (firstA <= lastA)
		{
			mergeC.push_back(nums[firstA]);
			++firstA;
		}
	}
	//
	int t = 0;
	while (i <= j)
	{
		nums[i] = mergeC[t];
		++i;
		++t;
	}
}

//********************************快速排序*******************************************
template <class T>
void SortAndFind<T>::quickSort(vector<T>&nums, int first,int last)                                                 //privot为中间的比较值
{
	//递归的对两边取中间值进行划分
	if (first < last)                                        //一个元素则不用进行交换
	{
		int mid = (first + last) / 2;
		int privot = findPrivotIndex(nums, first, mid, last);                                                                        //参数一般表示为灰色
		
		int i = findQuickCenterIndex(nums, first, last , privot);                                                                //i和j元素以privot为中心执行交换

		quickSort(nums, first, i - 1);                                  //左部分递归
		quickSort(nums, i + 1, last);                                  //右部分递归
	}
}

template <class T>
int SortAndFind<T>::findPrivotIndex(vector<T>&nums, int first, int mid, int last)
{
	T max = nums[last];
	T min = nums[first];
	int maxFlag=last;
	int minFlag = first;
	if (nums[first] > max)
	{
		max = nums[first];
		maxFlag = first;
	}
	if (nums[mid] > max)
	{
		max = nums[mid];
		maxFlag = mid;
	}
	//求最小值
	if (nums[last] < min)
	{
		min = nums[last];
		minFlag = last;
	}
	if (nums[mid] < min)
	{
		min = nums[mid];
		minFlag = mid;
	}
	//返回值
	if (maxFlag == last)
	{
		if (minFlag == first)
		{
			return mid;
		}
		else
		{
			return first;
		}
	}
	else if (maxFlag==first)
	{
		if (minFlag == last)
		{
			return mid;
		}
		else
		{
			return last;
		}
	}
	else     //maxFlag==mid
	{
		if (minFlag == first)
		{
			return last;
		}
		else
		{
			return first;
		}
	}
}


template <class T>
int SortAndFind<T>::findQuickCenterIndex(vector<T>&nums, int first, int last,int privot)
{
	int i=first;
	int j = last - 1;
	T data;
	T changeValue;
	data = nums[privot];
	nums[privot] = nums[last];
	nums[last] = data;
	while (i <= j)
	{
	
		if (nums[i]<data&&nums[j]>data)
		{
			++i;
			--j;
		}
		else if (nums[i]<data)
		{
			++i;
		}
		else if (nums[j]>data)
		{
			--j;
		}
		else                                                  // when i and j stop 
		{
			changeValue = nums[i];
			nums[i] = nums[j];
			nums[j] = changeValue;
			i++;
			j--;
		}
	}//while
	data = nums[i];
	nums[i] = nums[last];
	nums[last] = data;
	return i;
}

//***************************桶式排序*************************************
template <class T>
void SortAndFind<T>::bucketSort(vector<T>&nums, int M)
{
	vector<T>count;
	count.resize(M);
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] < M)
		{
			count[nums[i]]++;
		}
	}
	int t = 0;
	for (int i = 0; i < M; i++)
	{
		while (count[i])
		{
			nums[t] = i;
			count[i]--;
			t++;
		}
	}
}

//***************************基数排序*************************************
template <class T>
void SortAndFind<T>::radixSort(vector<T>&nums)
{
	//若相等，则按照原序排列
	vector<vector<int> >radix;
	radix.resize(10);                                   //i  0到9
	int s = 0;
	//二维则使用push_back();
	int remainder = 0;                         //余数
	int k = 1;
	int flag = 1;
	while (flag)
	{
		flag = 0;
		s = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] / k)
			{
				flag = 1;
			}
			remainder = (nums[i] / k) % 10;
			radix[remainder].push_back(nums[i]);                                          //从小到大排序
		}
		k *= 10;
	//返回到数组nums中
	 for (int i = 0; i < radix.size(); i++)
	 {
		 for (int j = 0; j < radix[i].size();j++)
		 {
		    	nums[s++] = radix[i][j];                              //永远赋值第一个
				cout << radix[i][j] << ", ";
		}
		 radix[i].clear();
	 }
	 cout << endl;
	}
}