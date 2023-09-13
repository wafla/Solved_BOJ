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
vector<vector<pi>> v(100001);
vector<bool> visit(100001);
int n, r, q;
int dp[100001] = { 0 };
void dfs(int idx)
{
	if (visit[idx])
		return;
	visit[idx] = 1;
	for (int i = 0; i < v[idx].size(); i++)
	{
		int nx = v[idx][i].X;
		if (!visit[nx])
		{
			dfs(nx);
			dp[idx] += dp[nx];
		}
	}
	dp[idx]++;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> r >> q;
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back({ y,1 });
		v[y].push_back({ x,1 });
	}
	dfs(r);
	for (int i = 0; i < q; i++)
	{
		int x;
		cin >> x;
		cout << dp[x] << '\n';
	}
}