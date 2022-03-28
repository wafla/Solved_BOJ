#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define x first
#define y second
using namespace std;
int v[51][51][1 << 5] = { 0 }, n, m, dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 }, x = 97, X = 0;
char arr[51][51] = { 0 };
queue<pair<pair<int, int>, pair<int, int>>> Q;
int bfs(int sx, int sy)
{
	Q.push({ {sx,sy},{0,0} });
	v[sx][sy][0] = 1;
	int ans;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x.x + dx[i];
			int ny = cur.x.y + dy[i];
			int key = cur.y.x;
			int sum = cur.y.y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (arr[nx][ny] == '#')
				continue;
			if (arr[nx][ny] == '.' || arr[nx][ny] == 'S')
			{
				if (v[nx][ny][key] == 0)
				{
					v[nx][ny][key] = 1;
					Q.push({ {nx,ny},{key, sum + 1} });
				}
			}
			else if (arr[nx][ny] >=97 && arr[nx][ny]<=101)
			{
				if (v[nx][ny][key] == 0)
				{
					v[nx][ny][key] = 1;
					Q.push({ {nx,ny},{key | (1 << arr[nx][ny] - 97), sum + 1} });
					v[nx][ny][key | (1 << arr[nx][ny] - 97)] = 1;
				}
			}
			else if (arr[nx][ny] == 'E')
			{
				ans = sum + 1;
				if (key == X)
					return ans;
			}
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	cin >> m >> n;
	int sx, sy;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'X')
			{
				X = X | (1 << x - 97);
				arr[i][j] = x++;
			}
			if (arr[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
		}
	}
	cout << bfs(sx, sy);
}