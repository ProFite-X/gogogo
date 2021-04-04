#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include <stack>
using namespace std;

int main()
{
	int n = 0;
	while (cin >> n)
	{
		string s;
		cin >> s;
		//����ջ������,����ȳ���������ջ��Ԫ����ջ��Ԫ����ȣ��򵯳�
		stack<int> mystack;
		for (int i = 0; i < s.size(); i++)
		{
			int number = s[i] - '0';
			if (!mystack.empty() && (mystack.top() + number == 10))
			{
				mystack.pop();
				continue;
			}
			mystack.push(number);
		}
		cout << mystack.size() << endl;
	}
	system("pause");
	return 0;
	
}