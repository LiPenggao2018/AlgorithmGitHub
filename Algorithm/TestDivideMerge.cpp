
#include"TestDivideMerge.h"
TestDivideMerge::TestDivideMerge()
{
	
}

TestDivideMerge::~TestDivideMerge()
{
}

int TestDivideMerge::testFindMedian()						//��Ϊ���η����кܶ�����Ӧ���㷨
{
	//��������д�������ݽ��в���

	vector<int> num;
	num = { 10, 5, 7, 6, 8, 23, 4, 9 };
	DivideMerge *testDivide = new DivideMerge();        //�����ʼ��
	int min;
	//for (int i = 0; i < num.size() / 2; i++)
	//{
		min = testDivide->findMedian(num, 0, num.size() - 1);
		cout << min;
	//}
	return min;
}

int TestDivideMerge::testFindMedian(vector<int>& num)
{
	//��������testFindMedian����



	return num.size();
}

int TestDivideMerge::testPow()              //���η�����pow
{
	int x = 3;
	int n = 5;
	return pow(3, 5);
}


void TestDivideMerge::testQuickSort()
{
	vector<int> num;
	num = {0,1,-3,0,1,1};
	
	DivideMerge *testDivide = new DivideMerge();        //�����ʼ��
	testDivide->quickSort(num, 0, num.size() - 1);
	
	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << ",";
	}
}

void TestDivideMerge::testMergeSort()                   //���ڷ���˼��ĺϲ�����
{
	vector<int>num;
	num = { 5,8,5,6,7,5,1,1,0,1,0,1,1,0,3,3,-4,34,5,4,5 };
	DivideMerge *testDivide = new DivideMerge();        //�����ʼ��
	testDivide->mergeSort(num, 0, num.size() - 1);

	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i] << ",";
	}
}

void TestDivideMerge::testTileBoard()                   //ͨ�����η���������ذ�
{
	DivideMerge *testDivide = new DivideMerge();        //�����ʼ��
	int n = 16;
	int m = 16;
	Point point;
	point.setTile(true);                                //����ȱ��λ������Ϊtrue���ȼ����������񣬱�ʾ����Ҫ��������Ҫ��ס�����ǿ�ȱ��
	point.setX(2);
	point.setY(3);
	cout << 2 << "  " << 3 << endl;
	vector<vector<Point>> quardPoint = testDivide->TileBoard(n, m, point);

	for (int i = 1; i < quardPoint.size(); i++)
	{
		for (int j = 1; j < quardPoint[i].size(); j++)
		{
			if (quardPoint[i][j].getTile())
			{
				cout << " @ ";
			}
			else
			{
				if(quardPoint[i][j].getX() == point.getX() && quardPoint[i][j].getY() == point.getY())
				{
					cout << "   ";
				}
				else cout <<" * ";
			}
		}
		cout << endl;
	}

}


void TestDivideMerge::testCountInversions()
{
	vector<int>num;
	num = { 32,4,5,1,7,8,42};
	DivideMerge *testDivide = new DivideMerge();        //�����ʼ��
	cout<<testDivide->countInversions(num, 0, num.size() - 1);
}

void TestDivideMerge::testPointMergeSort()             //���Զ�������
{
	vector<Point>num;
	Point p1, p2, p3, p4, p5, p6;
	p1.setX(4);
	p1.setY(5);
	num.push_back(p1);

	p2.setX(-2);
	p2.setY(6);
	num.push_back(p2);


	
	p3.setX(1);
	p3.setY(3);
	num.push_back(p3);

	p4.setX(2);
	p4.setY(1);
	num.push_back(p4);

	p5.setX(-4);
	p5.setY(1);
	num.push_back(p5);

	p6.setX(-7);
	p6.setY(9);
	num.push_back(p6);

	DivideMerge *testDivide = new DivideMerge();        //�����ʼ��
	testDivide->pointMergeSort(num, 0, num.size() - 1,0);
	for (int i = 0; i < num.size(); i++)
	{
		cout << num[i].getX()<<",";
	}
}

void TestDivideMerge::testClosedShortestPoint()         //����ƽ���ϵ�����������ľ���
{
	vector<Point>num;
	Point p1, p2, p3, p4, p5, p6;
	p1.setX(2);
	p1.setY(3);
	num.push_back(p1);

	p2.setX(12);
	p2.setY(30);
	num.push_back(p2);

	p3.setX(40);
	p3.setY(50);
	num.push_back(p3);

	p4.setX(5);
	p4.setY(1);
	num.push_back(p4);
	
	p5.setX(12);
	p5.setY(10);
	num.push_back(p5);
	
	p6.setX(3);
	p6.setY(4);
	num.push_back(p6);
	
	DivideMerge *testDivide = new DivideMerge();        //�����ʼ��
    double dd = -1;
	dd = testDivide->ClosedShortestPoint(num);
	cout << "��̾���Ϊ" << dd << endl;        
}

//*************************************************
void TestDivideMerge::testPolynomialsMultiply()
{
	vector<double>numA, numB, numC;
	numA = { 2,3,1,2,3,3,7};
	numB = { 1,2};
	DivideMerge *testDivide = new DivideMerge();    
	
	cout << "F(x) = ";
	for (int i = 0; i < numA.size();)
	{
		cout << numA[i];
		if (i != 0)
		{
			cout<<"x^" << i;
		}
		i++;
		if (i != numA.size())
		{
			cout << " + ";
		}
	}
	cout << ";"<< endl<<endl;
	cout << "G(x) = ";
	for (int i = 0; i < numB.size();)
	{
		cout << numB[i];
		if (i != 0)
		{
			cout << "x^" << i;
		}
		i++;
		if (i != numB.size())
		{
			cout << " + ";
		}
	}
	cout << ";" << endl << endl <<endl;

	numC = testDivide->polynomialsMultiply(numA, 0, numA.size()-1, numB, 0, numB.size()-1);
	cout << "F(x)��G(x) = ";
	for (int i = 0; i < numC.size();)
	{
		cout << numC[i];
		if (i != 0)
		{
			cout << "x^" << i;
		}
		i++;
		if (i != numC.size())
		{
			cout << " + ";
		}
	}
	cout << ";"<< endl;
}
