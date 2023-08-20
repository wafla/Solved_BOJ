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
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
int n, m;
int arr[201][201] = { 0 };
int dist[201][201] = { 0 };
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= n; j++)
		{
			arr[i][j] = -1;
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}

	for (int i = 0; i < m; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if (arr[x][y] == -1 || arr[x][y] < z)
		{
			arr[x][y] = z;
			arr[y][x] = z;
		}
		if (dist[x][y] == INF || z < dist[x][y])
		{
			dist[x][y] = z;
			dist[y][x] = z;
		}
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	double ans = INF, tmp, len, time;
	for (int s = 1; s <= n; s++)
	{
		tmp = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int edge = arr[i][j];
				if (edge != -1)
				{
					len = edge - (dist[s][j] - dist[s][i]);
					if (len > 0)
					{
						time = len / 2 + dist[s][j];
						tmp = max(time, tmp);
					}
				}
			}
		}
		ans = min(ans, tmp);
	}
	cout << fixed;
	cout.precision(1);
	cout << ans << '\n';
}
// 참고 : https://everenew.tistory.com/169