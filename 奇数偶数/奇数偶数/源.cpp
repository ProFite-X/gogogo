#include <iostream>
#include <vector>
using namespace std;
bool Judge(int n)
{
	int j = 0;
	int o = 0;
	int flag = 1;
	while (n)
	{
		if (flag == 1)
		{
			j += n % 10;
			n /= 10;
			flag = 0;
		}
		else
		{
			o += n % 10;
			n /= 10;
			flag = 1;
		}
	}
	return j == o;
}
int main()
{
	int L = 0;
	int R = 0;
	while (cin >> L >> R)
	{
		int count = 0;
		for (int i = L; i <= R; i++)
		{
			if (Judge(i))
			{
				count++;
			}
		}
		cout << count << endl;
	}
}