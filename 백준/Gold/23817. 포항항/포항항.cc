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
char arr[1001][1001] = { 0 };
int n, m;
int ans = INF;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int v[21][1001][1001] = { 0 };
vector<pair<int, int>> K;
void bfs(int idx, int x, int y)
{
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	v[idx][x][y] = 0;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (arr[nx][ny] == '.' && v[idx][nx][ny] == INF)
			{
				v[idx][nx][ny] = v[idx][cur.X][cur.Y] + 1;
				Q.push({ nx,ny });
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	memset(v, INF, sizeof(v));
	K.push_back({ 0,0 });
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'S')
			{
				arr[i][j] = '.';
				K[0].X = i;
				K[0].Y = j;
			}
			else if (arr[i][j] == 'K')
			{
				K.push_back({ i,j });
				arr[i][j] = '.';
			}
		}
	}
	for (int i = 0; i < K.size(); i++)
		bfs(i, K[i].X, K[i].Y);
	for (int i = 1; i < K.size(); i++)
	{
		int sum = 0;
		if (v[0][K[i].X][K[i].Y] == INF)
			continue;
		sum += v[0][K[i].X][K[i].Y];
		for (int j = 1; j < K.size(); j++)
		{
			int sum2 = sum;
			if (j == i)
				continue;
			if (v[i][K[j].X][K[j].Y] == INF)
				continue;
			sum2 += v[i][K[j].X][K[j].Y];
			for (int k = 1; k < K.size(); k++)
			{
				int sum3 = sum2;
				if (k == j || k == i)
					continue;
				if (v[j][K[k].X][K[k].Y] == INF)
					continue;
				sum3 += v[j][K[k].X][K[k].Y];
				for (int q = 1; q < K.size(); q++)
				{
					int sum4 = sum3;
					if (q == k || q == j || q == i)
						continue;
					if (v[k][K[q].X][K[q].Y] == INF)
						continue;
					sum4 += v[k][K[q].X][K[q].Y];
					for (int w = 1; w < K.size(); w++)
					{
						int sum5 = sum4;
						if (w == q || w == k || w == j || w == i)
							continue;
						if (v[q][K[w].X][K[w].Y] == INF)
							continue;
						sum5 += v[q][K[w].X][K[w].Y];
						if (ans > sum5)
							ans = sum5;
					}
				}
			}
		}
	}
	if (ans == INF || K.size() < 6)
		cout << -1;
	else
		cout << ans;
}