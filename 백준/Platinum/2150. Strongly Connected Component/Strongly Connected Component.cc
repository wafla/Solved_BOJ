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
bool visited[10001] = { 0 };
vector<vector<int>> scc;
vector<vector<int>> vt;
vector<vector<int>> rvt;
stack<int> st;
int v, e, r = 0;
bool cmp(vector<int> x, vector<int> y)
{
	return x[0] < y[0];
}
void dfs(int x)
{
	visited[x] = 1;
	for (int i = 0; i < vt[x].size(); i++)
		if (visited[vt[x][i]] == 0)
			dfs(vt[x][i]);
	st.push(x);
}
void re_dfs(int v, int c)
{
	visited[v] = 1;
	scc[c].push_back(v);
	for (int i = 0; i < rvt[v].size(); i++)
		if (visited[rvt[v][i]] == 0)
			re_dfs(rvt[v][i], c);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> v >> e;
	vt.resize(v + 1);
	rvt.resize(v + 1);
	for (int i = 0; i < e; i++)
	{
		int x, y;
		cin >> x >> y;
		vt[x].push_back(y);
		rvt[y].push_back(x);
	}
	for (int i = 1; i <= v; i++) // 먼저 dfs를 돌려서 끝나는 순서대로 스택에 삽입
		if(visited[i]==0)
			dfs(i);
	memset(visited, 0, sizeof(visited));
	while (st.size()) // 역순으로 dfs 돌리면서 scc 묶기
	{
		int idx = st.top();
		st.pop();
		if (visited[idx])
			continue;
		scc.resize(++r);
		re_dfs(idx, r - 1);
	}
	for (int i = 0; i < r; i++)
		sort(scc[i].begin(), scc[i].end());
	sort(scc.begin(), scc.end(), cmp);
	cout << r << '\n';
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < scc[i].size(); j++)
			cout << scc[i][j] << " ";
		cout << "-1\n";
	}
}
// 참고 : https://jason9319.tistory.com/98