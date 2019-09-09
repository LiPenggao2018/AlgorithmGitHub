/**
     greedy算法的原理和应用
*/
#pragma once
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<vector>
using namespace std;                    

class GreedyAlgorithm
{
public:
	GreedyAlgorithm();
	~GreedyAlgorithm();

	//the use
	vector<string> setCover(map<string,set<string>>broadcast, vector<string>rural);

private:

};