#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
string path;
vector<int> use;
int ccount = 0;
bool isSub(string s)
{
	int begin = 0;
	int end = s.size() - 1;
	while (begin < end)
	{
		//不相等
		if (s[begin] != s[end])
		{
			return false;
		}
		begin++;
		end--;
	}
	return true;
}

void backtrack(string s, int startIndex)
{
	if (startIndex >= s.size())
	{
		return;
	}
	for (int i = startIndex; i < s.size(); i++)
	{
		path += s[i];
		if (isSub(path))
		{
			ccount++;
		}
		//递归进下一层
		backtrack(s, i + 1);
		//回溯
		path.pop_back();
	}
}

int countSubstrings(string s) {
	if (s.empty())
	{
		return 0;
	}
	int startIndex = 0;
	use.assign(s.size(), 0);
	backtrack(s, startIndex);
	return ccount;
}

int main()
{
	countSubstrings("aaa");
	system("pause");
	return 0;
	
}