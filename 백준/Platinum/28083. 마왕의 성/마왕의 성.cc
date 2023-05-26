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
#include <bitset>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pi pair<ll, ll>
using namespace std;
int n, m;
ll arr[1001][1001] = { 0 }, value[1001][1001] = { 0 }, ans[1001][1001] = { 0 }, height[1001][1001] = { 0 };
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
pi parent[1001][1001];
map<int, vector<pi>> v;
pi Find(int x, int y)
{
	if (parent[x][y].X == -1 && parent[x][y].Y == -1)
		return { x,y };

	return parent[x][y] = Find(parent[x][y].X, parent[x][y].Y);
}
void Union(pi a, pi b)
{
	a = Find(a.X, a.Y);
	b = Find(b.X, b.Y);
	
	if (a == b)
		return;
	
	if (height[a.X][a.Y] < height[b.X][b.Y])
		swap(a, b);
	parent[b.X][b.Y] = a;
	
	if (height[a.X][a.Y] == height[b.X][b.Y])
		height[a.X][a.Y]++;
	value[a.X][a.Y] += value[b.X][b.Y];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> arr[i][j];
			v[arr[i][j]].push_back({ i,j });
		}

	for (int i = 0; i < 1001; i++)
		for (int j = 0; j < 1001; j++)
			parent[i][j].X = parent[i][j].Y = -1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> value[i][j];

	for (auto i = v.begin(); i != v.end(); i++)
	{
		auto cur = *i;
		for (auto j : cur.Y)
		{
			for (int k = 0; k < 4; k++)
			{
				int nx = j.X + dx[k];
				int ny = j.Y + dy[k];
				if (nx < 1 || nx > n || ny < 1 || ny > m)
					continue;
				if (cur.X >= arr[nx][ny])
					Union({ j.X,j.Y }, { nx,ny });
			}
		}
		for (auto j : cur.Y)
		{
			auto cur = Find(j.X, j.Y);
			ans[j.X][j.Y] = value[cur.X][cur.Y];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
}
// 참고 : https://github.com/oVeron0615/baekjoon/blob/main/baekjoon_28083.cpp