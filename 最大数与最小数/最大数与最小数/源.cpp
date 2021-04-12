#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
class Com
{
public:
	bool operator ()(string& s1, string& s2)
	{
		return s1 + s2 < s2 + s1;
	}
};
string largestNumber(vector<int> nums) {
	priority_queue<string, vector<string>, Com> q;
	for (int i = 0; i < nums.size(); i++)
	{
		q.push(to_string(nums[i]));
	}
	string res;
	for (int i = 0; i < nums.size(); i++)
	{
		string tmp = q.top();

		//不是第一个0则需要进行判断是否前面一坨数据都为0
		if (tmp == "0" && i > 0)
		{
			bool flag = 0;
			for (int k = 0; k < res.size(); k++)
			{
				if (res[k] != 0)
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				q.pop();
				continue;
			}
		}
		res += tmp;
		q.pop();
	}
	return res;
}
int main()
{
	largestNumber({ 0, 0 });
	system("pause");
	return 0;
	
}