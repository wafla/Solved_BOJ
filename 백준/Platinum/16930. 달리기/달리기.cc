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
struct T {
	int x;
	int y;
};
char arr[1002][1002] = { 0 };
int v[1002][1002] = { 0 };
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int n, m, kk;
int x1, x2, yy, y2;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> kk;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> arr[i][j];
	cin >> x1 >> yy >> x2 >> y2;
	queue<T> Q;
	Q.push({ x1,yy });
	v[x1][yy] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		if (cur.x == x2 && cur.y == y2)
		{
			cout << v[cur.x][cur.y] - 1 << '\n';
			return 0;
		}
		for (int k = 0; k < 4; k++)
		{
			for (int t = 1; t <= kk; t++)
			{
				int nx = cur.x + dx[k] * t;
				int ny = cur.y + dy[k] * t;
				if (nx <= 0 || ny <= 0 || nx > n || ny > m)
					break;
				if (arr[nx][ny] == '#')
					break;
				if (!v[nx][ny])
				{
					v[nx][ny] = v[cur.x][cur.y] + 1;
					Q.push({ nx,ny });
				}
				else if(v[nx][ny]<=v[cur.x][cur.y])
					break;
			}
		}
	}
	cout << -1 << '\n';
}