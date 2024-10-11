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
#define LINF 9223372036854775807
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<int, pi>
using namespace std;
vector<vector<int>> v;
int work[1002] = { 0 };
bool visited[1002] = { 0 };
bool dfs(int idx)
{
	for (int i = 0; i < v[idx].size(); i++)
	{
		int nw = v[idx][i];
		if (visited[nw])
			continue;
		visited[nw] = true;
		if (work[nw] == 0 || dfs(work[nw]))
		{
			work[nw] = idx;
			return true;
		}
	}
	return false;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		for (int j = 0; j < x; j++)
		{
			int y;
			cin >> y;
			v[i].push_back(y);
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 2; j++)
		{
			fill(visited, visited + m + 1, false);
			if (dfs(i))
				cnt++;
		}
	}
	cout << cnt << '\n';
}