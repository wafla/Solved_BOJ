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
#define MOD 998244353
#define ll long long
#define pi pair<int,int>
using namespace std;
int n;
vector<vector<int>> adj;
vector<int> v;
vector<int> ans;
vector<bool> visited;
int dp[10001][2] = { 0 };
void solve(int idx)
{
	dp[idx][0] = 0;
	dp[idx][1] = v[idx];
	visited[idx] = 1;
	for (int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];
		if (visited[nxt])
			continue;
		solve(nxt);
		dp[idx][0] += max(dp[nxt][0], dp[nxt][1]);
		dp[idx][1] += dp[nxt][0];
	}
}
void check(int idx, int last)
{
	if (dp[idx][1] > dp[idx][0] && !visited[last])
	{
		ans.push_back(idx);
		visited[idx] = 1;
	}
	for (int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];
		if (nxt == last)
			continue;
		check(nxt, idx);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	adj.resize(n + 1);
	v.resize(n + 1);
	visited.resize(n + 1);

	for (int i = 1; i <= n; i++)
		cin >> v[i];
	for (int i = 1; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	solve(1);
	for (int i = 0; i <= n; i++)
		visited[i] = 0;
	check(1, 0);
	cout << max(dp[1][0], dp[1][1]) << '\n';
    sort(ans.begin(), ans.end());
	for (auto i : ans)
		cout << i << " ";
	cout << '\n';
}
// 참고 : https://hyeo-noo.tistory.com/160