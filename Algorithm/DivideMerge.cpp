
#include"DivideMerge.h"

DivideMerge::DivideMerge()
{

}

DivideMerge::~DivideMerge()
{

}

int DivideMerge::findMedian(vector<int>& num, int first, int last)         //计算中位数
{

	int k = (first + last) / 2;
	if (first == last)
	{
		cout << num[k] << " ,";
		return num[k];
	}
	else
	{
		int leftNum = findMedian(num, first, k);                             // 想求左边递归
		int rightNum = findMedian(num, k + 1, last);                              // 想计算右边递归
		return leftNum > rightNum ? rightNum : leftNum;
	}
}



//求解大整数乘法
int DivideMerge::multiplicationOfLargeInteger(int num1, int num2)
{
	//num中存储多个大整数
	int a, b, c;
	int na = 1;
	int	nb = 1;                //这里设定至少有一位整数

	if (num1 < 10 && num2<10)
	{
		return num1*num2;
	}
	else
	{
		//对于单个大于10的情况则，对单个进行递归划分，另一个则不划分，直接传参？？？
	}
	a = num1 / 10;
	while (a>1)
	{
		na++;                  //计算整数num1的位数
		a /= 10;
	}

	b = num2 / 10;
	while (b > 1)
	{
		nb++;
		b /= 10;
	}

	//下面对第一个数字进行分解,若为各位，则不必分？？
	vector<int> divNum;
	int divA = num1 / (10 ^ (na / 2))*(10 ^ (na / 2));
	divNum.push_back(divA);                                   //存储第一个整数的前半部分
	divNum.push_back(num1 - divA);                            //存储第一个整数的后半部分

	int divB = num2 / (10 ^ (nb / 2))*(10 ^ (nb / 2));
	divNum.push_back(divB);                                                   //存储第一个整数的前半部分
	divNum.push_back(num1 - divB);                                            //存储第一个整数的后半部分

	int result = 0;
	for (int i = 0; i < 2; i++)                                               //进行递归调用
	{
		for (int j = 2; j < 4; j++)
		{
			result += multiplicationOfLargeInteger(divNum[i], divNum[j]);     //循环+递归
		}
	}
	return result;
}

//求解指数
double DivideMerge::pow(double x, int n)
{
	double result;
	double temp;
	if (n > 1)
	{
		temp = pow(x, n / 2);
		if (n % 2 != 0)
		{
			return temp*temp*x;
		}
		else
		{
			return temp*temp;
		}
	}
	else
	{
		return x;
	}
}



void DivideMerge::quickSort(vector<int> &num, int low, int high)
{
	//每一次递归的的中间标杆都不一样，需要计算，这里与归并排序不同的是这里采用先治后分
	int part = divideLR(num, low, high);              //治flag表示当前标杆，返回中间数字位置。

	if (low<part)
	{
		quickSort(num, low, part - 1);            // 左分
	}

	if (high>part)
	{

		quickSort(num, part + 1, high);            // 又分

	}

}

int DivideMerge::divideLR(vector<int>&num, int low, int high)
{
	int flag = (low + high) / 2;
	int temp = num[flag];                      //存储标志位数据

	while (low<high)
	{

		if (num[high]>temp)
		{
			high--;

		}
		else
		{
			if (num[low] > temp)                //交换的原则是比较停下来
			{
				int t = num[low];
				num[low] = num[high];
				num[high] = t;
			}
		}

		if (num[low] < temp)
		{
			low++;

		}
		else
		{
			if (num[high] <= temp)                 //若相等，则交换
			{
				int t = num[low];
				num[low] = num[high];
				num[high] = t;
				if (num[high] == num[low])         //注意是放在if里面，三者相等原则
				{
					high--;
				}
			}
		}

	}

	return low;
}


//**********************************************************
//基于分治法思想的合并排序,合并排序从分的思想出发也分为左右两边
//合并排序直接进行比较插入，与QuickSort不同的是,合并排序不需要进行左右分，寻找标志位，
//所以左右分的界限（即标志位）可以通过任意计算，一般直接从中间分开。
//与快速排序不同的是合并是先分后治，因为快排需要寻找标志位，所以必须先治；而合并可直接根据low和high计算，且由递归由深至浅排序好。
void DivideMerge::mergeSort(vector<int>&num, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergeSort(num, low, mid);             //不断的递归下去，分到原子左已排序好
		mergeSort(num, mid + 1, high);        //右已排序好
		conquer(num, low, mid, high);         //治就是插入合并到一个数组中排序
	}
}


void DivideMerge::conquer(vector<int>&num, int low, int mid, int high)         //治就是插入合并到一个数组中排序
{
	int i = low;
	int j = mid + 1;
	vector<int>mergeNum;

	while (i <= mid&&j <= high)              //治的过程
	{

		if (num[i] <= num[j])
		{
			mergeNum.push_back(num[i]);
			i++;
		}
		else
		{
			mergeNum.push_back(num[j]);
			j++;
		}
	}

	while (i <= mid)
	{
		mergeNum.push_back(num[i]);
		i++;
	}

	while (j <= high)
	{
		mergeNum.push_back(num[j]);
		j++;
	}

	int k = 0;
	while (low <= high)
	{
		try
		{
			if (k >= mergeNum.size())
			{
				throw "index out";
			}
			num[low] = mergeNum[k++];
		}
		catch (char *str)
		{
			cout << str << ":k++ 的地址越界" << endl;
			system("pause");
		}
		low++;
	}
}


//tile problem
void DivideMerge::Tile(int sum, Point point, Point position)
{
	//基本递归框架，即在满足什么条件时，继续调用函数，这里的函数不限制,一分四     ,所有的坐标全是右下角的坐标
	//point.setTile(true);
	if (sqrt(sum) > 2)
	{
		int len = sqrt(sum);
		int t = len / 2;
		Point leftUpPosition, leftDownPosition, rightUpPosition, rightDownPosition;
		Point centerPoint;
		centerPoint.setX(position.getX() - t);
		centerPoint.setY(position.getY() - t);

		leftUpPosition.setX(position.getX() - t);
		leftUpPosition.setY(position.getY() - t);

		leftDownPosition.setX(position.getX());
		leftDownPosition.setY(position.getY() - t);

		rightUpPosition.setX(position.getX() - t);
		rightUpPosition.setY(position.getY());

		rightDownPosition.setX(position.getX());
		rightDownPosition.setY(position.getY());

		//****************************************************************
		Point leftUpPoint, leftDownPoint, rightUpPoint, rightDownPoint;              //这里是空点或者已贴tile的点
		//直接计算以上这些点的位置坐标，并将其tile改为true,可以将最初的空的看作为true???
		//point 是空缺位置或者已填充位置
		//point 是当前的空缺位置 ，注意当光标变宽时，按下insert键恢复
		int quadrant;           //分别用象限来表示空缺点和填充点的位置
		if (point.getX() <= centerPoint.getX())
		{
			if (point.getY() <= centerPoint.getY())
			{
				quadrant = 2;                      //空缺位在第二象限
			}
			else
			{
				quadrant = 1;
			}
		}
		else
		{
			if (point.getY() <= centerPoint.getY())
			{
				quadrant = 3;                      //空缺位在第二象限
			}
			else
			{
				quadrant = 4;
			}
		}

		switch (quadrant)
		{
		case 1:{
				   //说明point在第一象限
				   rightUpPoint = point;

				   leftUpPoint.setTile(true);
				   leftUpPoint.setX(centerPoint.getX());
				   leftUpPoint.setY(centerPoint.getY());

				   leftDownPoint.setTile(true);             //第三象限
				   leftDownPoint.setX(centerPoint.getX() + 1);
				   leftDownPoint.setY(centerPoint.getY());

				   rightDownPoint.setTile(true);
				   rightDownPoint.setX(centerPoint.getX() + 1); //第四象限
				   rightDownPoint.setY(centerPoint.getY() + 1);
		}break;

		case 2:{
				   //说明point在第二象限
				   leftUpPoint = point;

				   leftDownPoint.setTile(true);                     //第三象限
				   leftDownPoint.setX(centerPoint.getX() + 1);
				   leftDownPoint.setY(centerPoint.getY());

				   rightUpPoint.setTile(true);                      //第一象限
				   rightUpPoint.setX(centerPoint.getX());
				   rightUpPoint.setY(centerPoint.getY() + 1);

				   rightDownPoint.setTile(true);
				   rightDownPoint.setX(centerPoint.getX() + 1);      //第四象限
				   rightDownPoint.setY(centerPoint.getY() + 1);
		}break;

		case 3:{
				   leftDownPoint = point;

				   leftUpPoint.setTile(true);
				   leftUpPoint.setX(centerPoint.getX());
				   leftUpPoint.setY(centerPoint.getY());

				   rightUpPoint.setTile(true);              //第一象限
				   rightUpPoint.setX(centerPoint.getX());
				   rightUpPoint.setY(centerPoint.getY() + 1);

				   rightDownPoint.setTile(true);
				   rightDownPoint.setX(centerPoint.getX() + 1); //第四象限
				   rightDownPoint.setY(centerPoint.getY() + 1);
		}break;

		case 4:{
				   rightDownPoint = point;

				   leftUpPoint.setTile(true);
				   leftUpPoint.setX(centerPoint.getX());
				   leftUpPoint.setY(centerPoint.getY());

				   leftDownPoint.setTile(true);
				   leftDownPoint.setX(centerPoint.getX() + 1); //第3象限
				   leftDownPoint.setY(centerPoint.getY());

				   rightUpPoint.setTile(true);              //第一象限
				   rightUpPoint.setX(centerPoint.getX());
				   rightUpPoint.setY(centerPoint.getY() + 1);


		}break;
		}

		Tile(sum / 4, leftUpPoint, leftUpPosition);                     //左上
		Tile(sum / 4, leftDownPoint, leftDownPosition);                     //左下

		Tile(sum / 4, rightUpPoint, rightUpPosition);                     //右上
		Tile(sum / 4, rightDownPoint, rightDownPosition);                     //右下

	}
	else if (sqrt(sum) == 2)                                                  //if(sqrt(n)==2),说明只存在一个位置可以tile
	{

		//直接将未tile的点tile
		//position肯定是右下角，而point则是空点或者已填充点
		//将剩下的最后4个全部填充

		quardPoint[point.getX()][point.getY()] = point;

		/*
		Point leftUpPoint, leftDownPoint, rightUpPoint, rightDownPoint;
		leftUpPoint.setTile(true);
		leftUpPoint.setX(position.getX() - 1);
		leftUpPoint.setY(position.getY() - 1);
		quardPoint[leftUpPoint.getX()][leftUpPoint.getY()] = leftUpPoint;      //对左上顶点进行赋值

		leftDownPoint.setTile(true);
		leftDownPoint.setX(position.getX() - 1);
		leftDownPoint.setY(position.getY());
		quardPoint[leftDownPoint.getX()][leftDownPoint.getY()] = leftDownPoint;

		rightUpPoint.setTile(true);
		rightUpPoint.setX(position.getX());
		rightUpPoint.setY(position.getY() - 1);
		quardPoint[rightUpPoint.getX()][rightUpPoint.getY()] = rightUpPoint;

		rightDownPoint.setTile(true);
		rightDownPoint.setX(position.getX());
		rightDownPoint.setY(position.getY());
		quardPoint[rightDownPoint.getX()][rightDownPoint.getY()] = rightDownPoint;
		*/
	}//else if
}

vector<vector<Point>> DivideMerge::TileBoard(int n, int m, Point point)            //point为初始空缺点
{
	//可以用一个,点值初始化
	quardPoint.resize(n + 1);
	for (int i = 0; i <= n; i++)
	{
		quardPoint[i].resize(m + 1);
	}
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= m; j++)
		{
			quardPoint[i][j] = *new Point();
			quardPoint[i][j].setTile(false);
			quardPoint[i][j].setX(i);
			quardPoint[i][j].setY(j);
		}
	}

	Point position;
	position.setX(n);
	position.setY(m);                           //右下角的顶点坐标

	int sum = n*m;
	Tile(sum, point, position);                 //调用递归函数  Tile(int n, Point point, Point position)

	quardPoint[point.getX()][point.getY()].setTile(false);
	return quardPoint;
}


int DivideMerge::countInversions(vector<int>&nums, int low, int high)
{
	int countLeftRight, countMid;
	if (low < high)
	{

		int mid = (low + high) / 2;                     //中间分
		countLeftRight = countInversions(nums, low, mid) + countInversions(nums, mid + 1, high);  //左右各两边的翻转数

		countMid = CountMergeSort(nums, low, mid, high);                                    //左边相比于右边的翻转数

		return countLeftRight + countMid;                 //返回总和
	}
	else                                                  //如果low==high，那么就只有一个数，所以不需要比较，则没有翻转数，所以返回0
	{
		return 0;
	}
}

int DivideMerge::CountMergeSort(vector<int>&nums, int low, int mid, int high)
{
	/**
	   通过合并排序来比较左右两边的sorted数，因为如果左边的第一个数比右边的数大，则左边的后面的数就一定比右边的的第一个数大，则左边的数就不用再比较了，这样大大减少了比较次数。
	   */
	int i = low;                       //表示左边的数
	int j = mid + 1;                     //表示右边的数
	vector<int>mergeNum;
	int count = 0;
	while (i <= mid&&j <= high)
	{
		if (nums[i] > nums[j])
		{
			mergeNum.push_back(nums[j]);
			count += mid - i + 1;
			j++;
		}
		else
		{
			mergeNum.push_back(nums[i]);
			i++;
		}
	}

	while (i <= mid)
	{
		mergeNum.push_back(nums[i]);
		i++;
	}

	while (j <= high)
	{
		mergeNum.push_back(nums[j]);
		j++;
	}

	for (int i = 0; i < mergeNum.size() && low <= high; i++)
	{
		nums[low] = mergeNum[i];
		low++;
	}

	return count;
}

//----------------------------------------------------------------------

double DivideMerge::ClosedShortestPoint(vector<Point>&num)
{
	pointMergeSort(num, 0, num.size() - 1, 0);                   //按X轴排序点分存储

	//*****************点分距离计算**************************************
	return shortestPointMergeSort(num, 0, num.size() - 1);       //返回最短顶点的距离
}


//*********************沿X排序****************************************
void DivideMerge::pointMergeSort(vector<Point>&num, int low, int high, int flag)         //先对一堆顶点进行排序存放
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		pointMergeSort(num, low, mid, flag);
		pointMergeSort(num, mid + 1, high, flag);

		if (flag)
		{
			pointYConquer(num, low, mid, high);
		}
		else
		{
			pointXConquer(num, low, mid, high);
		}

	}
}

void DivideMerge::pointXConquer(vector<Point>&num, int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;                               //特注：这里从mid+1开始
	vector<Point> sortedNum;
	while (i <= mid&&j <= high)
	{
		if (num[i].getX() < num[j].getX())
		{
			sortedNum.push_back(num[i]);
			i++;
		}
		else
		{
			sortedNum.push_back(num[j]);
			j++;
		}
	}

	while (i <= mid)
	{
		sortedNum.push_back(num[i]);
		i++;
	}
	while (j <= high)
	{
		sortedNum.push_back(num[j]);
		j++;
	}

	for (int i = 0; i < sortedNum.size() && low <= high; i++)
	{
		num[low] = sortedNum[i];
		low++;
	}
}
//*********************************************************************
void DivideMerge::pointYConquer(vector<Point>&num, int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;                               //特注：这里从mid+1开始
	vector<Point> sortedNum;
	while (i <= mid&&j <= high)
	{
		if (num[i].getY() < num[j].getY())
		{
			sortedNum.push_back(num[i]);
			i++;
		}
		else
		{
			sortedNum.push_back(num[j]);
			j++;
		}
	}

	while (i <= mid)
	{
		sortedNum.push_back(num[i]);
		i++;
	}
	while (j <= high)
	{
		sortedNum.push_back(num[j]);
		j++;
	}

	for (int i = 0; i < sortedNum.size() && low <= high; i++)
	{
		num[low] = sortedNum[i];
		low++;
	}
}

//***********************************************************************************
double DivideMerge::shortestPointMergeSort(vector<Point>&num, int low, int high)    //先对顶点进行分割
{
	double leftShortest, rightShortest, centerShortest, d;
	if (low < high)
	{
		int mid = (low + high) / 2;
		leftShortest = shortestPointMergeSort(num, low, mid);
		rightShortest = shortestPointMergeSort(num, mid + 1, high);

		if (leftShortest < 0 && rightShortest < 0)
		{
			d = sqrt(pow((num[low].getX() - num[high].getX()), 2) + pow((num[low].getY() - num[high].getY()), 2));
			cout << endl << num[low].getX() << " , " << num[high].getX() << "  d= " << d << endl;
			return d;
		}
		else
		{
			d = leftShortest < rightShortest ? leftShortest : rightShortest;
			if (d < 0)                                             //说明一边只有一个点，而另一边有多个点，则将非负数赋值给d 
			{
				if (leftShortest < 0)
				{
					d = rightShortest;
				}
				else
				{
					d = leftShortest;
				}
			}//if(d<0)

			centerShortest = shortestCenterPointConquer(num, low, mid, high, d);              //根据左右顶点中最短的d,再来计算中间顶点的d
			return centerShortest < d ? centerShortest : d;                                   //直接计算二者中较小的一个顶点
		}

	}
	else        //如果只有一个顶点，则不必进行左右分，则返回-1
	{
		return -1.0;
	}
}

double DivideMerge::shortestCenterPointConquer(vector<Point>&num, int low, int mid, int high, double d)      //对左边的顶点进行递归到只剩下两个顶点时，进行距离求解
{
	double centerdd;
	vector<Point>centerPoint;
	double cdL = num[mid].getX();
	double cdR = num[mid + 1].getX();
	double centerLine = (cdL + cdR) / 2.0;                  //标准中线

	for (int i = low; i <= high; i++)
	{
		if (abs(num[i].getX() - centerLine) <= d)
		{
			centerPoint.push_back(num[i]);
		}
	}
	pointMergeSort(centerPoint, 0, centerPoint.size() - 1, 1);                         //将区域内的点存储在一个向量里，下面在对区域内地向量进行Y轴的排序   
	//-------------至此Y轴排序是正确的---------------------------------
	double dd = 2 * d;
	double len = 0;
	for (int i = 0; i < centerPoint.size(); i++)                                      //特注：下面是按照Y来排列的
	{
		if (centerPoint[i].getX() >= centerLine)
		{
			int j = i - 3;         //j从当前i的下3个点开始，当i-3<0时，应该让j从0开始，否则，数组越界。
			if (j < 0)j = 0;
			for (j; j <= i + 3 && j < centerPoint.size(); j++)                             			    //上3下3个顶点//特注：在for循环中，如果某次不满足循环条件，则直接跳出循环，只有满足循环，才会执行后面的j++,所以有其他不满足循环的条件，要放在for循环里面
			{
				if (j == i)continue;

				if (centerPoint[j].getX() <= centerLine)                                          //与当前比对点相反
				{
					len = sqrt(pow((centerPoint[i].getX() - centerPoint[j].getX()), 2) + pow((centerPoint[i].getY() - centerPoint[j].getY()), 2));
					cout << centerPoint[i].getX() << "  ,  " << centerPoint[j].getX() << "   ";
					cout << "len =  " << len << endl;

					if (len < dd)
					{
						dd = len;
					}
				}
			}//for(j)
		}
	}//经过for循环后，得到中间点中最短的距离dd 
	centerdd = d < dd ? d : dd;                                                                  //计算两边和中间之间较小的，并返回
	return centerdd;
}

/*****************************************************
参数：numA，numB
多项式分割递归相乘，这里先做4次相乘
******************************************************/
vector<double> DivideMerge::polynomialsMultiply(vector<double>&numA, int lowA, int highA, vector<double>&numB, int lowB, int highB)
{

	vector<double>numXY,numXYZ;
	vector<double>numX, numY, numZ;                                                            //numX==A0B0, numY=A1B1,numZ=(A0B0+A1B1)

	if (lowA < highA && lowB<highB)
	{
		int midA = (highA + lowA) / 2;
		int midB = (highB + lowB) / 2;

		numX = polynomialsMultiply(numA, lowA, midA, numB, lowB, midB);

		vector<double> numa, numb;
		int dy;
		numa = polynomialsMultiply(numA, lowA, midA, numB, midB + 1, highB);
		numb = polynomialsMultiply(numA, midA + 1, highA, numB, lowB, midB);
		numY = crossAdd(numa, midA, highB, numb, highA, midB,dy);

		int dxy;
		numXY = crossAdd(numX, midA, midB, numY, 0, dy, dxy);
		numZ = polynomialsMultiply(numA, midA + 1, highA, numB, midB + 1, highB);                  //一切以上一个为准

		int dxyz;
		numXYZ = crossAdd(numXY, 0, dxy, numZ, highA, highB,dxyz);
	
	}
	else if (lowA<highA)
	{
		int midA = (highA + lowA) / 2;
		numX = polynomialsMultiply(numA, lowA, midA, numB, lowB, highB);                          //只有一个就不用交叉
		numZ = polynomialsMultiply(numA, midA + 1, highA, numB, lowB, highB);

		int dxz;
		numXYZ = crossAdd(numX, midA, highB, numZ, highA, highB,dxz);
	}
	else if (lowB < highB)
	{
		int midB = (lowB+highB) / 2;
		numX = polynomialsMultiply(numA, lowA, highA, numB, lowB, midB);                          //只有一个就不用交叉
		numZ = polynomialsMultiply(numA, lowA, highA, numB, midB+1, highB);

		int dxz;
		numXYZ = crossAdd(numX, highA, midB, numZ, highA, highB,dxz);
	}
	else
	{
		numXYZ.push_back(numA[lowA] * numB[lowB]);                                                 //调用的这个函数返回的是一个void类型
	}

	return numXYZ;
}

std::vector<double> DivideMerge::crossAdd(vector<double> &numa, int midA, int highB, vector<double>&numb, int highA, int midB,int &d)  //这里的int类型的参数都是最高次幂
{
	vector<double> numc;
	int i = 0;
	int j = 0;
	int na = midA + highB;                             //numa的最高幂次 2
	int nb = highA + midB;                             //numb的最高幂次 3
	int diffA = na - numa.size() + 1;
	int diffB = nb - numb.size() + 1;
	int flag = 0;                                     //相等就为0

	d = na > nb ? na : nb;                            //原则：返回最高次幂

	if (diffA > diffB)
	{
		flag = 1;
	}
	else if (diffA < diffB)
	{
		flag = 2;
	}

	while (i < numa.size() || j < numb.size())
	{
		switch (flag)
		{
			case 0:{
					   if (i < numa.size() && j < numb.size())                  //对齐还是有问题，没有对齐
					   {
							numc.push_back(numa[i] + numb[j]);
							i++;
							j++;
					   }
					   else if (i<numa.size())
					   {
						   numc.push_back(numa[i]);
						   i++;
					   }
					   else
					   {
						   numc.push_back(numb[j]);
						   j++;
					   }
					  
			}continue;

			case 1:{
					   if (j < diffA - diffB)
					   {
						   numc.push_back(numb[j]);
						   j++;
					   }
					   else if (j < numb.size())
					   {
						   numc.push_back(numa[i] + numb[j]);
						   i++;
						   j++;
					   }
					   else
					   {
						   numc.push_back(numa[i]);
						   i++;
					   }

			}continue;

			default:{

						if (i < diffB - diffA)
						{
							numc.push_back(numa[i]);
							i++;
						}
						else if (i<numa.size())
						{
							numc.push_back(numa[i] + numb[j]);
							i++;
							j++;
						}
						else
						{
							numc.push_back(numb[j]);
							j++;
						}
			}continue;
		}//switch
	}//while

	return numc;
}
