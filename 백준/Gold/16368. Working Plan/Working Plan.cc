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
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int m, n, w, h;
	cin >> m >> n >> w >> h;
	vector<int> work(m + 1);
	for (int i = 1; i <= m; i++)
		cin >> work[i];
	vector<int> plan(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> plan[i];

	priority_queue<pi> PQ;
	for (int i = 1; i <= m; i++)
		PQ.push({work[i], i});

	vector<vector<int>> ans(m + 1);
	vector<int> day(m + 1);
	stack<pi> st;
	for (int i = 1; i <= n; i++)
	{
		while (plan[i] > 0)
		{
			if (PQ.size() == 0 || i + w - 1 > n)
			{
				cout << -1 << '\n';
				return 0;
			}
			auto cur = PQ.top();
			PQ.pop();
			if (day[cur.Y] > i)
			{
				st.push(cur);
				continue;
			}
			for (int j = i; j < i + w; j++)
				plan[j]--;
			ans[cur.Y].push_back(i);
			day[cur.Y] = i + w + h;
			if (cur.X - w > 0)
				PQ.push({cur.X - w, cur.Y});
			else if (cur.X - w == 0)
				continue;
			else
			{
				cout << -1 << '\n';
				return 0;
			}
		}
		if (plan[i] < 0)
		{
			cout << -1 << '\n';
			return 0;
		}
		while (!st.empty())
		{
			PQ.push(st.top());
			st.pop();
		}
	}

	cout << 1 << '\n';
	for (int i = 1; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
			cout << ans[i][j] << " ";
		cout << '\n';
	}
}
// 참고 : https://cyj893.github.io/algorithm/Algorithm18_18/