#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
void StackRMin(vector<int>& Rmin, vector<int>& arr)
{
	stack<int> s;
	int i = 0;
	while (i < arr.size())
	{
		//当前元素大于等于当前栈顶元素，入栈
		if (s.empty() || arr[i] >= arr[s.top()])
		{
			s.push(i++);
		}
		//当前元素小于栈顶元素，栈顶出栈
		else
		{
			int index = s.top();
			s.pop();
			Rmin[index] = i;
		}
	}

}
void StackLMin(vector<int>& Lmin, vector<int>& arr)
{
	stack<int> s;
	int i = arr.size() - 1;
	while (i >= 0)
	{
		//当前元素大于等于当前栈顶元素，入栈
		if (s.empty() || arr[i] >= arr[s.top()])
		{
			s.push(i--);
		}
		//当前元素小于栈顶元素，栈顶出栈
		else
		{
			int index = s.top();
			s.pop();
			Lmin[index] = i;
		}
	}

}
int main()
{
	int n = 0;
	while (cin >> n)
	{
		vector<int> arr(n);
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		vector<int> Rmin(n, -1);
		vector<int> Lmin(n, -1);
		//找元素右边的第一个最小值
		StackRMin(Rmin, arr);
		//找元素左边的第一个最小值
		StackLMin(Lmin, arr);
		for (int i = 0; i < arr.size(); i++)
		{
			cout << Lmin[i] << " " << Rmin[i] << endl;
		}
	}

}