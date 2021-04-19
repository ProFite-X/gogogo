#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
//�ַ������
string addStrings(string a, string b) {
	int end1 = a.size() - 1;
	int end2 = b.size() - 1;
	string ans;
	int over = 0;
	while (end1 >= 0 || end2 >= 0 || over != 0)
	{
		int num1 = 0;
		int num2 = 0;
		//��ȡ��һ����
		if (end1 >= 0)
		{
			num1 = a[end1] - '0';
			end1--;
		}
		//��ȡ�ڶ�������
		if (end2 >= 0)
		{
			num2 = b[end2] - '0';
			end2--;
		}
		int res = num1 + num2 + over;
		//���������10
		if (res >= 10)
		{
			//��λ
			over = 1;
			//ȡ����
			res = res % 10;
		}
		else
		{
			over = 0;
		}
		//�������
		ans += to_string(res);
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
bool cmp(string s1, string s2)
{
	//ȥ��00�����
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
	//�Ƚϴ�С
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
//�ַ������
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
		//��ȡ��һ����
		if (end1 >= 0)
		{
			num1 = a[end1] - '0';
			end1--;
		}
		//��ȡ�ڶ�������
		if (end2 >= 0)
		{
			num2 = b[end2] - '0';
			end2--;
		}
		int res = num1 - num2 + over;
		//���������10
		if (res < 0)
		{
			res = 10 + num1 - num2 + over;
			over = -1;
		}
		else
		{
			over = 0;
		}
		//�������
		ans += to_string(res);
	}
	if (flag)
	{
		ans += '-';
	}
	reverse(ans.begin(), ans.end());
	return ans;
}
//�ַ��������
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
			//ʮλ
			int ten = res / 10;
			//��λ
			int bit = res % 10;
			//��λ��λ
			arr[i + j + 1] += bit;
			if (arr[i + j + 1] >= 10)
			{
				arr[i + j] += 1;
				arr[i + j + 1] %= 10;
			}
			//ʮλ��λ
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
//�ַ������(����nλС��)
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
	//���ַ�����Ϊ�����֣��������ֺ�С������
	int DeleteTime = 0;
	string integer = a;
	//���������ڵ��ڳ�������ô��һֱ������
	while (cmp(integer, b))
	{
		integer = DeleteStrings(integer, b);
		//��¼����Ĵ�����Ϊ��������
		DeleteTime++;
	}
	//������������
	ans = to_string(DeleteTime) + ".";

	//��¼С������,����ʮλС��
	for (int i = 0; i < 10; i++)
	{
		//��λ
		integer.append("0");
		int time = 0;
		while (cmp(integer, b))
		{
			integer = DeleteStrings(integer, b);
			time++;
		}
		//����С������
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