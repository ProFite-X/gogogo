#include<iostream>
#include<string>
#include<assert.h>
using namespace std;
void _MergeSort(int *ar, int left, int right, int *tmp)
{
	int mid = (left + right) / 2;
	if (left >= right)//分的最后状态
		return;

	//先分
	_MergeSort(ar, left, mid, tmp);
	_MergeSort(ar, mid + 1, right, tmp);
	//再治理
	int begin1 = left;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = right;
	int i = 0;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (ar[begin1] < ar[begin2])
			tmp[i++] = ar[begin1++];
		else
			tmp[i++] = ar[begin2++];
	}
	while (begin1 <= end1)
		tmp[i++] = ar[begin1++];
	while (begin2 <= end2)
		tmp[i++] = ar[begin2++];

	memcpy(ar + left, tmp, sizeof(int)*(right - left + 1));
	//排好的进行插入进原数组中


}


void MergeSort(int *ar, int left, int right)
{
	int n = right - left + 1;
	int *tmp = (int *)malloc(sizeof(int)* n);
	assert(tmp != NULL);

	//归并排序的过程
	_MergeSort(ar, left, right, tmp);

	free(tmp);
	tmp = NULL;
}
int main()
{
	int a[] = { 49, 38, 65, 97, 76, 13, 27 };
	MergeSort(a, 0, 6);
	for (int i = 0; i < 7; i++)
		printf("%d ", a[i]);
	system("pause");
	return 0;

}