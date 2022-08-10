#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;
int n, m, edge[MAX] = { 0 };
vector<int> adjust[MAX], ans;
bool v[MAX] = { 0 };
void dfs(int x)
{
	v[x] = 1;
	for (int i = 0;i < adjust[x].size();i++)
	{
		int next = adjust[x][i];
		if (v[next] == 0)
			dfs(next);
	}
	ans.push_back(x);
}
int main()
{
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	for (int i = 0;i < m;i++)
	{
		int x, y;
		cin >> x >> y;
		adjust[x].push_back(y);
		edge[y]++;
	}
	for (int i = 1;i <= n;i++)
		if (!edge[i])
			dfs(i);
	reverse(ans.begin(), ans.end());
	for (int i = 0;i < ans.size();i++)
		cout << ans[i] << " ";
}