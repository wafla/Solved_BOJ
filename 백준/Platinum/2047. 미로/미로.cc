#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <deque>
#include <set>
#define X first
#define Y second
using namespace std;
char arr[101][101] = { 0 };
int v[101][101] = { 0 }, dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int n, m, sx, sy;
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		memset(arr, 0, sizeof(arr));
		memset(v, 0, sizeof(v));
		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < m;j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == 's')
				{
					sx = i;
					sy = j;
				}
			}
		}
		queue<pair<int, int>> Q;
		Q.push({ sx,sy });
		v[sx][sy] = 1;
		int sum = 0;
		while (!Q.empty())
		{
			auto cur = Q.front();
			Q.pop();
			for (int i = 0;i < 4;i++)
			{
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;
				if ((arr[nx][ny] == '.' || arr[nx][ny] == 't') && v[nx][ny] == 0)
				{
					sum++;
					v[nx][ny] = 1;
					Q.push({ nx,ny });
				}
			}
		}
		cout << sum << ".00\n";
	}
}