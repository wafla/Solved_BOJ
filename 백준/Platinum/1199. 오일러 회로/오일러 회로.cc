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
vector<vector<pi>> adj;
int n;
void solve(int idx)
{
	for (int i = 0; i < adj[idx].size(); i++)
	{
		int check = adj[idx][i].X;
		int next = adj[idx][i].Y;
		if (check)
		{
			for (int j = 0; j < adj[next].size(); j++)
			{
				if (adj[next][j].Y == idx && adj[next][j].X > 0)
				{
					adj[next][j].X--;
					adj[idx][i].X--;
					if (!adj[next][j].X)
						adj[next].erase(adj[next].begin() + j);
					break;
				}
			}
			if (!adj[idx][i].X)
			{
				adj[idx].erase(adj[idx].begin() + i);
				i--;
			}
			solve(next);
		}
	}
	cout << idx + 1 << " ";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	vector<int> tmp(n);
	adj.resize(n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			if (x)
				adj[i].push_back({ x,j });
			tmp[i] += x;
		}

	for (int i = 0; i < n; i++)
	{
		if (tmp[i] % 2 == 1)
		{
			cout << -1 << '\n';
			return 0;
		}
	}

	solve(0);
	cout << '\n';
}