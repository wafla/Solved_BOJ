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
	int n;
	cin >> n;
	priority_queue<pi, vector<pi>, greater<pi>> PQ;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		PQ.push({ y, x });
	}

	priority_queue<pi> ans;
	while (!PQ.empty())
	{
		auto cur = PQ.top();
		PQ.pop();
		if (cur.X > ans.size())
		{
			ans.push({-cur.Y, -cur.X});
		}
		else if (cur.X == ans.size())
		{
			if (cur.Y > -ans.top().X)
			{
				ans.pop();
				ans.push({-cur.Y, -cur.X});
			}
		}
		else
			continue;
	}
	
	int sum = 0;
	while (!ans.empty())
	{
		sum += -ans.top().X;
		ans.pop();
	}
	cout << sum << '\n';
}