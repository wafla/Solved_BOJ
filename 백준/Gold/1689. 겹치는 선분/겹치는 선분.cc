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
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vector<pi> v;
	priority_queue<int, vector<int>, greater<int>> PQ;
	for (int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	int ans = 1;
	PQ.push(v[0].Y);
	for (int i = 1; i < v.size(); i++)
	{
		while (!PQ.empty() && v[i].X >= PQ.top())
				PQ.pop();
		PQ.push(v[i].Y);
		ans = max(ans, (int)PQ.size());
	}
	cout << ans << '\n';
}