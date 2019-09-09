/******************************************************
  ����������㷨�����Ĳ���
  
*******************************************************/
#include"Algorithm.h"
#include"ScientificCalculator.h"
#include"ScientificCalculator.cpp"
#include"BinarySearchTree.h"
#include"BinarySearchTree.cpp"
#include"PriorityBinaryHeap.h"
#include"PriorityBinaryHeap.cpp"
#include"PriorityHeapApplication.cpp"
#include"GreedyAlgorithm.h"
#include<map>
#include<queue>
#include<set>
#include"SortAndFind.cpp"
#include"SortAndFind.h"
#include"AVLTree.h"
#include"AVLTree.cpp"                                                                               //��ע���ڶ���ģ����ʱ��.h �� .cpp �ļ�Ҫͬʱ������
#include"Graph.cpp"                                                                                        //��Ϊֻ��.cpp�ļ��ж���Ĳ��Ǿ�������ʵ�֣���.h�ж����ֻ��ģ��
using namespace std;                                                                                                               //���Ա������.cpp�ļ�
                                                                                                                      //��Ҳ��Ϊʲôģ���п�����������������Ϊ��.h�о�ʵ���˾����ģ��
//*****************************************************

void main()
{
	GreedyAlgorithm greedyAlgorithm;
	map<string, set<string>>broadcast;
	vector<string>rural;
	rural = { "ID"," NV", "UT", "WA", "MT", "OR", "CA", "AZ"};
	set<string>setk1, setk2, setk3, setk4, setk5;
	setk1.insert("ID");
	setk1.insert("NV");
	setk1.insert("UT");
	broadcast.insert(map<string, set<string>>::value_type("k1", setk1));

	setk2.insert("WA");
	setk2.insert("ID");
	setk2.insert("MT");
	broadcast.insert(map<string, set<string>>::value_type("k2", setk2));

	setk3.insert("OR");
	setk3.insert("NV");
	setk3.insert("CA");
	broadcast.insert(map<string, set<string>>::value_type("k3", setk3));

	setk4.insert("UT");
	setk4.insert("NV");
	broadcast.insert(map<string, set<string>>::value_type("k4", setk4));

	setk5.insert("CA");
	setk5.insert("AZ");
	broadcast.insert(map<string, set<string>>::value_type("k5", setk5));

	cout<<greedyAlgorithm.setCover(broadcast, rural)[0];
	//------------------------------------------------------------------------
	/*SortAndFind<int> sortAndFind;                                                       //����Ϊ���͵�ģ����
	vector<int> nums;
	nums = { 5, 7, 9, 2, 4,113,8, 1,2,4,2, 1, 3 ,78,56,13,44};
	vector<int> orderNum;
	//orderNum = sortAndFind.insertSort(nums);
	//sortAndFind.mergeSort(nums,0,nums.size()-1);                                 //ע��������Ҫ��������Ĵ�С��Χ
	//sortAndFind.quickSort(nums, 0, nums.size() - 1);
	//sortAndFind.bucketSort(nums, 79);
	sortAndFind.radixSort(nums);
	cout << endl << "last result: ";
	for (int i = 0; i <nums.size(); i++)
	{
	cout << nums[i]<<"   ";
	}
	cout << endl;
	*/
	//********************************************************************
	//****************************leetcode�㷨����********************************
	/*Algorithm algorithm;               //�ر�ע��:ģ��һ��Ҫ����T
	string s = "abpcplfffefa";
	vector<string>d;
	d.push_back("apple");
	d.push_back("plea");
	d.push_back("ccle");
	d.push_back("ab");
	string longestString;
	longestString = algorithm.findLongestWord(s,d);
	cout << "the longest word is:"<<longestString<<endl;

	*/
	/*vector<Interval> is,it;
	Interval temp;
	temp.start = 1;
	temp.end = 3;
	is.push_back(temp);
	temp.start = 6;
	temp.end = 9;
	is.push_back(temp);
	temp.start = 4;
	temp.end = 5;
	is.push_back(temp);
	temp.start = 6;
	temp.end = 8;
	is.push_back(temp);
	temp.start = 7;
	temp.end = 10;
	is.push_back(temp);
	temp.start = 0;
	temp.end = 0;
	is.push_back(temp);

	temp.start = 2;
	temp.end = 5;
	int i;
	it=Algorithm.merge(is,temp);
	for (int i = 0; i < it.size(); i++)
	{
	cout << "[" << it[i].start << ", " << it[i].end <<"]"<< endl;
	}
	*/

	//***************************************************************************
	//***************************************************************************
	/*
	//1.0���ʽ��
	ScientificCalculator<string> sc=*new ScientificCalculator<string>();
	vector<string >infix;
	string s;
	cout << "����������,��!������" << endl;
	/*while (true)
	{
	cin >> s;
	if (s.compare("!")==0)
	{
	break;
	}
	else
	{
	infix.push_back(s);
	}
	}
	infix.push_back("(");
	infix.push_back("3");
	infix.push_back("+");
	infix.push_back("5");
	infix.push_back(")");
	infix.push_back("*");
	infix.push_back("4");
	infix.push_back("-");
	infix.push_back("(");
	infix.push_back("6");
	infix.push_back("/");
	infix.push_back("2");
	infix.push_back("+");
	infix.push_back("3");
	infix.push_back(")");
	infix.push_back("/");
	infix.push_back("4");
	sc.infixTranslatePostfix(infix);
	sc.constructTree(sc.getPostfix());
	cout << endl;
	cout << "����������ʽ����";
	sc.visitTree(sc.getStackTree()[0]);
	cout << endl;
	cout<<sc.calculateTree(sc.getPostfix());
	*/
	/*
	double s;
	BinarySearchTree<double> binarySearchTree;
	vector<double>datas;
	cout << "Please input BinarySearchTree Node Value:" << endl;
	while (true)
	{
	cin >> s;
	if (s == 0)
	{
	break;
	}
	else
	{
	datas.push_back(s);
	}
	}
	binarySearchTree.constructBinarySearchTree(datas);
	binarySearchTree.visitSearchTree(binarySearchTree.getRoot());
	cout << endl;
	cout<<"������Сֵ��   "<<binarySearchTree.findMax(binarySearchTree.getRoot())->getData();
	cout << endl;
	cout << "�������ݣ�";
	cin>>s;
	while (s)
	{
	binarySearchTree.insertNode(s, binarySearchTree.getRoot());
	binarySearchTree.visitSearchTree(binarySearchTree.getRoot());
	cin >> s;
	}
	cout << endl;
	cout << "search data:";
	cin >> s;
	while (s)
	{
	Tree<double> t=*binarySearchTree.find(s, binarySearchTree.getRoot());
	if (t.getData()==0)
	{
	cout << "û�ҵ�" << endl;
	cout << "����������";
	cin >> s;
	}
	else
	{
	if (t.getLeftTree() != nullptr)
	{
	cout << s << "��������" << t.getLeftTree()->getData() << endl;
	}
	else
	{
	cout << t.getData() << "ΪҶ�ӽڵ�" << endl;
	}
	cout << "search data:";
	cin >> s;
	}
	}
	*/
	//--------------------------------------------------------------------------
	/*
	   //ͨ������������������ƽ����
	   AVLTree <int> avlTree;// = *new AVLTree<int>();              //ͨ���޲ι��캯������������ƽ�����������Դ����ڵ�

	   int data;
	   cout << "please input nodeData and end in 0:" << endl;                 //����ֻ��ʵ���˶����� �Ĳ������ڴ˵���ƽ�⣡
	   Tree<int> *node = new Tree<int>();
	   cin >> data;
	   node->setData(data);
	   avlTree.setRoot(node);
	   int flag = 0;
	   while (data)                               //
	   {
	   if (flag == 0)
	   {
	   cin >> data;
	   flag = 1;
	   }
	   avlTree.insertAVLnode(data, avlTree.getRoot());                             //0Ҳ�ᱻ�������
	   avlTree.visitAVLSearchTree(avlTree.getRoot());
	   cin >> data;
	   }
	   */
	//-----------------------------------------���ȶ���-��------------------------
	/*
	PriorityBinaryHeap<int> priorityBinaryHeap;
	PriorityHeapApplication<int>priorityHeapApplication;
	cout << "Please input data constructing binaryHeap and end in 0:" << endl;
	int data;
	cin >> data;
	while (data)
	{
	priorityBinaryHeap.insertHeap(data);
	cin >> data;
	}
	for (auto x : priorityBinaryHeap.getHeap())
	{
	if (x)
	{
	cout << x;
	}
	}
	cout << endl;
	priorityHeapApplication.setPriorityBinaryHeap(priorityBinaryHeap);
	int k = 3;
	cout<<"��"<<k<<"С����Ϊ��"<<priorityHeapApplication.find_Kth_minNumber(k);
	//------------------------------
	*/



	/*
	//-------------------------------------bankQueue�¼�ģ��--------------------
	PriorityHeapApplication<int>priorityHeapApplication;
	list<map<int, int >> customers;
	map<int, int>m;
	for (int i = 0; i < 10; i++)
	{
	m.insert(pair<int, int>(i, i*2+5));
	customers.push_back(m);
	m.clear();
	}
	cout<<"һ��480�������ĽӴ�Ա����kΪ�� "<<priorityHeapApplication.bankQueue(customers)<<endl;
	*/
	//--------------------------------------------------------------------------------------------------------------------------
	//**********************************ͼ*********************************************
	/*Graph<int> graph;                                     //����һ��ͼ�����
	*/
	//------------------------------------------------------------------------------------------------------------------------


//********************************************************************************
	cout << endl;
	system("pause");
}
