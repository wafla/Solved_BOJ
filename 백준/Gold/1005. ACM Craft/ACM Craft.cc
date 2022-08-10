#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <math.h>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
using namespace std;
vector<int> v[1001];
int arr[1001] = { 0 };
int build[1001] = { 0 }; //건설하는데 걸리는 시간
int n, m, last;
void solve()
{
	queue<int> Q;
	for (int i = 1; i <= n; i++)
		if (!arr[i])
			Q.push(i);
	int ans[1001] = { 0 };
	while (!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		if (cur == last)
			break;
		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i];
			arr[next]--;
			ans[next] = max(ans[next], ans[cur] + build[cur]);
			if (!arr[next])
				Q.push(next);
		}
	}
	cout << ans[last] + build[last] << '\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int num, t;
	cin >> t;
	while (t--)
	{
		memset(v, 0, sizeof(v));
		memset(arr, 0, sizeof(arr));
		memset(build, 0, sizeof(build));
		cin >> n >> m;
		for (int i = 1; i <= n; i++)
			cin >> build[i];
		for (int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			v[x].push_back(y);
			arr[y]++;
		}
		cin >> last;
		solve();
	}
}