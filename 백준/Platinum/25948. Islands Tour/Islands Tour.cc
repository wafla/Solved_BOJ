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
bool visited[1000001] = { 0 };
int dp[1000001] = { 0 };
vector<vector<int>> v;
vector<int> arr;
int ans = 1;
pi num;
void solve(vector<int> numbers)
{
	queue<int> Q;
	for (int i = 0; i < numbers.size(); i++)
		Q.push(numbers[i]);
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		visited[cur] = 1;
		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			v[cur].pop_back();
			arr[next]--;
			dp[next] = max(dp[next], dp[cur] + 1);
			ans = max(dp[next] + 1, ans);
			if (!arr[next])
				Q.push(next);
		}
	}
}
void dfs(int x, int cnt)
{
	if (visited[x])
		return;
	visited[x] = 1;
	int connected = dp[x];
	num = { max(connected, num.X), max(cnt, num.Y) };
	for (int i = 0; i < v[x].size(); i++)
	{
		int nx = v[x][i];
		v[x].pop_back();
		dfs(nx, cnt + 1);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int m, n;
	cin >> m >> n;
	if (n == 0)
	{
		cout << "0\n";
		return 0;
	}
	v.resize(n);
	arr.resize(n);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		arr[y]++;
	}

	vector<int> tmp;
	for (int i = 0; i < n; i++)
		if (!arr[i])
			tmp.push_back(i);
	solve(tmp);

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			num = { 0,0 };
			dfs(i, 1);
			ans = max(ans, num.X + num.Y);
		}
	}
	cout << ans << '\n';
}