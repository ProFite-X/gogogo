#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
bool chkParenthesis(string A, int n) {
	// write code here
	if (n % 2 != 0)
	{
		return false;
	}
	stack<char> s;
	for (int i = 0; i < n; i++)
	{
		if (A[i] != '(' || A[i] != ')')
		{
			return false;
		}
		else if (A[i] == '(')
		{
			s.push('(');
		}
		else if (A[i] == ')')
		{
			if (s.empty())
				return false;
			else
				s.pop();
		}
	}
	if (s.empty())
		return true;
	return false;
}
int main()
{
	cout << chkParenthesis("(()())", 6);
	system("pause");
	return 0;
	
}