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
#define MOD 1000000000
#define ll long long
#define int long long
#define pi pair<int, int>
using namespace std;
vector<vector<int>> v;
vector<int> p;
vector<bool> exist;
int find(int x)
{
	if (p[x] == x)
		return x;
	return p[x] = find(p[x]);
}
void merge(int a, int b)
{
	a = find(a), b = find(b);
	if (a == b)
		return;
	p[a] = b;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	v.resize(n + 1);
	p.resize(n + 1);
	exist.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}

	vector<int> arr(n);
	for (auto& i : arr)
		cin >> i;
	reverse(arr.begin(), arr.end());
	
	for (int i = 1; i <= n; i++)
		p[i] = i;

	vector<string> ans;
	int group_cnt = 0;
	for (int i = 0; i < n; i++)
	{
		int node = arr[i];
		exist[node] = 1;
		group_cnt++;
		for (int j = 0; j < v[arr[i]].size(); j++)
		{
			int connected_node = v[arr[i]][j];
			if (!exist[connected_node])
				continue;
			if (find(node) == find(connected_node))
				continue;
			else
			{
				merge(arr[i], v[arr[i]][j]);
				group_cnt--;
			}
		}
		if (group_cnt == 1)
			ans.push_back("YES\n");
		else
			ans.push_back("NO\n");
	}

	reverse(ans.begin(), ans.end());
	for (auto i : ans)
		cout << i;
}