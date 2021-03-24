#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
void selectSort(int R[],int n)
{
	int i, j, k;
	for (int i = 0; i < n; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (R[k] > R[j])
				k = j;
		}
		swap(R[i], R[k]);
	}
}
int main()
{
	int R[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	selectSort(R, 8);
	system("pause");
	return 0;
	
}