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
int v, e, k;
vector<int> dist;
vector<pair<int, int>> V[20001];
void dijkstra(int start_node)
{
	dist.assign(v + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start_node });
	dist[start_node] = 0;
	while (!pq.empty())
	{
		int w = -pq.top().X;
		int u = pq.top().Y;
		pq.pop();
		if (dist[u] < w)
			continue;
		for (int i = 0; i < V[u].size(); i++)
		{
			int x = V[u][i].X;
			int y = w + V[u][i].Y;
			if (dist[x] > y)
			{
				pq.push({ -y, x });
				dist[x] = y;
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> v >> e >> k;
	for (int i = 0; i < e; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		V[x].push_back({ y,w });
	}
	dijkstra(k);
	for (int i = 1; i <= v; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
}