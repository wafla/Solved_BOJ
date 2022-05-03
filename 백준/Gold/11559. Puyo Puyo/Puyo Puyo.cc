#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <math.h>
#include <memory.h>
#define x first
#define y second
using namespace std;
char arr[12][6] = { 0 };
int ans = 0, v[12][6] = { 0 }, dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 }, cnt;
int boom(char z, int x, int y)
{
	v[x][y] = 1;
	cnt++;
	if (cnt >= 4)
		return 1;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < 12 && ny >= 0 && ny < 6)
			if (arr[nx][ny] == z && v[nx][ny] == 0)
				if (boom(z, nx, ny) == 1)
					return 1;
	}
	return 0;
}
void remove(char z, int x, int y)
{
	arr[x][y] = '.';
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx>=0 && nx<12 && ny>=0 && ny<6)
			if (arr[nx][ny] == z)
				remove(z, nx, ny);
	}
}
void update()
{
	for (int j = 0; j < 6; j++)
	{
		queue<pair<pair<int, int>,char>> Q;
		for (int i = 11; i >= 0; i--)
		{
			if(arr[i][j]!='.')
				Q.push({ {i,j},arr[i][j] });
		}
		while (!Q.empty())
		{
			auto cur = Q.front();
			Q.pop();
			int nx = cur.x.x;
			while (nx + 1 < 12 && arr[nx + 1][cur.x.y] == '.')
				nx++;
			if (nx == cur.x.x)
				continue;
			else
			{
				arr[nx][cur.x.y] = cur.y;
				arr[cur.x.x][cur.x.y] = '.';
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			cin >> arr[i][j];
	while (1)
	{
		int check = 0;
		queue<pair<int, int>> Q;
		memset(v, 0, sizeof(v));
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{
				cnt = 0;
				if (arr[i][j] == 'R' || arr[i][j] == 'G' || arr[i][j] == 'B' || arr[i][j] == 'P' || arr[i][j] == 'Y')
				{
					if (v[i][j] == 0)
					{
						if (boom(arr[i][j], i, j) == 1)
						{
							check = 1;
							Q.push({ i, j });
						}
					}
				}
			}
		}
		if (check == 1)
		{
			ans++;
			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();
				remove(arr[cur.x][cur.y], cur.x, cur.y);
			}
		}
		else if (check == 0)
			break;
		update();
	}
	cout << ans;
}