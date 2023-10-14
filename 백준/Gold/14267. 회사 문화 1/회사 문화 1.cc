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
int n, m;
vector<vector<int>> adj;
bool visited[100001] = { 0 };
int arr[100001] = { 0 }, dp[100001] = { 0 };
void dfs(int idx, int num)
{
	visited[idx] = 1;
	dp[idx] = arr[idx] + num;
	for (int i = 0; i < adj[idx].size(); i++)
	{
		int nxt = adj[idx][i];
		if (visited[nxt])
			continue;
		dfs(nxt, dp[idx]);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	adj.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		if (x == -1)
			continue;
		adj[x].push_back(i);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a] += b;
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++)
		cout << dp[i] << " ";
	cout << '\n';
}