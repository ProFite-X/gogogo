#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include <stack>
using namespace std;
//归并排序
//void MergerSort(int *R, int left, int right,int *tmp)
//{
//	if (left >= right)
//	{
//		return;
//	}
//	int middle = left + (right - left) / 2;
//	//先分
//	MergerSort(R, left, middle - 1);
//	MergerSort(R, middle + 1, right);
//	//再治
//	int begin1 = left;
//	int end1 = middle;
//	int begin2 = middle + 1;
//	int end2 = right;
//	int i = 0;
//	while (begin1 <= end1 && begin2 <= end2)
//	{
//		if (R[begin1] < R[begin2])
//			tmp[i++] = R[begin1++];
//		else
//			tmp[i++] = R[begin2++];
//	}
//	while (begin1 <= end1)
//		tmp[i++] = R[begin1++];
//	while (begin2 <= end2)
//		tmp[i++] = R[begin2++];
//	memcpy(R + left, tmp, sizeof(int)* (right - left + 1));
//}
int GetMid(int *R, int left, int right)
{
	int mid = (left + right) / 2;
	if (R[left] <= R[right])
	{
		if (R[mid] < R[left])
		{
			return left;
		}
		else if (R[mid] > right)
		{
			return right;
		}
		else
		{
			return mid;
		}
	}
	else
	{
		if (R[mid] < R[left])
		{
			return right;
		}
		else if (R[mid] > right)
		{
			return left;
		}
		else
		{
			return mid;
		}
	}

}
int GetIndex (int R[], int left, int right)
{
	int i = left;
	int j = right;
	if (i < j)
	{
		while (i != j)
		{
			while (i < j && R[j] >= R[left])
				j--;
			while (i < j && R[i] <= R[left])
				i++;
			swap(R[i], R[j]);
		}
		swap(R[i], R[left]);
	}
	return i;
}
void Quicksort(int *R, int left, int right)
{
	stack<int> st;
	st.push(right);
	st.push(left);
	//当栈不为空的时候
	while (!st.empty())
	{
		int i = st.top();
		st.pop();
		int j = st.top();
		st.pop();
		int index = GetIndex(R, i, j);
		swap(R[i], R[left]);
		if (i < index - 1)
		{
			st.push(index - 1);
			st.push(i);
		}
		if (index + 1 < j)
		{
			st.push(j);
			st.push(index + 1);
		}
	}
}
int main()
{
	int R[5] = { 4, 3, 2, 1, 0 };
	Quicksort(R, 0, 4);
	for (auto n : R)
	{
		cout << n << endl;
	}
	system("pause");
	return 0;
	
}