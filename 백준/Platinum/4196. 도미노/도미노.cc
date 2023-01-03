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
int v, e, r;
vector<vector<int>> vt;
vector<vector<int>> rvt;
vector<vector<int>> scc;
bool visit[100001] = { 0 };
stack<int> st;
int v_num[100001] = { 0 };
int scc_num[100001] = { 0 };
void dfs(int idx)
{
	visit[idx] = 1;
	for (int i = 0; i < vt[idx].size(); i++)
		if (!visit[vt[idx][i]])
			dfs(vt[idx][i]);
	st.push(idx);
}
void dfs_r(int idx, int c)
{
	visit[idx] = 1;
	v_num[idx] = c;
	scc[c].push_back(idx);
	for (int i = 0; i < rvt[idx].size(); i++)
		if (!visit[rvt[idx][i]])
			dfs_r(rvt[idx][i], c);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> v >> e;
		r = 0;
		memset(visit, 0, sizeof(visit));
		memset(v_num, 0, sizeof(v_num));
		memset(scc_num, 0, sizeof(scc_num));
		vt.clear();
		rvt.clear();
		scc.clear();
		vt.resize(v + 1);
		rvt.resize(v + 1);
		for (int i = 0; i < e; i++)
		{
			int x, y;
			cin >> x >> y;
			vt[x].push_back(y);
			rvt[y].push_back(x);
		}
		for (int i = 1; i <= v; i++)
			if (!visit[i])
				dfs(i);
		memset(visit, 0, sizeof(visit));
		while (!st.empty())
		{
			int idx = st.top();
			st.pop();
			if (visit[idx])
				continue;
			scc.resize(++r);
			dfs_r(idx, r - 1);
		}
		for (int i = 1; i <= v; i++)
			for (int j = 0; j < vt[i].size(); j++)
				if (v_num[i] != v_num[vt[i][j]])
					scc_num[v_num[vt[i][j]]] = 1;
		int ans = 0;
		for (int i = 0; i < r; i++)
			if (!scc_num[i])
				ans++;
		cout << ans << '\n';
	}
}