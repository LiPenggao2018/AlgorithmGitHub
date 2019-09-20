/******************************************************
  在这里进行算法函数的测试
  
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
#include"AVLTree.cpp"                                                                               //特注：在定义模板类时，.h 和 .cpp 文件要同时包含，
#include"Graph.cpp"                                                                                        //因为只有.cpp文件中定义的才是具体的类的实现，而.h中定义的只是模板
#include"Test.h"
#include <windows.h>                   //注：必须要加window.h，且必须在最前面
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
	/*SortAndFind<int> sortAndFind;                                                       //定义为整型的模板类
	vector<int> nums;
	nums = { 5, 7, 9, 2, 4,113,8, 1,2,4,2, 1, 3 ,78,56,13,44};
	vector<int> orderNum;
	//orderNum = sortAndFind.insertSort(nums);
	//sortAndFind.mergeSort(nums,0,nums.size()-1);                                 //注意这里需要传递数组的大小范围
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
	//****************************leetcode算法测试********************************
	/*Algorithm algorithm;               //特别注意:模板一定要用上T
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
	//1.0表达式树
	ScientificCalculator<string> sc=*new ScientificCalculator<string>();
	vector<string >infix;
	string s;
	cout << "请输入数据,以!结束：" << endl;
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
	cout << "中序遍历表达式树：";
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
	cout<<"返回最小值：   "<<binarySearchTree.findMax(binarySearchTree.getRoot())->getData();
	cout << endl;
	cout << "插入数据：";
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
	cout << "没找到" << endl;
	cout << "请重新输入";
	cin >> s;
	}
	else
	{
	if (t.getLeftTree() != nullptr)
	{
	cout << s << "的左子树" << t.getLeftTree()->getData() << endl;
	}
	else
	{
	cout << t.getData() << "为叶子节点" << endl;
	}
	cout << "search data:";
	cin >> s;
	}
	}
	*/
	//--------------------------------------------------------------------------
	/*
	   //通过插入操作来构造二叉平衡树
	   AVLTree <int> avlTree;// = *new AVLTree<int>();              //通过无参构造函数来建立二叉平衡树，其中自带根节点

	   int data;
	   cout << "please input nodeData and end in 0:" << endl;                 //这里只是实现了二叉树 的操作，在此调整平衡！
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
	   avlTree.insertAVLnode(data, avlTree.getRoot());                             //0也会被插入进来
	   avlTree.visitAVLSearchTree(avlTree.getRoot());
	   cin >> data;
	   }
	   */
	//-----------------------------------------优先队列-堆------------------------
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
	cout<<"第"<<k<<"小的数为："<<priorityHeapApplication.find_Kth_minNumber(k);
	//------------------------------
	*/



	/*
	//-------------------------------------bankQueue事件模拟--------------------
	PriorityHeapApplication<int>priorityHeapApplication;
	list<map<int, int >> customers;
	map<int, int>m;
	for (int i = 0; i < 10; i++)
	{
	m.insert(pair<int, int>(i, i*2+5));
	customers.push_back(m);
	m.clear();
	}
	cout<<"一天480分钟最大的接待员数量k为： "<<priorityHeapApplication.bankQueue(customers)<<endl;
	*/
	//--------------------------------------------------------------------------------------------------------------------------
	//**********************************图*********************************************
	/*Graph<int> graph;                                     //定义一个图类对象
	*/
	//------------------------------------------------------------------------------------------------------------------------
/* 
	//邻接节点进行存储
	Graph<string> graph;
	graph.buildGraphNode();                                         //无权值可看着权值为1
	graph.BFSGraph(graph);
	//graph.topSort(graph);
	vector<Vertex<string>*>sssp;
	string s, p;
	cout << "please input s and p with weight:";
	cin >> s;
	cin >> p;
	//sssp = graph.unweightedShortestPath(graph, s, p);
	sssp = graph.weightedShortestPathDijkstra(graph, s, p);
	cout << s << " 到" << p << "的最短路径为：" << endl;
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
