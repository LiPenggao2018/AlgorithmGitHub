/******************************************************
  ����������㷨�����Ĳ���
  
*******************************************************/
#include"Algorihtm.h"
#include"ScientificCalculator.h"
#include"ScientificCalculator.cpp"
#include"BinarySearchTree.h"
#include"BinarySearchTree.cpp"
#include"PriorityBinaryHeap.h"
#include"PriorityBinaryHeap.cpp"
#include"PriorityHeapApplication.cpp"
#include<map>
#include<queue>
#include<set>
#include"SortAndFind.cpp"
#include"SortAndFind.h"
#include"AVLTree.h"
#include"AVLTree.cpp"                                                                               //��ע���ڶ���ģ����ʱ��.h �� .cpp �ļ�Ҫͬʱ������
#include"Graph.cpp"                                                                                        //��Ϊֻ��.cpp�ļ��ж���Ĳ��Ǿ�������ʵ�֣���.h�ж����ֻ��ģ��
#include"Test.h"
#include <windows.h>                   //ע������Ҫ��window.h���ұ�������ǰ��
#include <GL/gl.h>  
#include <GL/glu.h>  
#include <GL/glut.h>  
#include <cstdlib>  
#include <cstdio>  
#include <cmath>  

//************************************************************************************
//************************************************************************************
/*void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0, 1.0);
	glRectf(25.0, 25.0, 125.0, 125.0);
	glRectf(225.0, 25.0, 325.0, 125.0);
	glDisable(GL_POLYGON_STIPPLE);
	glFlush();
}

void init(void){
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glShadeModel(GL_FLAT);
}

void reshape(int w, int h){
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
}

int main(int argc, char** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1000, 800);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}*/


void main()
{
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
	   while (data)                                           //
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
/* 
	//�ڽӽڵ���д洢
	Graph<string> graph;
	graph.buildGraphNode();                                         //��Ȩֵ�ɿ���ȨֵΪ1
	graph.BFSGraph(graph);
	//graph.topSort(graph);
	vector<Vertex<string>*>sssp;
	string s, p;
	cout << "please input s and p with weight:";
	cin >> s;
	cin >> p;
	//sssp = graph.unweightedShortestPath(graph, s, p);
	sssp = graph.weightedShortestPathDijkstra(graph, s, p);
	cout << s << " ��" << p << "�����·��Ϊ��" << endl;
	for (int i = 0; i < sssp.size(); i++)
	{
		cout << sssp[i]->getData()<<"->";
	}
//********************************************************************************
*/

	Test *t1 = new Test();  
	t1->testAdvancedAlgorithm.testDivideMerge->testPolynomialsMultiply();

    cout << endl;
	system("pause");
}
