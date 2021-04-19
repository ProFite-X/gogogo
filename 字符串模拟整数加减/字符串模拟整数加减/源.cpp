#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//字符串相加
string addStrings(string a, string b) {
	int end1 = a.size() - 1;
	int end2 = b.size() - 1;
	string ans;
	int over = 0;
	while (end1 >= 0 || end2 >= 0 || over != 0)
	{
		int num1 = 0;
		int num2 = 0;
		//提取第一数字
		if (end1 >= 0)
		{
			num1 = a[end1] - '0';
			end1--;
		}
		//提取第二个数字
		if (end2 >= 0)
		{
			num2 = b[end2] - '0';
			end2--;
		}
		int res = num1 + num2 + over;
		//如果超过了10
		if (res >= 10)
		{
			//进位
			over = 1;
			//取余数
			res = res % 10;
		}
		else
		{
			over = 0;
		}
		//结果加上
		ans += to_string(res);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
bool cmp(string s1, string s2)
{
	//去除00的情况
	int pos = s1.find_first_not_of('0');
	if (pos == string::npos)
	{
		s1 = "0";
	}
	else
	{
		s1 = s1.substr(pos);
	}
	pos = s2.find_first_not_of('0');
	if (pos == string::npos)
	{
		s2 = "0";
	}
	else
	{
		s2 = s2.substr(pos);
	}
	//比较大小
	if (s1.size() > s2.size())
	{
		return 1;
	}
	else if (s1.size() < s2.size())
	{
		return 0;
	}
	else
	{
		return s1 >= s2;
	}
}
//字符串相减
string DeleteStrings(string a, string b) {
	int end1 = a.size() - 1;
	int end2 = b.size() - 1;
	string ans;
	int over = 0;
	bool flag = 0;
	if (cmp(b,a))
	{
		swap(a, b);
		swap(end1, end2);
		flag = -1;
	}
	while (end1 >= 0 || end2 >= 0 || over != 0)
	{
		int num1 = 0;
		int num2 = 0;
		//提取第一数字
		if (end1 >= 0)
		{
			num1 = a[end1] - '0';
			end1--;
		}
		//提取第二个数字
		if (end2 >= 0)
		{
			num2 = b[end2] - '0';
			end2--;
		}
		int res = num1 - num2 + over;
		//如果超过了10
		if (res < 0)
		{
			res = 10 + num1 - num2 + over;
			over = -1;
		}
		else
		{
			over = 0;
		}
		//结果加上
		ans += to_string(res);
	}
	if (flag)
	{
		ans += '-';
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
//字符串相乘以
//[ ][ ][1][2][3]
//[ ][ ][ ][4][5]
//---------------
//[ ][ ][ ][1][5]
//[ ][ ][1][0][ ]
//[ ][0][5][ ][ ]
//[ ][ ][1][2][ ]
//[ ][0][8][ ][ ]
//[0][4][ ][ ][ ]
string multiply(string num1, string num2) {
	if (num1 == "0" || num2 == "0")
	{
		return "0";
	}
	int n = num1.size();
	int m = num2.size();
	string ans;
	vector<int> arr(m + n, 0);
	for (int j = m - 1; j >= 0; j--)
	{
		for (int i = n - 1; i >= 0; i--)
		{
			int value1 = num2[j] - '0';
			int value2 = num1[i] - '0';
			int res = value1 * value2;
			//十位
			int ten = res / 10;
			//个位
			int bit = res % 10;
			//个位归位
			arr[i + j + 1] += bit;
			if (arr[i + j + 1] >= 10)
			{
				arr[i + j] += 1;
				arr[i + j + 1] %= 10;
			}
			//十位归位
			arr[i + j] += ten;
			if (arr[i + j] >= 10)
			{
				arr[i + j - 1] += 1;
				arr[i + j] %= 10;
			}
		}
	}
	bool flag = 0;
	for (int i = 0; i < m + n; i++)
	{
		if (arr[i] == 0 && flag == 0)
		{
			continue;
		}
		flag = 1;
		ans += to_string(arr[i]);
	}
	return ans;
}
//字符串相除(保留n位小数)
int invert(string s)
{
	int res = 0;
	for (int i = 0; i < s.size(); i++)
	{
		res = res * 10 + (s[i] - '0');
	}
	return res;
}

string divide(string a, string b)
{
	string ans;
	//将字符串分为两部分，整数部分和小数部分
	int DeleteTime = 0;
	string integer = a;
	//被除数大于等于除数，那么就一直减除数
	while (cmp(integer, b))
	{
		integer = DeleteStrings(integer, b);
		//记录相减的次数作为整数部分
		DeleteTime++;
	}
	//加入整数部分
	ans = to_string(DeleteTime) + ".";

	//记录小数部分,保留十位小数
	for (int i = 0; i < 10; i++)
	{
		//借位
		integer.append("0");
		int time = 0;
		while (cmp(integer, b))
		{
			integer = DeleteStrings(integer, b);
			time++;
		}
		//加入小数部分
		ans += to_string(time);
	}
	return ans;
}
int main()
{
	divide("10", "7");
	system("pause");
	return 0;
	
}