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
#define X first
#define Y second
using namespace std;
int num[26] = { 0 };
int v[26] = { 0 };
vector<int> t[26];
int n, m, ans = 0;
void dfs(int x)
{
	if (v[x] == 1)
		return;
	v[x] = 1;
	ans++;
	for (int i = 0;i < t[x].size();i++)
		dfs(t[x][i]);
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0;i < m;i++)
	{
		char x, y;
		cin >> x >> y;
		t[x - 65].push_back(y - 65);
		num[y - 65]++;
	}
	int c;
	cin >> c;
	for (int i = 0;i < c;i++)
	{
		char x;
		cin >> x;
		v[x - 65] = 1;
	}
	int cnt = 0;
	for (int i = 0;i < n;i++)
		if (num[i] == 0 && v[i] == 0)
		{
			dfs(i);
			cnt++;
		}
	cout << ans - cnt;
}