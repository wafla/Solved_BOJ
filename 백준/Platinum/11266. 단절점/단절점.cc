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
#define int long long
#define pi pair<int,int>
using namespace std;
vector<vector<int>> arr;
vector<int> ans;
bool check[10001] = { 0 };
int visit[10001] = { 0 };
int cnt = 1;
int dfs(int idx, bool root)
{
	visit[idx] = cnt++;
	int ret = visit[idx];
	int child = 0;

	for (int i = 0; i < arr[idx].size(); i++)
	{
		if (visit[arr[idx][i]])
		{
			ret = min(ret, visit[arr[idx][i]]);
			continue;
		}
		child++;
		int next = dfs(arr[idx][i], false);
		if (!root && next >= visit[idx])
			check[idx] = true;
		ret = min(ret, next);
	}

	if (root && child > 1)
		check[idx] = true;

	return ret;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int v, e;
	cin >> v >> e;
	arr.resize(v + 1);
	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	for (int i = 1; i <= v; i++)
		if (!visit[i])
			dfs(i, true);

	for (int i = 1; i <= v; i++)
		if (check[i])
			ans.push_back(i);

	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i << " ";
	cout << '\n';
}