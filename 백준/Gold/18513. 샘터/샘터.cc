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
map<int, int> M;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int ans = 0, cnt = 0;
	queue<pi> Q;
	for (int i = 0; i < n; i++)
	{
		Q.push({ v[i], 0 });
		M[v[i]] = 1;
	}
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		if (cnt < n + k)
			cnt++;
		else
			break;
		ans += cur.Y;
		if (!M[cur.X + 1])
		{
			M[cur.X + 1] = 1;
			Q.push({ cur.X + 1, cur.Y + 1 });
		}
		if (!M[cur.X - 1])
		{
			M[cur.X - 1] = 1;
			Q.push({ cur.X - 1,cur.Y + 1 });
		}
	}
	cout << ans << '\n';
}