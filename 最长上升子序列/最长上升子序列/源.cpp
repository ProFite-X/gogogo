#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
	vector<int> dp(nums.size(), 1);
	//dp[i] = max (dp[i], dp[j] + 1)
	int res = 1;
	for (int i = 1; i < nums.size(); i++)
	{
		//不能直接这么写
		//10 > 4
		if (nums[i] > nums[i - 1])
		{
			dp[i] = dp[i - 1] + 1;
		}
		else
		{
			//去之前找最长的子序列 + 1
			int preMaxLen = 1;
			for (int j = i - 1; j >= 0; j--)
			{
				if (nums[i] > nums[j])
				{
					preMaxLen = max(preMaxLen, dp[j] + 1);
				}
			}
			dp[i] = preMaxLen;
		}
		res = max(res, dp[i]);
	}
	return res;
}
int main()
{
	vector<int> res = { 1, 3, 6, 7, 9, 4, 10, 5, 6 };
	lengthOfLIS(res);
	system("pause");
	return 0;
	
}