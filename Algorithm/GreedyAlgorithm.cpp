#include"GreedyAlgorithm.h"

GreedyAlgorithm::GreedyAlgorithm()
{

}


GreedyAlgorithm::~GreedyAlgorithm()
{

}

// use greedyAlgorithm to solve the covering problem, and return the broadercast
vector<string> GreedyAlgorithm::setCover(map<string, set<string>>broadcast,vector<string>rural)    //map��string�ǹ㲥������set���串�ǵĵ���
{
	vector<string> result;            //�洢�㲥

	map<string, set<string>>::iterator it;
	string name;
	set<string> coverArea;
	vector<string>::iterator ruralIt;                         //��ǰ�����ڵ�δ�����ǵ�������
	set<string>::iterator coverIt;
	int flag = 0;
	for (it = broadcast.begin(); it != broadcast.end();it++)
	{
		name=it->first;
		coverArea = it->second;                       //��ǰ�㲥�ĸ�������
		for (coverIt = coverArea.begin(); coverIt != coverArea.end(); coverIt++)
		{
			for (ruralIt = rural.begin(); ruralIt != rural.end(); ruralIt++)
			{
				if (coverIt->data == ruralIt->data)
				{
					rural.erase(ruralIt);                   //�����ȣ�˵���ù㲥it����δ�����ǵ�����
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