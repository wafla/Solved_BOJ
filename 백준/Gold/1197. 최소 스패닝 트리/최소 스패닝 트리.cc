#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <deque>
#include <set>
#define x first
#define y second
using namespace std;
int parent[10001] = { 0 };
int find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}
void merge(int u, int v)
{
	u = find(u);
	v = find(v);
	parent[u] = v;
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	int n, m, ans = 0;
	vector<pair<int,pair<int,int>>> edges;//간선 v u
	vector<pair<int, pair<int, int>>> mst;
	cin >> n >> m;
	for (int i = 0;i < m;i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({ c,{a,b} });
	}
	sort(edges.begin(), edges.end());
	for (int i = 1;i <= n;i++)
		parent[i] = i;
	for (int i = 0;i < edges.size();i++)
	{
		auto cur = edges[i];

		if (find(cur.y.x) == find(cur.y.y))//사이클 발생 확인
			continue;

		ans += cur.x;
		mst.push_back(cur);//현재 간선 추가
		merge(cur.y.x, cur.y.y);//연결

		if (mst.size() == n - 1)//다 연결되면 종료
			break;
	}
	cout << ans;
}
//참고: https://4legs-study.tistory.com/111