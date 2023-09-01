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
int n, m;
int dist[50002] = { 0 };
int node_cnt[50002] = { 0 };
bool inq[50002];
int minn = INF, maxx = -INF;
vector<pi> v[50002];
int solve()
{
	dist[minn] = 0;
	inq[minn] = 1;
	++node_cnt[minn];
	queue<int> Q;
	Q.push(minn);
	while (Q.size())
	{
		int cur = Q.front();
		Q.pop();
		inq[cur] = 0;
		for (auto i : v[cur])
		{
			int nv = i.X, w = i.Y;
			if (dist[cur] + w > dist[nv]) {
				dist[nv] = dist[cur] + w;
				if (!inq[nv])
				{
					if (++node_cnt[nv] >= maxx)
						return 0;
					inq[nv] = 1;
					Q.push(nv);
				}
			}
		}
	}
	return dist[maxx];
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		v[x].push_back({ y + 1,z });
		maxx = max(maxx, y + 1);
		minn = min(minn, x);
	}

	for (int i = minn; i <= maxx; i++)
		dist[i] = -INF;

	for (int i = minn; i <= maxx; i++)
	{
		v[i].push_back({ i + 1,0 });
		v[i + 1].push_back({ i,-1 });
	}

	cout << solve() << '\n';
}