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
vector<vector<pi>> arr;
vector<priority_queue<int>> ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m, k;
	cin >> n >> m >> k;
	arr.resize(n + 1);
	ans.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[a].push_back({ c,b });
	}
	priority_queue<pi, vector<pi>, greater<pi>> PQ;
	ans[1].push(0);
	PQ.push({ 0, 1 }); // 비용 - 도시
	while (!PQ.empty())
	{
		auto cur = PQ.top();
		PQ.pop();
		for (int i = 0; i < arr[cur.Y].size(); i++)
		{
			int next_city = arr[cur.Y][i].Y;
			int next_cost = arr[cur.Y][i].X + cur.X;
			if (ans[next_city].size() < k)
			{
				ans[next_city].push(next_cost);
				PQ.push({ next_cost,next_city });
			}
			else if(ans[next_city].top() > next_cost)
			{
				ans[next_city].pop();
				ans[next_city].push(next_cost);
				PQ.push({ next_cost,next_city });
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (ans[i].size() < k)
			cout << "-1\n";
		else
			cout << ans[i].top() << '\n';
	}
}