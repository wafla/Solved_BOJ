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
vector<vector<int>> v;
vector<bool> visited;
vector<bool> good;
int ans = 0;
bool solve(int idx)
{
	visited[idx] = 1;
	bool flag = false;
	for (int i = 0; i < v[idx].size(); i++)
	{
		int nxt = v[idx][i];
		if (visited[nxt])
			continue;
		if (good[nxt])
			flag = true;
		else if (solve(nxt))
			flag = true;
	}
	if (!flag)
		return false;
	if(!good[idx])
		ans++;
	return true;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	v.resize(n + 1);
	visited.resize(n + 1);
	good.resize(n + 1);
	for (int i = 1; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		good[x] = 1;
	}

	for (int i = 1; i <= n; i++)
		if (good[i])
			solve(i);
	cout << ans + k << '\n';
}
// 참고 : https://tjdahr25.tistory.com/26