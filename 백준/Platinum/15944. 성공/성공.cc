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
#include <bitset>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pi pair<int, int>
#define T pair<int,pair<int,int>>
using namespace std;
int n, m, d, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
char arr[511][511] = { 0 };
int v[511][511] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	priority_queue<T, vector<T>, greater<T>> PQ;
	PQ.push({ 1,{0,0} });
	v[0][0] = 1;
	while (!PQ.empty())
	{
		auto cur = PQ.top();
		PQ.pop();
		if (cur.Y.X == n - 1 && cur.Y.Y == m - 1)
		{
			cout << cur.X - 1 << '\n';
			return 0;
		}
		int flag = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.Y.X + dx[i];
			int ny = cur.Y.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (arr[nx][ny] == '.' && (v[nx][ny] == 0 || v[nx][ny] > v[cur.Y.X][cur.Y.Y]))
			{
				v[nx][ny] = v[cur.Y.X][cur.Y.Y];
				PQ.push({ cur.X,{nx,ny} });
			}
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.Y.X + dx[i] * d;
			int ny = cur.Y.Y + dy[i] * d;
			if (i == 0 || i == 1)
			{
				for (int j = ny - d + 1; j <= ny + d - 1; j++)
				{
					if (nx >= 0 && nx <= n - 1 && j >= 0 && j <= m - 1 && v[nx][j] == 0)
					{
						v[nx][j] = v[cur.Y.X][cur.Y.Y] + 1;
						PQ.push({ cur.X + 1,{nx,j} });
					}
					else if (nx >= n - 1 && j >= m - 1 && !flag)
					{
						flag = 1;
						v[n - 1][m - 1] = v[cur.Y.X][cur.Y.Y] + 1;
						PQ.push({ cur.X + 1,{n - 1,m - 1} });
					}
				}
			}
			else
			{
				for (int j = nx - d + 1; j <= nx + d - 1; j++)
				{
					if (j >= 0 && j <= n - 1 && ny >= 0 && ny <= m - 1 && v[j][ny] == 0)
					{
						v[j][ny] = v[cur.Y.X][cur.Y.Y] + 1;
						PQ.push({ cur.X + 1,{j,ny} });
					}
					else if (j >= n - 1 && ny >= m - 1 && !flag)
					{
						flag = 1;
						v[n - 1][m - 1] = v[cur.Y.X][cur.Y.Y] + 1;
						PQ.push({ cur.X + 1,{n - 1,m - 1} });
					}
				}
			}
		}
	}
}