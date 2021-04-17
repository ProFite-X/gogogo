#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool div(string& s, int& index)
{
	if (index == s.size())
	{
		return false;
	}
	if (s[index] == ',')
	{
		index++;
	}
	if (s[index] == '#')
	{
		index++;
		return true;
	}
	while (s[index] >= '0' && s[index] <= '9')
	{
		index++;
	}
	return div(s, index) && div(s, index);
}
bool isValidSerialization(string preorder) {
	int index = 0;
	int n = preorder.size();
	return div(preorder, index) && index == n;
}

int main()
{
	string s = "9,3,4,#,#,1,#,#,2,#,6,#,#";
	isValidSerialization(s);
	system("pause");
	return 0;
	
}