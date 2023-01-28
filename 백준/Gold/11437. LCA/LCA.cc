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
int n, m;
vector<int> node[50001];
bool chk[50001];
int parent[50001] = { 0 };
int depth[50001] = { 0 };
int LCA(int u, int v)
{
	if (depth[u] > depth[v])
		swap(u, v);
	while (depth[u] != depth[v])
		v = parent[v];
	while (u != v)
	{
		u = parent[u];
		v = parent[v];
	}
	return u;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	}
	queue<int> Q;
	Q.push(1);
	depth[1] = 1;
	chk[1] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (int i = 0; i < node[cur].size(); i++)
		{
			int x = node[cur][i];
			if (!chk[x])
			{
				chk[x] = 1;
				depth[x] = depth[cur] + 1;
				parent[x] = cur;
				Q.push(x);
			}
		}
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		cout << LCA(u, v) << '\n';
	}
}
// 참고 : https://cocoon1787.tistory.com/328