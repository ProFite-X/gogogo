#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
vector<vector<int>> cur;
vector<vector<int>> res;
vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
	if (obstacleGrid.empty())
	{
		return res;
	}
	backtrack(obstacleGrid, 0, 0);
	return res;
}
void backtrack(vector<vector<int>>& obstacleGrid, int i, int j)
{
	if (i >= obstacleGrid.size() || j >= obstacleGrid[0].size() || i < 0 || j < 0 || obstacleGrid[i][j] == 1)
	{
		//越界或者遇到障碍物返回
		return;
	}
	if (i == obstacleGrid.size() - 1 && j == obstacleGrid[0].size() - 1)
	{
		res = cur;
		return;
	}
	//节点入队
	vector<int> tmp = { i, j };
	cur.push_back(tmp);
	//标记当前路径已经走过
	obstacleGrid[i][j] = 1;
	//向右走
	backtrack(obstacleGrid, i, j + 1);
	//向下走
	backtrack(obstacleGrid, i + 1, j);
	//回溯
	cur.pop_back();
	obstacleGrid[i][j] = 0;
}
int main()
{
	vector<vector<int>> obstacleGrid = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };
	pathWithObstacles(obstacleGrid);
	system("pause");
	return 0;
	
}