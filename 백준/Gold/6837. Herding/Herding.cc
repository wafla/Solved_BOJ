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
int n, m, num = 0;
char arr[1001][1001] = { 0 };
bool v[1001][1001] = { 0 };
void bfs(int x, int y)
{
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		// 위에서 오는거
		if (cur.X - 1 >= 0)
		{
			int nx = cur.X - 1;
			int ny = cur.Y;
			if(!v[nx][ny])
				if (arr[nx][ny] == 'S')
				{
					v[nx][ny] = 1;
					Q.push({ nx,ny });
				}
		}
		// 밑에서 오는거
		if (cur.X + 1 < n)
		{
			int nx = cur.X + 1;
			int ny = cur.Y;
			if (!v[nx][ny])
				if (arr[nx][ny] == 'N')
				{
					v[nx][ny] = 1;
					Q.push({ nx,ny });
				}
		}
		// 오른쪽에서 오는거
		if (cur.Y + 1 < m)
		{
			int nx = cur.X;
			int ny = cur.Y + 1;
			if (!v[nx][ny])
				if (arr[nx][ny] == 'W')
				{
					v[nx][ny] = 1;
					Q.push({ nx,ny });
				}
		}
		// 왼쪽에서 오는거
		if (cur.Y - 1 >= 0)
		{
			int nx = cur.X;
			int ny = cur.Y - 1;
			if (!v[nx][ny])
				if (arr[nx][ny] == 'E')
				{
					v[nx][ny] = 1;
					Q.push({ nx,ny });
				}
		}
		// 다음으로 가는거
		int nx = cur.X;
		int ny = cur.Y;
		if (arr[cur.X][cur.Y] == 'N')
			nx--;
		else if (arr[cur.X][cur.Y] == 'S')
			nx++;
		else if (arr[cur.X][cur.Y] == 'E')
			ny++;
		else if (arr[cur.X][cur.Y] == 'W')
			ny--;
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (!v[nx][ny])
		{
			v[nx][ny] = 1;
			Q.push({ nx,ny });
		}
	}
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
			if (!v[i][j])
			{
				num++;
				v[i][j] = 1;
				bfs(i, j);
			}
	cout << num;
}