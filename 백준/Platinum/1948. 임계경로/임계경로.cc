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
#define MOD 10000000000
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<pi, int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<vector<pi>> v(n + 1); // 다음 정점, 시간
	vector<vector<pi>> rv(n + 1);
	vector<int> arr(n + 1);
	vector<int> dp(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		v[x].push_back({ y, w });
		rv[y].push_back({ x,w });
		arr[y]++;
	}

	int start, end;
	cin >> start >> end;

	queue<int> Q;
	Q.push(start);
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		int x = cur;
		for (int i = 0; i < v[x].size(); i++)
		{
			int nx = v[x][i].X;
			int nw = v[x][i].Y;
			arr[nx]--;
			if (dp[x] + nw > dp[nx])
				dp[nx] = dp[x] + nw;
			if (!arr[nx])
				Q.push(nx);
		}
	}

	int cnt = 0;
	Q.push(end);
	vector<bool> visited(n + 1);
	visited[end] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		int x = cur;
		for (int i = 0; i < rv[x].size(); i++)
		{
			int nx = rv[x][i].X;
			int nw = rv[x][i].Y;
			if (dp[x] - nw == dp[nx])
			{
				cnt++;
				if (!visited[nx])
				{
					visited[nx] = 1;
					Q.push(nx);
				}
			}
		}
	}
	cout << dp[end] << '\n';
	cout << cnt << '\n';
}