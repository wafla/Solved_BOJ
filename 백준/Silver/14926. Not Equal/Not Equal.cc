#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <math.h>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
using namespace std;
bool visit[501][501] = { 0 };
int n;
void dfs(int x, int y)
{
	visit[x][y] = 1;
	visit[y][x] = 1;
	for (int j = 1; j <= n; j++)
	{
		if (y == j)
			continue;
		if (!visit[y][j])
		{
			cout << "a" << j << " ";
			dfs(y, j);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	cout << "a1 ";
	visit[n][1] = 1;
	visit[1][n] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (i == j)
				continue;
			if (!visit[i][j])
			{
				cout << "a" << j << " ";
				dfs(i, j);
			}
		}
	}
	cout << "a1\n";
}