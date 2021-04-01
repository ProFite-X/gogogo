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
		//��ǰԪ�ش��ڵ��ڵ�ǰջ��Ԫ�أ���ջ
		if (s.empty() || arr[i] >= arr[s.top()])
		{
			s.push(i++);
		}
		//��ǰԪ��С��ջ��Ԫ�أ�ջ����ջ
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
		//��ǰԪ�ش��ڵ��ڵ�ǰջ��Ԫ�أ���ջ
		if (s.empty() || arr[i] >= arr[s.top()])
		{
			s.push(i--);
		}
		//��ǰԪ��С��ջ��Ԫ�أ�ջ����ջ
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
		//��Ԫ���ұߵĵ�һ����Сֵ
		StackRMin(Rmin, arr);
		//��Ԫ����ߵĵ�һ����Сֵ
		StackLMin(Lmin, arr);
		for (int i = 0; i < arr.size(); i++)
		{
			cout << Lmin[i] << " " << Rmin[i] << endl;
		}
	}

}