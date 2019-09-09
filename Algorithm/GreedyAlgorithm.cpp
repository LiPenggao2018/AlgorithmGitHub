#include"GreedyAlgorithm.h"

GreedyAlgorithm::GreedyAlgorithm()
{

}


GreedyAlgorithm::~GreedyAlgorithm()
{

}

// use greedyAlgorithm to solve the covering problem, and return the broadercast
vector<string> GreedyAlgorithm::setCover(map<string, set<string>>broadcast,vector<string>rural)    //map中string是广播，其后的set是其覆盖的地区
{
	vector<string> result;            //存储广播

	map<string, set<string>>::iterator it;
	string name;
	set<string> coverArea;
	vector<string>::iterator ruralIt;                         //当前还存在的未被覆盖到的区域
	set<string>::iterator coverIt;
	int flag = 0;
	for (it = broadcast.begin(); it != broadcast.end();it++)
	{
		name=it->first;
		coverArea = it->second;                       //当前广播的覆盖领域
		for (coverIt = coverArea.begin(); coverIt != coverArea.end(); coverIt++)
		{
			for (ruralIt = rural.begin(); ruralIt != rural.end(); ruralIt++)
			{
				if (coverIt->data == ruralIt->data)
				{
					rural.erase(ruralIt);                   //如果相等，说明该广播it存在未被覆盖的区域
					break;
					flag = 1;
				}
			}//for(ruralIt)
		}//for(coverIt)

		if (flag)
		{
			result.push_back(name);
		}

	}

	return result;       //
}