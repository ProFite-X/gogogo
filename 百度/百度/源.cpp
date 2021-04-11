#if 0


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int T = 0;
	while (cin >> T)
	{
		int n = 0;
		int m = 0;
		while (T--)
		{
			cin >> n >> m;
			vector<int> people(n);
			vector<int> point(m);
			vector<int> res(n);
			for (int i = 0; i < n; i++)
			{
				cin >> people[i];
			}
			for (int i = 0; i < m; i++)
			{
				cin >> point[i];
			}
			for (int i = 0; i < n; i++)
			{
				int count = 0;
				for (int j = 0; j < m; j++)
				{
					if (people[i] <= point[j])
					{
						count++;
					}
				}
				res[i] = count;
			}
			for (int k = 0; k < n - 1; k++)
			{
				cout << res[k] << " ";
			}
			cout << res[n - 1] << endl;
		}
	}
	system("pause");
	return 0;
	
}
#endif

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	//����
	int n = 0;
	//ָ��
	int m = 0;
	while (cin >> n >> m)
	{
		vector<vector<int>> people(n, vector<int>());
		for (int i = 0; i < n; i++)
		{
			people[i].push_back(i + 1);
		}
		int i = 0;
		cout << i << endl;
		vector<char> ordered(m);
		vector<int> close(m);
		vector<int> open(m);
		vector<int> res;
		while (m--)
		{
			cin >> ordered[i] >> close[i] >> open[i];
			if (ordered[i] == 'C')
			{
				//�ر�close[i]���˰��Ƶ�open[i]
				vector<int> closePeople = people[close[i] - 1];
				vector<int> openPeople = people[open[i] - 1];
				//��������
				for (int numb = 0; numb < closePeople.size(); numb++)
				{
					openPeople.push_back(closePeople[numb]);
				}
				//�رյĳ������
				vector<int> empty;

				//�����¼���Ķ�Ա
				people[close[i] - 1] = empty;
				people[open[i] - 1] = openPeople;
			}
			if (ordered[i] == 'Q')
			{
				int p1 = close[i];
				int p2 = open[i];
				for (int j = 0; j < ordered.size() - 1; j++)
				{
					//����ѡ��
					if ((open[j] == p1 && close[j] == p2) || (close[j] == p1 && open[j] == p2))
					{
						int step = 0;
						//��close[i]��Ѱ�Ҷ���
						for (int k = 0; k < people[open[j] - 1].size(); k++)
						{
							if (people[close[i] - 1][k] == p1)
								p1 = k;
							if (people[close[i] - 1][k] == p2)
								p2 = k;
						}
						step = abs(p1 - p2) + 1;
						res.push_back(step);
					}
					//û�н���������ôһ������һ��
					else
					{
						res.push_back(-1);
					}
				}
			}
			i++;
		}
		for (int i = 0; i < res.size(); i++)
		{
			cout << res[i] << endl;
		}
	}
	system("pause");
	return 0;
	
}
