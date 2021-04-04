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
		//利用栈的特性,后进先出，假如入栈的元素与栈顶元素相等，则弹出
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