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
map<int, vector<int>> M;
int root, x, ans = 0;
bool visit[51] = { 0 };
void dfs(int idx)
{
	if (idx == x)
		return;
	if (M[idx].size() == 0)
		ans++;
	visit[idx] = 1;
	for (int i = 0; i < M[idx].size(); i++)
		if (!visit[M[idx][i]])
		{
			if (M[idx][i] == x)
			{
				if (M[idx].size() == 1)
					ans++;
				visit[x] = 1;
			}
			else
				dfs(M[idx][i]);
		}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		if (v[i] == -1)
		{
			root = i;
			continue;
		}
		M[v[i]].push_back(i);
	}
	cin >> x;
	dfs(root);
	cout << ans << '\n';
}