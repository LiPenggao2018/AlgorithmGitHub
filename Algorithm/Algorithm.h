/***************************************************************
    （1）用面向对象的思想写过程化程序和算法，二者并不矛盾，
	     反而是更全面的考虑，更简洁的调用和更优化的设计，
	     将算法的过程予以封装，将封装的结果予以应用。
    （2）用C++进行编程，利用STL进行调用，专注于算法，优化细节。
****************************************************************/
#include<iostream>
#include<math.h>
#include<set>
#include<map>
#include<string>
#include<vector>
#include"struct.h"
using namespace std;
//****************************************************************
class Algorithm
{
public:
	Algorithm();

	~Algorithm();
	//*****************************************************模板函数
	template < class T>
	inline T polynomial(vector<T > a, T x, int n);    //计算n次多项式：P(x)=(...(An*x+An-1)*x+...A1)*x+A0)

	template<typename T>
	inline vector<T> intervalCount(vector<T >a);       //函数返回一个向量数组
    //************************************************************
	template<class T>
	inline T maxSubArray(vector<T>&nums);

	//******************************** leetcode -vector************************************
	template<class T>
	inline T maxProfit(vector<T>& prices);
	
	template<class T>
	inline int kdiffPairs(vector<T>& nums , int k);

	template<class T>
	inline int findUnsortedSubarray(vector<T>& nums);

	template<class T>
	inline vector<vector<T>> imageSmoother(vector<vector<T>>& M);              //求卷积

	template<class T>
	inline vector<T>merge(vector<T>&intervals, Interval newInterval);

	//******************************** leetcode -sort************************************
	template<class T>
	inline void sortColors(vector<T>&nums);

	template<class T>
	inline string largestNumber(vector<T>&nums);

	template<class T>
	inline void wiggleSort(vector<T>&nums);

	template<class T>
	inline vector<T> intersection(vector<T>& nums1, vector<T>& nums2);
	
	template<class T> 
	inline  vector<T> radixSort(vector<T> &nums);

	template<class T>
	inline string findLongestWord(T s, vector<T>&d);

	template<class T>
	inline int maxAreaOfIsland(vector<vector<T>>& grid);

	template<class T>
	inline int findShortestSubArray(vector<T>& nums);

	template<class T>
	inline bool isOneBitCharacter(vector<T>&bits);

	template<class T>
	inline  bool isToeplitzMatrix(vector<vector<T>>& matrix);

	template<class T>
	inline  vector<vector<int>> largeGroupPositions(T S);

	template<class T>
	inline vector<vector<T>> flipAndInvertImage(vector<vector<T>> &A);

	template<class T>
	inline  int numMagicSquaresInside(vector<vector<T>>& grid);
	 
	template<class T>
	inline vector<int> fairCandySwap(vector<T>& A, vector<T>& B);

	template<class T>
	inline bool hasGroupsSizeX(vector<T>&deck);
private:

};

//********************************************************************
template < class T>
inline T Algorithm::polynomial(vector<T > a, T x, int n)  //可定义模板类和模板函数               //多项式相加
{
	if (n < a.size() - 1)
	{
		return a[n] + polynomial(a, x, n + 1)*x;
	}
	else
	{
		return a[n];  //递归终止条件：当n等于最大值的前个数是，递归截止
	}
}

//********************************************************************
template<typename T>
inline vector<T> Algorithm::intervalCount(vector<T >a)              //间隔取数
{
	vector<T > b;                       //存储数组
	int i=0 , j = 0;
    vector<T>:: iterator it;
	it = a.begin();
	b.resize(a.size());
	while(it!=a.end())                       //不兼容待扩展到N间隔
	{
		b[j++] = *it;

		it=a.erase(it);  //注vector有返回值，必须用其返回值进行下一次循环的迭代操作
		if (a.begin() != a.end())
		{
			if (it == a.end())
			{
				it = a.begin();
				it++;
				if (it == a.end())
				{
					it = a.begin();
				}

			}
			else
			{
				if (++it == a.end())
				{
					it = a.begin();
				}
			}
		}
	}
	return b;
}

//---------------------maxSubArray---------------------------------------------------------
template<class T>
inline T Algorithm::maxSubArray(vector<T>&nums)                     //note:the implement must be the same as zhe interface  especially template
{
	/*int maxSum;
	if (nums.size() != 0)
		maxSum = nums[0];
	int sum = 0;
	for (int i = 0; i<nums.size(); i++)
	{
		sum += nums[i];
		if (sum>maxSum)
		{
			maxSum = sum;
		}
		else if (sum<0)
		{
			sum = 0;
		}
	}
	return maxSum;
	*/

	
	T sum = 0;
	T result = 0;
	T finalResult = nums[0];
	int flag;
	int position;
	int finalPosition;
	
	for (int i = 1; i <= nums.size(); i++)
	{
		result = nums[0];
		for (int k = 0; k <= nums.size() - i; k++)
		{
			sum = 0;
			for (int j = 0; j<i; j++)
			{
				sum += nums[k + j];
			}
			if (result<sum)
			{
				result = sum;
				position = k;
			}
		}//for(k)
		if (finalResult<result)
		{
			finalResult = result;
			finalPosition = position;
			flag = i;
		}
	}//for(i)
	return finalResult;
}
//-------------------------
template<class T>
inline T Algorithm::maxProfit(vector<T>& prices)
{
	int i, j;
	int sum = 0;
	for (i = 0; i<prices.size();)                               //i is the buy,j is the sell
	{
		for (j = i + 1; j<prices.size();)
		{
			if (prices[i]<prices[j])
			{
				if (prices[j] >= prices[j - 1])
				{
                    	
					if (j == prices.size() - 1)
					{
						if (prices[j] < prices[i])
						{
							sum += prices[j - 1] - prices[i];
							cout << sum << endl;
							
						}
						else
						{
                              sum += prices[j] - prices[i];
							  cout << sum << endl;
						}
						i = j;
						break;
					}
					else
					{
						if (j == prices.size() - 1)
						{
							sum += prices[j - 1] - prices[i];
							cout << sum << endl;
						}
						
						j++;
					}
				}
				else
				{
					sum += prices[j - 1] - prices[i];
					cout << sum << endl;
					i = j;
					break;
				}
			}
			else                      
			{
				if (i + 1 < j)
				{
					sum += prices[j - 1] - prices[i];
					i = j;
					cout << sum << endl;
				}
				else
				{
					i++;
				}
				break;
			}
		}//for(j)
		if (i == prices.size() - 1)
		{
			break;
		}
	}
	return sum;
}


//求K-D Pairs
template<class T>
inline int Algorithm::kdiffPairs(vector<T>&nums,int k)
{
	int count = 0;
	multiset<int> mSet;
	set<int> mySet;
	for (int i = 0; i<nums.size(); i++)
	{
		mSet.insert(nums[i]);
		mySet.insert(nums[i]);
	}
	multiset<int>::iterator it = mSet.begin();
	multiset<int>::iterator jt;
	set<int>::iterator kt = mySet.begin();
	set<int>::iterator tt;
	if (k == 0)
	{
		int i;
		while (it != mSet.end())
		{
			i = mSet.count(*it);
			if (i>1)
			{
				count++;
				for (i; i >= 1; i--)
				{
					it++;
				}
			}
			else
			{
				it++;
			}
		}//while
	}
	else
	{
		while (kt != mySet.end())
		{
			tt = kt;
			tt++;
			while (tt != mySet.end())
			{
				if (abs(*tt - *kt) == k)
				{
					count++;
					cout <<*tt<<"-"<< *kt << "="<<*tt-*kt <<":"<< count << endl;
					break;
				}
				else
				{
					tt++;
				}
			}
			kt++;
		}
	}
	return count;
}

//寻找无序子序列
template<class T>
inline int Algorithm::findUnsortedSubarray(vector<T>& nums)
{
	int i, j;
	int min = 0, max = 0;
	int t, k;
	int flagI = 0, flagJ = 0;

	if (nums.size() == 1)
	{
		return 0;
	}
	//--------------------------------

	for (i = 0; i<nums.size() - 1;)
	{
		if (nums[i] <= nums[i + 1])
		{
			i++;
		}
		else
		{
			break;
		}
	}
	if (i >= nums.size() - 1)
	{
		
		return 0;
	}
	//---------------------------------
	for (i = 0, j = nums.size() - 1; i<j;)
	{
		if (i + 1 == j)
		{
			if (nums[i]>nums[j])
			{
				return 2;
			}
			else
			{
				return 0;
			}
		}

		multiset<int>mySet;
		multiset<int>::iterator it, jt;
		for (int t = i; t <= j; t++)
		{
			mySet.insert(nums[t]);
		}

		it = mySet.begin();
		jt = mySet.end();
		min = *it;
		max = *(--jt);
		if (nums[i] <= min)
		{
			if (flagI == 0)
				i++;
		}
		else
		{
			flagI = 1;
		}
		if (nums[j] >= max)
		{
			if (flagJ == 0)
				j--;
		}
		else
		{
			flagJ = 1;
		}
		if (flagI&&flagJ)
		{
			break;
		}

		while (it != mySet.end())
		{
			mySet.erase(it++);
		}
	}
	if (i == j)
	{
		return 0;
	}
	else
	{
		return j - i + 1;
	}
}

//--------------------------------------------------卷积————————————————————
template<class T>
inline vector<vector<T>> Algorithm::imageSmoother(vector<vector<T>>& M)              //求卷积
{
	int sum = 0;
	int k = 0;
	vector<vector<T> > result;
	result.resize(M.size());

	for (int i = 0; i < M.size(); i++)
	{
		result[i].resize(M[i].size());
	}

	for (int i = 0; i <M.size() ; i++)
	{
		
		for (int j = 0; j < M[i].size(); j++)
		{
			k = 0;
			sum = M[i][j];
			k++;
			
		if (j - 1 >= 0)                    //left
			{
				sum += M[i][j - 1];
				k++;
			}

			if (j + 1 < M[i].size())           //right
			{
				sum += M[i][j + 1];
				k++;
			}
			
			if (i - 1 >= 0)
			{
				sum += M[i - 1][j];           //up
				k++;
				if (j - 1 >= 0)
				{
					sum += M[i - 1][j - 1];      //up_left
					k++;
				}
				if (j + 1 < M[i-1].size())
				{
					sum += M[i - 1][j + 1];      //up_right
					k++;
				}
			}
		
			if (i + 1 < M.size())
			{
				sum += M[i + 1][j];            //down
				k++;
				if (j - 1 >= 0)
				{
					sum += M[i + 1][j - 1];      //down_left
					k++;
				}

				if (j + 1 < M[i+1].size())
				{
					sum += M[i + 1][j + 1];       //down_right
					k++;
				}
			}
			result[i][j] = sum / k;
		}//for(j)
		cout << endl;
	}//for(i)
	return result;
}


//*************************************间隔数合并***************************
template<class T>
inline vector<T> Algorithm::merge(vector<T>&intervals, Interval newInterval)
{
	
	vector<Interval>intervalss;
	int flag = 0;
	int t;
	for (t = intervals.size() - 1; t >= 0;)
	{
		if (intervals[t].start>newInterval.start || flag)
		{
			intervalss.push_back(intervals[t]);
			--t;
		}
		else
		{
			intervalss.push_back(newInterval);
			flag = 1;
		}
	}//t+1为插入的位置
	intervals.clear();
	for (int i = intervalss.size() - 1; i >= 0; --i)
	{
		intervals.push_back(intervalss[i]);
	}

	Interval temp;
	int i, j;
	vector<Interval>mergeIntervals;
	for (i = 0; i < intervals.size();)                                                  //合并操作
	{
		temp = intervals[i];
		for (j = i + 1; j < intervals.size();)
		{
			if (temp.end >= intervals[j].start)
			{
				//合并两者
				if (temp.end < intervals[j].end)
				{
					temp.end = intervals[j].end;
				}
				j++;
			}
			else
			{
				break;
			}
		}//for(j)
		mergeIntervals.push_back(temp);
		i = j;
	}//for(i)
	return mergeIntervals;
	
	/* 
	Interval temp;                                                                                             
	int i, j;
	vector<Interval>mergeIntervals;
	for (int i = 1; i<intervals.size(); i++)      //先对intervals进行插入排序
	{
		temp = intervals[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (intervals[j].start > temp.start)
			{
				intervals[j + 1] = std::move(intervals[j]);
			}
			else
			{
				break;
			}
		}
		intervals[j + 1] = temp;
	}

	for (i = 0; i < intervals.size(); )                                                  //合并操作
	{
		temp = intervals[i];
		for (j = i + 1; j < intervals.size(); )
		{
			if (temp.end >= intervals[j].start)
			{
				//合并两者
				if (temp.end < intervals[j].end)
				{
					temp.end = intervals[j].end;
				}
				j++;
			}
			else
			{
				break;
			}
		}//for(j)
		mergeIntervals.push_back(temp);
		i = j;
	}//for(i)
	return mergeIntervals;
	*/
}



template<class T>
inline void Algorithm::sortColors(vector<T>&nums)
{
	int i, j, t;
	i = 0;
	t = 0;
	j = nums.size()-1;
	T temp;
	while (i < j)
	{
		if (nums[i] == 0)
		{
			if (nums[t] == 1)
			{
				if (t < i)
				{
                    temp = nums[i];
			    	nums[i] = nums[t];
				   nums[t] = temp;
				   t++;
				   i++;
				}
				else
				{
					i++;
				}
			}
			else if (nums[t]==0)
			{
				t++;
			}
			else
			{
                i++;
			}
		}
		else if (nums[i] == 1)
		{
			if (nums[j] == 0)
			{
				temp = nums[i];
				nums[i] = nums[j];
				nums[j] = temp;
				i++;
			}
			else
			{
				i++;
			}
		}
		else                                                                  //if nums[i]==2
		{
			while (nums[j] == 2)
			{
				if (i >= j)
				{
					break;
				}
				else
				{
                 	j--;
				}
			}
			temp = nums[i];
			nums[i] = nums[j];
			nums[j] = temp;
			if (nums[i] == 1)
			{
				i++;
			}
		}

	}//while
}

template<class T>
inline string Algorithm::largestNumber(vector<T>&nums)
{
	//apply for radixSort
	vector<vector<int> > radix;
	radix.resize(10);
	int i, j;
	int flag = 1;
	int raminder;
	int k = 10;
	int s;
	int eachMax=0;
	vector<int>temp;
	while (flag)
	{
		for (i = 0; i < nums.size(); i++)
		{
			int t = nums[i];
			while (t/ k)
			{
				t /= k;
			}
			radix[t].push_back(nums[i]);
		}

		for (int i = 9; i >= 0; )
		{
			if (radix[i].size()==1)
			{
				temp.push_back(radix[i][0]);                                              //若为1则直接设为最大
				--i;
			}
			else if (radix.size() > 1)
			{
				
			}
			else
			{
				--i;
			}
		}//for



	}//while



	string str;
	for(int i=nums.size()-1;i>=0;i--)
	{
		str+=to_string(nums[i]);
	}
	return str;
}

template<class T>
inline void Algorithm::wiggleSort(vector<T>&nums)
{
	vector<vector<int>>radix;
	int k = 1;
	int flag = 1;
	int remainder;
	int s = 0;
	radix.resize(10);
	while (flag)
	{
		flag = 0;
		s = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			if (nums[i] / k)
			{
				flag = 1;
			}
			remainder = (nums[i] / k) % 10;
			radix[remainder].push_back(nums[i]);
		}
		k *= 10;
		for (int i = 0; i<radix.size(); i++)
		{
			for (int j = 0; j<radix[i].size(); j++)
			{
				nums[s++] = radix[i][j];
			}
			radix[i].clear();
		}
	}//while
	vector<int>temp;
	int i = 0;
	int j = nums.size() - 1;
	while (i + 1 <= j)
	{
		temp.push_back(nums[i]);
		temp.push_back(nums[j]);
		++i;
		--j;
		/**
		怎么处理abbc的问题？？？？？？
		*/
	}
	if (i == j)
	{
		temp.push_back(nums[i]);
	}
	for (int i = 0; i<temp.size(); i++)
	{
		nums[i] = temp[i];
	}
}

template<class T>
inline vector<T> Algorithm::intersection(vector<T>& nums1, vector<T>& nums2)
{
	if (nums1.size() == 0)
	{
		return nums1;
	}
	else if (nums2.size() == 0)
	{
		return nums2;
	}
	vector<T>  nums12;
	mergeSort(nums1, 0, nums1.size() - 1);
	mergeSort(nums2, 0, nums2.size() - 1);
	int mid;
	for (int i = 0; i<nums11.size(); i++)         //二分查找nums22
	{
		int low = 0, high = nums22.size() - 1;
		while (low<=high)
		{
			mid = (low + high) / 2;
			if (nums22[mid]>nums11[i])
			{
				high = mid - 1;
			}
			else if (nums22[mid]<nums11[i])
			{
				low = mid + 1;
			}
			else
			{
				nums12.push_back(nums11[i]);
				for (int i = mid + 1; i<nums22.size(); i++)
				{//向前移动
					nums22[i - 1] = nums22[i];
				}
				nums22.pop_back();
				break;
			}
		}//while
	}
	return nums12;
}

template<class T>
inline  vector<T> Algorithm::radixSort(vector<T> &nums)
{
	if (nums.size() <= 1)
	{
		return nums;
	}
	int flag = 1;
	vector<vector<T>>radix;
	radix.resize(10);
	int remainder;
	int k = 1;
	int s;
	while (flag)
	{
		s = 0;
		flag = 0;
		for (int i = 0; i<nums.size(); i++)
		{
			if (nums[i] / k)
			{
				flag = 1;
			}
			remainder = (nums[i] / k) % 10;
			radix[remainder].push_back(nums[i]);
		}
		k *= 10;
		for (int i = 0; i<radix.size(); i++)
		{
			for (int j = 0; j<radix[i].size(); j++)
			{
				nums[s++] = radix[i][j];
			}
			radix[i].clear();
		}
	}//while
	/*vector<T>number;
	for (int i = 0; i<nums.size() - 1;)
	{
		if (nums[i] == nums[i + 1])
		{
			i++;
		}
		else
		{
			number.push_back(nums[i]);
			i++;
		}
		if (i == nums.size() - 1)
		{
			number.push_back(nums[i]);
		}
	}
	return number;
	*/
	return nums;
}

template<class T>
inline string Algorithm::findLongestWord(T s, vector<T>&d)
{
	//s表示参考字符串， s = "abpcplea";
	map<char, int> hashMap;
	map<char, int>::iterator it;
	for (int i = 0; i<s.size(); i++)
	{
      	it = hashMap.find(s[i]);
		if (it != hashMap.end())
		{
			int t = it->second;
			hashMap.erase(it);
             hashMap.insert(pair<char,int>(s[i],t+1));
		}
		else                       //没有相同的
		{
			hashMap.insert(pair<char, int>(s[i],1));
		}
	}
	int maxLength = 0;
	string word;
	int maxFlag = 0;
	for (int i = 0; i < d.size(); i++)
	{  
		word = d[i];         
		map<char, int> checkHash = hashMap;
		for (int j = 0; j < word.size();)
		{
			it = checkHash.find(word[j]);
			if (it != checkHash.end())                                                 //已经找到
			{                                                          
				j++;
				if (it->second>1)
				{
					it->second--;
				}
				else
				{ 
					checkHash.erase(it);
				}
				if (j == word.size())
				{
					if (word.size()>maxLength)
					{
						maxLength = word.size();
						maxFlag = i;
					}
				}
			}               //没找到，则直接break
			else
			{
				break;
			}
		}
	}//for
	if (maxLength)
	{
		return d[maxFlag];
	}
	else
	{
		return "";
	}
}

template<class T>
inline int Algorithm::maxAreaOfIsland(vector<vector<T>>& grid)
{
	queue<int>islandRow, islandCol;
	int k, t;
	int maxArea = 0;
	int count;
	vector<int> repeatRow, repeatCol;
	for (int i = 0; i<grid.size(); i++)
	{
		for (int j = 0; j<grid[0].size(); j++)
		{
			if (grid[i][j] == 1)
			{
				count = 0;
				islandRow.push(i);
				islandCol.push(j);
				while (!islandRow.empty())
				{
					k = islandRow.front();
					t = islandCol.front();
					count++;
					grid[k][t] = 2;
					islandRow.pop();
					islandCol.pop();
					int ri, rj;
					int length = islandRow.size();
					repeatRow.clear();
					repeatCol.clear();
					for (int i = 0; i < length;i++)
					{
						ri = islandRow.front();
						rj = islandCol.front();
						repeatRow.push_back(ri);
						repeatCol.push_back(rj);
						islandRow.pop();
						islandCol.pop();
						islandRow.push(ri);
						islandCol.push(rj);
					}
					int flag = 0;
					if (k - 1 >= 0)                     //上
					{
						 flag = 0;
						if (grid[k - 1][t] == 1)
						{
							for (int m = 0; m < repeatRow.size(); m++)
							{
								if (repeatRow[m] == k - 1 && repeatCol[m] == t)
								{
									flag = 1; 
									break;
								}
							}
							if (flag==0)
							{
							islandRow.push(k - 1);
							islandCol.push(t);
							}
						}
					}

					if (k + 1<grid.size())            //下
					{
						flag = 0;
						if (grid[k + 1][t] == 1)
						{
							for (int m = 0; m < repeatRow.size(); m++)
							{
								if (repeatRow[m] == k + 1 && repeatCol[m] == t)
								{
									flag = 1;
								}
							}
							if (flag==0)
							{
								islandRow.push(k + 1);
								islandCol.push(t);
							}
						}
					}

					if (t - 1 >= 0)               //左
					{
						flag = 0;
						if (grid[k][t - 1] == 1)
						{
							for (int m = 0; m < repeatRow.size(); m++)
							{
								if (repeatRow[m] == k && repeatCol[m] == t - 1)
								{
									flag = 1;
								}
							}
							if (flag==0)
							{
								islandRow.push(k);
								islandCol.push(t - 1);
							}
						}
					}

					if (t + 1<grid[0].size())                      //右
					{
						flag = 0;
						if (grid[k][t + 1] == 1)
						{
							for (int m = 0; m < repeatRow.size(); m++)
							{
								if (repeatRow[m] == k && repeatCol[m] == t + 1)
								{
									flag = 1;
								}
							}
							if (flag==0)
							{
								islandRow.push(k);
								islandCol.push(t + 1);
							}
						}
					}
				}//while
				if (count>maxArea)
				{
					maxArea = count;
				}
			}//if
		}//for(j)
	}//for(i)
	return maxArea;
}

template<class T>
inline int Algorithm::findShortestSubArray(vector<T>& nums)
{
	set<int> s;
	for (int i = 0; i<nums.size(); i++)
	{
		s.insert(nums[i]);
	}
	int count;
	int maxSum = 0;
	int maxValue;
	for (auto it : s)
	{
		count = 0;
		for (int j = 0; j<nums.size(); j++)
		{
			if (it == nums[j])
			{
				count++;
			}
		}
		if (maxSum<count)
		{
			maxSum = count;
		}
	}

	//求最大数有哪些
	vector<int>v;
	for (auto is : s)
	{
		count = 0;
		for (int j = 0; j<nums.size(); j++)
		{
			if (is == nums[j])
			{
				count++;
			}
		}
		if (count == maxSum)
		{
			v.push_back(is);
		}
	}
	//maxSum为最大频率, v中装入的是最大频率相对应的数值
	//******************************************
	int value;
	int flag = 0;
	int mixCount = nums.size();
	for (int i = 0; i<v.size(); i++)
	{
		count = 0;
		value = v[i];
		flag = 0;
		
		for (int j = 0; j<nums.size(); j++)
		{
			if (value == nums[j])
			{
				flag++;
			}
			if (0<flag &&flag<= maxSum)
			{
				count++;
				if (flag == maxSum)
				{
					break;
				}
			}
		}
		if (count<=mixCount)
		{
			mixCount = count;
		}
	}//for(i)
	return mixCount;
}


template<class T>
inline bool Algorithm::isOneBitCharacter(vector<T>&bits)
{
	int flag = 0;
	if (bits.size() == 1)
	{
		if (bits[0] == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		int i, j;
		for (i = 0, j = 1; i < bits.size(); )
		{
			if (bits[i] == 0)
			{
				
					i++;
					j++;
					if (i >= bits.size())
					{
						i--;
						break;
					}
			}
			else if (bits[i] == 1)
			{
				if (j + 1 < bits.size())
				{
					i += 2;
					if (j + 2 < bits.size())
					{
						j += 2;
					}
					else
					{
						j += 2;
					}
				}
				else
				{
					if ( bits[i] == 0)return true;
					else return false;
				}
			}//else
		}

		if (bits[i] == 0)
		{
            return true;
		}
		else
		{
			return false;
		}
	}
}

template<class T>
inline  bool Algorithm::isToeplitzMatrix(vector<vector<T>>& matrix)
{
	//first testing the 0th row
	int row = matrix.size();
	int col = matrix[0].size();
	int k, t;
	int i = 0;
	int j;
	for (j = 0; j<col; j++)
	{
		k = i;
		t = j;
		while (k<row&&t<col)
		{
			if (matrix[i][j] == matrix[k][t])
			{
				k++;
				t++;
			}
			else
			{
				return false;
			}
		}
	}//for(j)

	if (j == col )
	{
		j = 0;
		for (i = 1; i<row; i++)
		{
			k = i;
			t = j;
			while (k<row&&t<col)
			{
				if (matrix[i][j] == matrix[k][t])
				{
					k++;
					t++;
				}
				else
				{
					return false;
				}
			}
		}//for(i)
		if (i == row)
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//求连续位置
template<class T>
inline  vector<vector<int>> Algorithm::largeGroupPositions(T S)
{
	vector<vector<int>> result;
	int count = 0;
	int j = 0;
	int t = 0;

	for (int i = 0; i<S.length();)
	{
		j = i;
		count = 1;

		if (j + 1<S.length())
		{
			j++;
		}

		while (S[i] == S[j])
		{
			count++;
			if (j + 1<S.length())
			{
				j++;
			}
			else
			{
				j++;
				break;
			}
		
		} // end of while

		if (count >= 3)
		{
			vector<int> re;
			re.push_back(i);
			re.push_back(j - 1);
			result.push_back(re);
			re.clear();
		}

		i = j;
		if (i == S.length() - 1)
		{
			break;
		}
	} // end of for
	
	return result;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
inline vector<vector<T>> Algorithm::flipAndInvertImage(vector<vector<T>> &A)
{
	    int row = A.size();
        int col = A[0].size();
        int start=0;
        int end=col-1;
        int temp;
        
        for(int i=0;i<row;i++)
        {
            start=0;
            end=col-1;
            
            while(start<end)
            {
                temp = A[i][start];
                A[i][start]=A[i][end];
                A[i][end]=temp;
                
                if(A[i][start]==0)
                {
                    A[i][start]=1;
                }
                else
                {
                    A[i][start]=0;
                }
                
                if(A[i][end]==0)
                {
                    A[i][end]=1;
                }
                else
                {
                    A[i][end]=0;
                }
                
                start++;
                end--;
            }//while
            
            if(start==end)
            {
                if(A[i][start]==0)
                {
                    A[i][start]=1;
                }
                else
                {
                    A[i][start]=0;
                }
            } //if
            
        }//for
        
        return A;
}

template<class T>
inline  int  Algorithm::numMagicSquaresInside(vector<vector<T>>& grid)
{
	int row = grid.size();
	int col = grid[0].size();
	int sum = 0;
	int count = 0;
	int s;
	int flag = 0;
	if (row >= 3 && col >= 3)
	{
		for (int i = 0; i<row - 2; i++)
		{
			for (int j = 0; j<col - 2; j++)
			{

				flag = 0;
				sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];
				for (int m = 0; m<3; m++)
				{
					if (grid[i][j + m] == 0 || grid[i][j + m]>9)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 1)
				{
					continue;
				}

				for (int r = 1; r<3; r++)   //the sum of each row 
				{
					s = 0;
					for (int k = 0; k<3; k++)
					{
						if (grid[i + r][j + k] == 0 || grid[i + r][j + k]>9)
						{
							flag = 1;
							break;
						}
						s += grid[i + r][j + k];
					}
					if (sum != s || flag == 1)
					{
						flag = 1;
						break;
					}
				}

				if (flag == 1)
				{
					continue;
				}

				for (int c = 0; c<3; c++)     //the sum of each col
				{
					s = 0;
					for (int t = 0; t<3; t++)
					{
						if (grid[i + t][j + c] == 0 || grid[i + t][j + c]>9)
						{
							flag = 1;
							break;
						}
						s += grid[i + t][j + c];
					}
					if (sum != s || flag == 1)
					{
						flag = 1;
						break;
					}
				}

				if (flag == 1)
				{
					continue;
				}

				s = 0;
				for (int k = 0; k<3; k++)  //the sum of diagonals
				{
					if (grid[i + k][j + k] == 0 || grid[i + k][j + k]>9)
					{
						flag = 1;
						break;
					}
					s += grid[i + k][j + k];
				}
				if (sum != s || flag == 1)
				{
					continue;
				}

				s = 0;
				for (int k = 0, t = 2; k<3 && t >= 0; k++, t--)
				{
					if (grid[i + k][j + t] == 0 || grid[i + k][j + t]>9)
					{
						flag = 1;
						break;
					}
					s += grid[i + k][j + t];
				}
				if (sum != s || flag == 1)
				{
					continue;
				}

				if (flag == 0)
				{
				
					count++;
				}
			}
		} // for(i)
	} // end of if
	else
	{
		return 0;
	}

	return count;
}

template<class T>
inline vector<int> Algorithm::fairCandySwap(vector<T>& A, vector<T>& B)
{
	int sumA = 0;
	int sumB = 0;
	int flag = 0;
	vector<int> result;

	for (int i = 0; i<A.size(); i++)
	{
		sumA += A[i];
	}

	for (int j = 0; j<B.size(); j++)
	{
		sumB += B[j];
	}

	for (int i = 0; i<A.size(); i++)
	{
		for (int j = 0; j<B.size(); j++)
		{
		
			if (sumA - A[i] + B[j] == sumB - B[j] + A[i])
			{
				result.push_back(A[i]);
				result.push_back(B[j]);
				flag = 1;
				break;
			}
		}

		if (flag == 1)
		{
			break;
		}
	} //for(i)

	return result;
}


template<class T>
inline bool Algorithm::hasGroupsSizeX(vector<T>&deck)                                               //if the size of number is known, so choose the radix sort.
{
	int remainder;
	int k = 1;
	vector<vector<int>> radix;
	radix.resize(10);
	int flag = 1;
	int t = 0;
	while (flag)
	{
		flag = 0;

		for (int i = 0; i<deck.size(); i++)
		{
			if (deck[i] / k)
			{
				flag = 1;
			}
			remainder = (deck[i] / k) % 10;
			radix[remainder].push_back(deck[i]);
		}

		k *= 10;
		t = 0;

		for (int i = 0; i<radix.size(); i++)
		{
			for (int j = 0; j < radix[i].size(); j++)
			{
				deck[t++] = radix[i][j];
			}
			radix[i].clear();
		}
	}//while  基数增序排序

	vector<int> numberCount;
	int count = 0;
	int j;
	int min = 10000;
	if (deck.size() == 1)
	{
		return false;
	}

	for (int i = 0; i<deck.size() - 1;)
	{
		j = i;
		while (deck[i] == deck[i + 1])
		{
			i++;
			if (i == deck.size() - 1)
			{
				break;
			}
		}
		numberCount.push_back(i - j + 1);
		if (i - j + 1<min)
		{
			min = i - j + 1;
		}
		i++;
	}//计数



	if (min == 1)
	{
		return false;
	}
	int i;

	for (i = 0; i < numberCount.size(); )         	//被2整除
	{
		if (numberCount[i] % 2 == 0)
		{
			i++;
		}
		else
		{
			break;
		}
	}
	if (i == numberCount.size())
	{
		return true;
	}


	
	for (i = 0; i < numberCount.size();)      //被3整除
	{
		if (numberCount[i] % 3 == 0)
		{
			i++;
		}
		else
		{
			break;
		}
	}
	if (i == numberCount.size())
	{
		return true;
	}


	for (i = 0; i < numberCount.size();)      //被5整除
	{
		if (numberCount[i] % 5 == 0)
		{
			i++;
		}
		else
		{
			break;
		}
	}
	if (i == numberCount.size())
	{
		return true;
	}





	for (i = 0; i<numberCount.size(); i++)   //被最小的整除
	{
		if (numberCount[i] % min != 0)
		{
			return false;
		}
	}
	if (i == numberCount.size())
	{
		return true;
	}
}