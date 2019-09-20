
#include"DivideMerge.h"

DivideMerge::DivideMerge()
{

}

DivideMerge::~DivideMerge()
{

}

int DivideMerge::findMedian(vector<int>& num, int first, int last)         //������λ��
{

	int k = (first + last) / 2;
	if (first == last)
	{
		cout << num[k] << " ,";
		return num[k];
	}
	else
	{
		int leftNum = findMedian(num, first, k);                             // ������ߵݹ�
		int rightNum = findMedian(num, k + 1, last);                              // ������ұߵݹ�
		return leftNum > rightNum ? rightNum : leftNum;
	}
}



//���������˷�
int DivideMerge::multiplicationOfLargeInteger(int num1, int num2)
{
	//num�д洢���������
	int a, b, c;
	int na = 1;
	int	nb = 1;                //�����趨������һλ����

	if (num1 < 10 && num2<10)
	{
		return num1*num2;
	}
	else
	{
		//���ڵ�������10������򣬶Ե������еݹ黮�֣���һ���򲻻��֣�ֱ�Ӵ��Σ�����
	}
	a = num1 / 10;
	while (a>1)
	{
		na++;                  //��������num1��λ��
		a /= 10;
	}

	b = num2 / 10;
	while (b > 1)
	{
		nb++;
		b /= 10;
	}

	//����Ե�һ�����ֽ��зֽ�,��Ϊ��λ���򲻱ط֣���
	vector<int> divNum;
	int divA = num1 / (10 ^ (na / 2))*(10 ^ (na / 2));
	divNum.push_back(divA);                                   //�洢��һ��������ǰ�벿��
	divNum.push_back(num1 - divA);                            //�洢��һ�������ĺ�벿��

	int divB = num2 / (10 ^ (nb / 2))*(10 ^ (nb / 2));
	divNum.push_back(divB);                                                   //�洢��һ��������ǰ�벿��
	divNum.push_back(num1 - divB);                                            //�洢��һ�������ĺ�벿��

	int result = 0;
	for (int i = 0; i < 2; i++)                                               //���еݹ����
	{
		for (int j = 2; j < 4; j++)
		{
			result += multiplicationOfLargeInteger(divNum[i], divNum[j]);     //ѭ��+�ݹ�
		}
	}
	return result;
}

//���ָ��
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
	//ÿһ�εݹ�ĵ��м��˶���һ������Ҫ���㣬������鲢����ͬ��������������κ��
	int part = divideLR(num, low, high);              //��flag��ʾ��ǰ��ˣ������м�����λ�á�

	if (low<part)
	{
		quickSort(num, low, part - 1);            // ���
	}

	if (high>part)
	{

		quickSort(num, part + 1, high);            // �ַ�

	}

}

int DivideMerge::divideLR(vector<int>&num, int low, int high)
{
	int flag = (low + high) / 2;
	int temp = num[flag];                      //�洢��־λ����

	while (low<high)
	{

		if (num[high]>temp)
		{
			high--;

		}
		else
		{
			if (num[low] > temp)                //������ԭ���ǱȽ�ͣ����
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
			if (num[high] <= temp)                 //����ȣ��򽻻�
			{
				int t = num[low];
				num[low] = num[high];
				num[high] = t;
				if (num[high] == num[low])         //ע���Ƿ���if���棬�������ԭ��
				{
					high--;
				}
			}
		}

	}

	return low;
}


//**********************************************************
//���ڷ��η�˼��ĺϲ�����,�ϲ�����ӷֵ�˼�����Ҳ��Ϊ��������
//�ϲ�����ֱ�ӽ��бȽϲ��룬��QuickSort��ͬ����,�ϲ�������Ҫ�������ҷ֣�Ѱ�ұ�־λ��
//�������ҷֵĽ��ޣ�����־λ������ͨ��������㣬һ��ֱ�Ӵ��м�ֿ���
//���������ͬ���Ǻϲ����ȷֺ��Σ���Ϊ������ҪѰ�ұ�־λ�����Ա������Σ����ϲ���ֱ�Ӹ���low��high���㣬���ɵݹ�������ǳ����á�
void DivideMerge::mergeSort(vector<int>&num, int low, int high)
{
	if (low < high)
	{
		int mid = (low + high) / 2;
		mergeSort(num, low, mid);             //���ϵĵݹ���ȥ���ֵ�ԭ�����������
		mergeSort(num, mid + 1, high);        //���������
		conquer(num, low, mid, high);         //�ξ��ǲ���ϲ���һ������������
	}
}


void DivideMerge::conquer(vector<int>&num, int low, int mid, int high)         //�ξ��ǲ���ϲ���һ������������
{
	int i = low;
	int j = mid + 1;
	vector<int>mergeNum;

	while (i <= mid&&j <= high)              //�εĹ���
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
			cout << str << ":k++ �ĵ�ַԽ��" << endl;
			system("pause");
		}
		low++;
	}
}


//tile problem
void DivideMerge::Tile(int sum, Point point, Point position)
{
	//�����ݹ��ܣ���������ʲô����ʱ���������ú���������ĺ���������,һ����     ,���е�����ȫ�����½ǵ�����
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
		Point leftUpPoint, leftDownPoint, rightUpPoint, rightDownPoint;              //�����ǿյ��������tile�ĵ�
		//ֱ�Ӽ���������Щ���λ�����꣬������tile��Ϊtrue,���Խ�����ĿյĿ���Ϊtrue???
		//point �ǿ�ȱλ�û��������λ��
		//point �ǵ�ǰ�Ŀ�ȱλ�� ��ע�⵱�����ʱ������insert���ָ�
		int quadrant;           //�ֱ�����������ʾ��ȱ��������λ��
		if (point.getX() <= centerPoint.getX())
		{
			if (point.getY() <= centerPoint.getY())
			{
				quadrant = 2;                      //��ȱλ�ڵڶ�����
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
				quadrant = 3;                      //��ȱλ�ڵڶ�����
			}
			else
			{
				quadrant = 4;
			}
		}

		switch (quadrant)
		{
		case 1:{
				   //˵��point�ڵ�һ����
				   rightUpPoint = point;

				   leftUpPoint.setTile(true);
				   leftUpPoint.setX(centerPoint.getX());
				   leftUpPoint.setY(centerPoint.getY());

				   leftDownPoint.setTile(true);             //��������
				   leftDownPoint.setX(centerPoint.getX() + 1);
				   leftDownPoint.setY(centerPoint.getY());

				   rightDownPoint.setTile(true);
				   rightDownPoint.setX(centerPoint.getX() + 1); //��������
				   rightDownPoint.setY(centerPoint.getY() + 1);
		}break;

		case 2:{
				   //˵��point�ڵڶ�����
				   leftUpPoint = point;

				   leftDownPoint.setTile(true);                     //��������
				   leftDownPoint.setX(centerPoint.getX() + 1);
				   leftDownPoint.setY(centerPoint.getY());

				   rightUpPoint.setTile(true);                      //��һ����
				   rightUpPoint.setX(centerPoint.getX());
				   rightUpPoint.setY(centerPoint.getY() + 1);

				   rightDownPoint.setTile(true);
				   rightDownPoint.setX(centerPoint.getX() + 1);      //��������
				   rightDownPoint.setY(centerPoint.getY() + 1);
		}break;

		case 3:{
				   leftDownPoint = point;

				   leftUpPoint.setTile(true);
				   leftUpPoint.setX(centerPoint.getX());
				   leftUpPoint.setY(centerPoint.getY());

				   rightUpPoint.setTile(true);              //��һ����
				   rightUpPoint.setX(centerPoint.getX());
				   rightUpPoint.setY(centerPoint.getY() + 1);

				   rightDownPoint.setTile(true);
				   rightDownPoint.setX(centerPoint.getX() + 1); //��������
				   rightDownPoint.setY(centerPoint.getY() + 1);
		}break;

		case 4:{
				   rightDownPoint = point;

				   leftUpPoint.setTile(true);
				   leftUpPoint.setX(centerPoint.getX());
				   leftUpPoint.setY(centerPoint.getY());

				   leftDownPoint.setTile(true);
				   leftDownPoint.setX(centerPoint.getX() + 1); //��3����
				   leftDownPoint.setY(centerPoint.getY());

				   rightUpPoint.setTile(true);              //��һ����
				   rightUpPoint.setX(centerPoint.getX());
				   rightUpPoint.setY(centerPoint.getY() + 1);


		}break;
		}

		Tile(sum / 4, leftUpPoint, leftUpPosition);                     //����
		Tile(sum / 4, leftDownPoint, leftDownPosition);                     //����

		Tile(sum / 4, rightUpPoint, rightUpPosition);                     //����
		Tile(sum / 4, rightDownPoint, rightDownPosition);                     //����

	}
	else if (sqrt(sum) == 2)                                                  //if(sqrt(n)==2),˵��ֻ����һ��λ�ÿ���tile
	{

		//ֱ�ӽ�δtile�ĵ�tile
		//position�϶������½ǣ���point���ǿյ����������
		//��ʣ�µ����4��ȫ�����

		quardPoint[point.getX()][point.getY()] = point;

		/*
		Point leftUpPoint, leftDownPoint, rightUpPoint, rightDownPoint;
		leftUpPoint.setTile(true);
		leftUpPoint.setX(position.getX() - 1);
		leftUpPoint.setY(position.getY() - 1);
		quardPoint[leftUpPoint.getX()][leftUpPoint.getY()] = leftUpPoint;      //�����϶�����и�ֵ

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

vector<vector<Point>> DivideMerge::TileBoard(int n, int m, Point point)            //pointΪ��ʼ��ȱ��
{
	//������һ��,��ֵ��ʼ��
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
	position.setY(m);                           //���½ǵĶ�������

	int sum = n*m;
	Tile(sum, point, position);                 //���õݹ麯��  Tile(int n, Point point, Point position)

	quardPoint[point.getX()][point.getY()].setTile(false);
	return quardPoint;
}


int DivideMerge::countInversions(vector<int>&nums, int low, int high)
{
	int countLeftRight, countMid;
	if (low < high)
	{

		int mid = (low + high) / 2;                     //�м��
		countLeftRight = countInversions(nums, low, mid) + countInversions(nums, mid + 1, high);  //���Ҹ����ߵķ�ת��

		countMid = CountMergeSort(nums, low, mid, high);                                    //���������ұߵķ�ת��

		return countLeftRight + countMid;                 //�����ܺ�
	}
	else                                                  //���low==high����ô��ֻ��һ���������Բ���Ҫ�Ƚϣ���û�з�ת�������Է���0
	{
		return 0;
	}
}

int DivideMerge::CountMergeSort(vector<int>&nums, int low, int mid, int high)
{
	/**
	   ͨ���ϲ��������Ƚ��������ߵ�sorted������Ϊ�����ߵĵ�һ�������ұߵ���������ߵĺ��������һ�����ұߵĵĵ�һ����������ߵ����Ͳ����ٱȽ��ˣ������������˱Ƚϴ�����
	   */
	int i = low;                       //��ʾ��ߵ���
	int j = mid + 1;                     //��ʾ�ұߵ���
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
	pointMergeSort(num, 0, num.size() - 1, 0);                   //��X�������ִ洢

	//*****************��־������**************************************
	return shortestPointMergeSort(num, 0, num.size() - 1);       //������̶���ľ���
}


//*********************��X����****************************************
void DivideMerge::pointMergeSort(vector<Point>&num, int low, int high, int flag)         //�ȶ�һ�Ѷ������������
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
	int j = mid + 1;                               //��ע�������mid+1��ʼ
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
	int j = mid + 1;                               //��ע�������mid+1��ʼ
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
double DivideMerge::shortestPointMergeSort(vector<Point>&num, int low, int high)    //�ȶԶ�����зָ�
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
			if (d < 0)                                             //˵��һ��ֻ��һ���㣬����һ���ж���㣬�򽫷Ǹ�����ֵ��d 
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

			centerShortest = shortestCenterPointConquer(num, low, mid, high, d);              //�������Ҷ�������̵�d,���������м䶥���d
			return centerShortest < d ? centerShortest : d;                                   //ֱ�Ӽ�������н�С��һ������
		}

	}
	else        //���ֻ��һ�����㣬�򲻱ؽ������ҷ֣��򷵻�-1
	{
		return -1.0;
	}
}

double DivideMerge::shortestCenterPointConquer(vector<Point>&num, int low, int mid, int high, double d)      //����ߵĶ�����еݹ鵽ֻʣ����������ʱ�����о������
{
	double centerdd;
	vector<Point>centerPoint;
	double cdL = num[mid].getX();
	double cdR = num[mid + 1].getX();
	double centerLine = (cdL + cdR) / 2.0;                  //��׼����

	for (int i = low; i <= high; i++)
	{
		if (abs(num[i].getX() - centerLine) <= d)
		{
			centerPoint.push_back(num[i]);
		}
	}
	pointMergeSort(centerPoint, 0, centerPoint.size() - 1, 1);                         //�������ڵĵ�洢��һ������������ڶ������ڵ���������Y�������   
	//-------------����Y����������ȷ��---------------------------------
	double dd = 2 * d;
	double len = 0;
	for (int i = 0; i < centerPoint.size(); i++)                                      //��ע�������ǰ���Y�����е�
	{
		if (centerPoint[i].getX() >= centerLine)
		{
			int j = i - 3;         //j�ӵ�ǰi����3���㿪ʼ����i-3<0ʱ��Ӧ����j��0��ʼ����������Խ�硣
			if (j < 0)j = 0;
			for (j; j <= i + 3 && j < centerPoint.size(); j++)                             			    //��3��3������//��ע����forѭ���У����ĳ�β�����ѭ����������ֱ������ѭ����ֻ������ѭ�����Ż�ִ�к����j++,����������������ѭ����������Ҫ����forѭ������
			{
				if (j == i)continue;

				if (centerPoint[j].getX() <= centerLine)                                          //�뵱ǰ�ȶԵ��෴
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
	}//����forѭ���󣬵õ��м������̵ľ���dd 
	centerdd = d < dd ? d : dd;                                                                  //�������ߺ��м�֮���С�ģ�������
	return centerdd;
}

/*****************************************************
������numA��numB
����ʽ�ָ�ݹ���ˣ���������4�����
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
		numZ = polynomialsMultiply(numA, midA + 1, highA, numB, midB + 1, highB);                  //һ������һ��Ϊ׼

		int dxyz;
		numXYZ = crossAdd(numXY, 0, dxy, numZ, highA, highB,dxyz);
	
	}
	else if (lowA<highA)
	{
		int midA = (highA + lowA) / 2;
		numX = polynomialsMultiply(numA, lowA, midA, numB, lowB, highB);                          //ֻ��һ���Ͳ��ý���
		numZ = polynomialsMultiply(numA, midA + 1, highA, numB, lowB, highB);

		int dxz;
		numXYZ = crossAdd(numX, midA, highB, numZ, highA, highB,dxz);
	}
	else if (lowB < highB)
	{
		int midB = (lowB+highB) / 2;
		numX = polynomialsMultiply(numA, lowA, highA, numB, lowB, midB);                          //ֻ��һ���Ͳ��ý���
		numZ = polynomialsMultiply(numA, lowA, highA, numB, midB+1, highB);

		int dxz;
		numXYZ = crossAdd(numX, highA, midB, numZ, highA, highB,dxz);
	}
	else
	{
		numXYZ.push_back(numA[lowA] * numB[lowB]);                                                 //���õ�����������ص���һ��void����
	}

	return numXYZ;
}

std::vector<double> DivideMerge::crossAdd(vector<double> &numa, int midA, int highB, vector<double>&numb, int highA, int midB,int &d)  //�����int���͵Ĳ���������ߴ���
{
	vector<double> numc;
	int i = 0;
	int j = 0;
	int na = midA + highB;                             //numa������ݴ� 2
	int nb = highA + midB;                             //numb������ݴ� 3
	int diffA = na - numa.size() + 1;
	int diffB = nb - numb.size() + 1;
	int flag = 0;                                     //��Ⱦ�Ϊ0

	d = na > nb ? na : nb;                            //ԭ�򣺷�����ߴ���

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
					   if (i < numa.size() && j < numb.size())                  //���뻹�������⣬û�ж���
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
