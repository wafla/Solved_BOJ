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
int n, m, l, r, cnt = 0;
char arr[1001][1001] = { 0 };
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
bool v[1001][1001] = { 0 };
typedef pair<pair<int, pair<int, int>>, pair<int, int>> T; //우선순위 좌표 왼쪽,오른쪽
void bfs(int sx, int sy)
{
	priority_queue < T, vector<T>> Q;
	Q.push({ { {1}, {sx,sy} }, { l,r } });
	cnt++;
	v[sx][sy] = 1;
	while (!Q.empty())
	{
		auto cur = Q.top();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X.Y.X + dx[i];
			int ny = cur.X.Y.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (arr[nx][ny] == '0' && v[nx][ny] == 0)
			{
				if (dy[i] == -1)
				{
					if (cur.Y.X > 0)
					{
						Q.push({ { {cur.Y.X+cur.Y.Y-1}, {nx,ny} }, { cur.Y.X - 1, cur.Y.Y } });
						v[nx][ny] = 1;
						cnt++;
					}
				}
				else if (dy[i] == 1)
				{
					if (cur.Y.Y > 0)
					{
						Q.push({ { {cur.Y.X+cur.Y.Y-1}, {nx,ny} }, { cur.Y.X, cur.Y.Y - 1} });
						v[nx][ny] = 1;
						cnt++;
					}
				}
				else
				{
					Q.push({ { {cur.Y.X+cur.Y.Y+1}, {nx,ny} }, { cur.Y.X, cur.Y.Y } });
					v[nx][ny] = 1;
					cnt++;
				}
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	cin >> l >> r;
	int sx, sy;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '2')
			{
				sx = i;
				sy = j;
			}
		}
	}
	bfs(sx, sy);
	cout << cnt << '\n';
}