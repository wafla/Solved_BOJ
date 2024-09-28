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
#define MOD 10000000000
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<pi, int>
using namespace std;
int n, m, start, fin;
vector<vector<pi>> v;
vector<vector<pi>> rv;
vector<int> arr;
set<pi> solve()
{
	queue<int> Q;
	Q.push(fin);
	vector<bool> visited(n, 0);
	visited[fin] = 1;
	set<pi> tmp;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		int x = cur;
		for (int i = 0; i < rv[x].size(); i++)
		{
			int nw = rv[x][i].X;
			int nx = rv[x][i].Y;
			if (arr[x] - nw == arr[nx])
			{
				tmp.insert({ x,nx });
				if (!visited[nx])
				{
					visited[nx] = 1;
					Q.push(nx);
				}
			}
		}
	}
	return tmp;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	while (1)
	{
		cin >> n >> m;
		if (!n && !m)
			break;
		v.clear();
		rv.clear();
		arr.clear();

		cin >> start >> fin;

		v.resize(n);
		rv.resize(n);
		arr.resize(n);
		for (int i = 0; i < n; i++)
			arr[i] = INF;
		for (int i = 0; i < m; i++)
		{
			int x, y, w;
			cin >> x >> y >> w;
			v[x].push_back({ w,y });
			rv[y].push_back({ w,x });
		}

		priority_queue<int> PQ;
		PQ.push(start);
		arr[start] = 0;
		while (!PQ.empty())
		{
			int x = PQ.top();
			PQ.pop();
			for (int i = 0; i < v[x].size(); i++)
			{
				int nw = v[x][i].X;
				int nx = v[x][i].Y;
				if (arr[nx] > arr[x] + nw)
				{
					arr[nx] = arr[x] + nw;
					PQ.push(nx);
				}
			}
		}

		set<pi> sa = solve();

		for (int i = 0; i < n; i++)
			arr[i] = INF;
		PQ.push(fin);
		arr[fin] = 0;
		while (!PQ.empty())
		{
			int x = PQ.top();
			PQ.pop();
			for (int i = 0; i < rv[x].size(); i++)
			{
				int nw = rv[x][i].X;
				int nx = rv[x][i].Y;
				pi tmp = { x, nx };
				if (!sa.count(tmp))
				{
					if (arr[nx] > arr[x] + nw)
					{
						arr[nx] = arr[x] + nw;
						PQ.push(nx);
					}
				}
			}
		}

		if (arr[start] == INF)
			cout << -1 << '\n';
		else
			cout << arr[start] << '\n';
	}
}