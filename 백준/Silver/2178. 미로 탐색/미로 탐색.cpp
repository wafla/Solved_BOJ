#include <iostream>
#include <vector>
#include <queue>
#define X first
#define Y second
using namespace std;
int arr[101][101] = { 0 }, n, m;
int vis[101][101] = { 0 };
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
queue<pair<int, int>> Q;
void bfs()
{
	vis[0][0] = 1;
	Q.push({ 0,0 });
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (vis[nx][ny] > 0 || arr[nx][ny] != 1)
				continue;
			vis[nx][ny] = vis[cur.X][cur.Y]+1;
			Q.push({ nx, ny });
		}
	}
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%1d", &arr[i][j]);
	bfs();
	cout << vis[n - 1][m - 1];
}
//참고 : https://blog.encrypted.gg/729?category=773649
