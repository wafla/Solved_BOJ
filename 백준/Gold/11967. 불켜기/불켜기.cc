#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000009
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<int, pi>
using namespace std;
int arr[101][101] = { 0 };
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
bool visited[101][101] = { 0 };
bool light[101][101] = { 0 };
map <pi, vector<pi>> M;
int n, m;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		M[{a, b}].push_back({ c,d });
	}

	int x = 1, y = 1, ans = 1;
	queue<pi> Q;
	Q.push({ x,y });
	visited[1][1] = 1;
	light[1][1] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (auto i : M[{cur.X, cur.Y}])
		{
			if (!light[i.X][i.Y])
			{
				ans++;
				light[i.X][i.Y] = 1;
				for (int j = 0; j < 4; j++)
				{
					int nx = i.X + dx[j];
					int ny = i.Y + dy[j];
					if (nx <= 0 || ny <= 0 || nx > n || ny > n)
						continue;
					if (visited[nx][ny] && !visited[i.X][i.Y])
					{
						visited[i.X][i.Y] = 1;
						Q.push({ i.X,i.Y });
					}
				}
			}
		}
		for (int k = 0; k < 4; k++)
		{
			int nx = cur.X + dx[k];
			int ny = cur.Y + dy[k];
			if (nx <= 0 || ny <= 0 || nx > n || ny > n)
				continue;
			if (light[nx][ny] && !visited[nx][ny])
			{
				visited[nx][ny] = 1;
				Q.push({ nx,ny });
			}
		}
	}
	cout << ans << '\n';
}