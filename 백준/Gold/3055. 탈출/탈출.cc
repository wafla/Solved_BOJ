#include <iostream>
#include <queue>
#define x first
#define y second
using namespace std;
char arr[51][51] = { 0 };
int n, m, v[51][51] = { 0 }, dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
void bfs(int x, int y)
{
	queue<pair<pair<int, int>, pair<int, int>>> Q;//x,y,고슴도치,물
	Q.push({ {x,y},{1,0} });
	v[x][y] = 1;
	for (int i = 0;i < n;i++)
		for (int j = 0;j < m;j++)
			if (arr[i][j] == '*')
				Q.push({ {i,j},{0,1} });
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		if (cur.y.x == 1)//고슴도치
		{
			if (arr[cur.x.x][cur.x.y] == '*')//이동한 뒤 물이 덮침 
				continue;
			else
			{
				for (int i = 0;i < 4;i++)
				{
					int nx = cur.x.x + dx[i];
					int ny = cur.x.y + dy[i];
					if (arr[nx][ny]=='D')
					{
						cout << v[cur.x.x][cur.x.y];
						return;
					}
					if (nx >= n || nx < 0 || ny >= m || ny < 0)
						continue;
					if (arr[nx][ny] == 'X' || arr[nx][ny] == '*')
						continue;
					if (v[nx][ny] == 0)
					{
						Q.push({ {nx,ny},{1,0} });
						v[nx][ny] = v[cur.x.x][cur.x.y] + 1;
					}
				}
			}
		}
		else if (cur.y.y == 1)//물
		{
			for (int i = 0;i < 4;i++)
			{
				int nx = cur.x.x + dx[i];
				int ny = cur.x.y + dy[i];
				if (arr[nx][ny] == '.' || arr[nx][ny] == 'S')
				{
					arr[nx][ny] = '*';
					Q.push({ {nx,ny},{0,1} });
				}
			}
		}
	}
	cout << "KAKTUS";
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	int sx = 0, sy = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'S')
			{
				sx = i;
				sy = j;
			}
		}
	}
	bfs(sx, sy);
}