#include <iostream>
#include <vector>
#include <queue>
#define x first
#define y second
using namespace std;
int v[51][51][1 << 6] = { 0 }, dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
char arr[51][51] = { 0 };
int n, m;
queue < pair<pair<int, int>, pair<int, int>>> Q;//x좌표, y좌표, 열쇠, 답
int bfs(int sx, int sy)
{
	v[sx][sy][0] = 1;
	Q.push({ { sx,sy },{0,0} });
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (int i = 0;i < 4;i++)
		{
			int nx = cur.x.x + dx[i];
			int ny = cur.x.y + dy[i];
			int key = cur.y.x;
			int sum = cur.y.y;
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)//범위 밖
				continue;
			if (arr[nx][ny] == 35)//벽
				continue;
			if (arr[nx][ny] == 46 || arr[nx][ny]=='0')//방문하지 않은 점
			{
				if (v[nx][ny][key] == 0)
				{
					v[nx][ny][key] = 1;
					Q.push({ {nx,ny},{key,sum + 1} });
				}
			}
			else if (arr[nx][ny] >= 97 && arr[nx][ny] <= 102)//열쇠
			{
				if (v[nx][ny][key] == 0)
				{
					v[nx][ny][key] = 1;
					v[nx][ny][key | (1 << (arr[nx][ny]-97))] = 1;
					Q.push({ {nx,ny},{key | (1 << (arr[nx][ny] - 97)),sum + 1}});
				}
			}
			else if (arr[nx][ny] >= 65 && arr[nx][ny] <= 70)//문
			{
				if (v[nx][ny][key] == 0)
				{
					if (key & (1 << arr[nx][ny]-65))
					{
						v[nx][ny][key] = 1;
						Q.push({ {nx,ny},{key,sum + 1} });
					}
				}
			}
			else if (arr[nx][ny] == '1')//탈출
				return cur.y.y + 1;
		}
	}
	return -1;
}
int main()
{
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int sx, sy;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == '0')
			{
				sx = i;
				sy = j;
			}
		}
	}
	cout << bfs(sx,sy);
}