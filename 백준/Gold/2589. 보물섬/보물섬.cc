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
char arr[63][63] = { 0 };
int visit[63][63] = { 0 };
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int maxx = 0;
int n, m;
void bfs(int x, int y)
{
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	visit[x][y] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		if (maxx < visit[cur.X][cur.Y])
			maxx = visit[cur.X][cur.Y];
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (!visit[nx][ny] && arr[nx][ny] == 'L')
			{
				Q.push({ nx,ny });
				visit[nx][ny] = visit[cur.X][cur.Y] + 1;
			}
		}
	}
	memset(visit, 0, sizeof(visit));
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 'L')
				bfs(i, j);
	cout << maxx - 1 << '\n';
}