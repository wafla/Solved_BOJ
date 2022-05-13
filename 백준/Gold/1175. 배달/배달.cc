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
#define x first
#define y second
using namespace std;
int n, m;
char arr[51][51] = { 0 };
int v[4][4][51][51] = { 0 }, dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 };
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	int sx, sy, cx1, cx2, cy1, cy2, c = 0;
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'S')
			{
				sx = i;
				sy = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'C')
			{
				if (c == 0)
				{
					cx1 = i;
					cy1 = j;
					c++;
				}
				else if (c == 1)
				{
					cx2 = i;
					cy2 = j;
					c++;
				}
			}
		}
	}
	queue<pair<pair<int, int>, pair<pair<int, int>,int>>>Q;//x y 방향 시간 개수
	Q.push({ {sx,sy},{{0,0}, 0} });//위
	Q.push({ {sx,sy},{{1,0}, 0} });//아래
	Q.push({ {sx,sy},{{2,0}, 0} });//오른쪽
	Q.push({ {sx,sy},{{3,0}, 0} });//왼쪽
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		if (cur.y.y == 3)
		{
			cout << cur.y.x.y;
			return 0;
		}
		for (int i = 0;i < 4;i++)
		{
			int nx = cur.x.x + dx[i];
			int ny = cur.x.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (arr[nx][ny] == '#')
				continue;
			if (cur.y.x.x != i && v[cur.y.y][i][nx][ny] == 0)
			{
				if (cx1 == nx && cy1 == ny)
				{
						Q.push({ {nx,ny},{{i,cur.y.x.y + 1}, cur.y.y | 1} });
						v[cur.y.y | 1][i][nx][ny] = 1;
				}
				else if (cx2 == nx && cy2 == ny)
				{
					Q.push({ {nx,ny},{{i,cur.y.x.y + 1}, cur.y.y | 2} });
					v[cur.y.y | 2][i][nx][ny] = 1;
				}
				else
				{
					Q.push({ {nx,ny},{{i,cur.y.x.y + 1}, cur.y.y} });
					v[cur.y.y][i][nx][ny] = 1;
				}
			}
		}
	}
	cout << -1;
}