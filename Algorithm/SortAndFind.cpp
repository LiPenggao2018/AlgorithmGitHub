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
	//���������˼���ǽ������Ԫ�����β��뵽ǰ�����ݵĺ���λ�ã�ͨ��ÿ����ǰһ��Ԫ�����Ƚϣ���ǰ���뵽����ʵ�λ�ã����շǵݼ�����
	T data;
	//ֻ�е�����������1�ž������������
	for (int i = 1; i < nums.size(); i++)
	{
		data = nums[i];
		for (int j = i - 1; j >= 0; j--)
		{
			if (nums[j]>data)
			{
				nums[j+1] = nums[j];
			 	nums[j] = data;                                               //ͨ���ƶ������潻��
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
void SortAndFind<T>::shellSort(vector<T>&nums,int h)                        //hΪ����
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
	if (h <= nums.size() / 2)                 //��С��һ��ʱ��������ݹ���ȥ��Ȼ����ִ���������
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


//******************************�鲢����************************************
template <class T>
void SortAndFind<T>::mergeSort(vector<T>&nums, int first, int last)
{
	/**
	             ���õ�˼���Ƿ��η���
	*/
	int mid = (first + last) / 2;
	if (first +1< last)
	{
			mergeSort(nums, first, mid);                            //�󲿷�
			mergeSort(nums, mid + 1, last);                      //�Ҳ���
			//��������˳�����ִ�кϲ�����,��first ��last ������ݽ��кϲ�����
	}
	//���õݹ�ͺϲ�
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

//********************************��������*******************************************
template <class T>
void SortAndFind<T>::quickSort(vector<T>&nums, int first,int last)                                                 //privotΪ�м�ıȽ�ֵ
{
	//�ݹ�Ķ�����ȡ�м�ֵ���л���
	if (first < last)                                        //һ��Ԫ�����ý��н���
	{
		int mid = (first + last) / 2;
		int privot = findPrivotIndex(nums, first, mid, last);                                                                        //����һ���ʾΪ��ɫ
		
		int i = findQuickCenterIndex(nums, first, last , privot);                                                                //i��jԪ����privotΪ����ִ�н���

		quickSort(nums, first, i - 1);                                  //�󲿷ֵݹ�
		quickSort(nums, i + 1, last);                                  //�Ҳ��ֵݹ�
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
	//����Сֵ
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
	//����ֵ
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

//***************************Ͱʽ����*************************************
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

//***************************��������*************************************
template <class T>
void SortAndFind<T>::radixSort(vector<T>&nums)
{
	//����ȣ�����ԭ������
	vector<vector<int> >radix;
	radix.resize(10);                                   //i  0��9
	int s = 0;
	//��ά��ʹ��push_back();
	int remainder = 0;                         //����
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
			radix[remainder].push_back(nums[i]);                                          //��С��������
		}
		k *= 10;
	//���ص�����nums��
	 for (int i = 0; i < radix.size(); i++)
	 {
		 for (int j = 0; j < radix[i].size();j++)
		 {
		    	nums[s++] = radix[i][j];                              //��Զ��ֵ��һ��
				cout << radix[i][j] << ", ";
		}
		 radix[i].clear();
	 }
	 cout << endl;
	}
}