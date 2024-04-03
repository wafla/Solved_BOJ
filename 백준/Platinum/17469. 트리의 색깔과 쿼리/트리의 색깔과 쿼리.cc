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
vector<int> v, p;
vector<set<int>> S;
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
	if (S[a].size() <= S[b].size())
		swap(a, b);
	p[b] = a;
	for (auto i : S[b])
		S[a].insert(i);
	S[b].clear();
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;

	v.resize(n + 1);
	p.resize(n + 1);
	S.resize(n + 1);
	for (int i = 2; i <= n; i++)
	{
		int x;
		cin >> x;
		v[i] = x;
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		S[i].insert(x);
	}

	vector<pi> arr;
	for (int i = 0; i < n - 1 + m; i++)
	{
		int x, y;
		cin >> x >> y;
		arr.push_back({ x,y });
	}
	reverse(arr.begin(), arr.end());
	
	for (int i = 1; i <= n; i++)
		p[i] = i;

	vector<int> ans;
	for (int i = 0; i < n - 1 + m; i++)
	{
		if (arr[i].X == 1)
			merge(arr[i].Y, v[arr[i].Y]);
		else
			ans.push_back(S[find(arr[i].Y)].size());
	}

	reverse(ans.begin(), ans.end());
	for (auto i : ans)
		cout << i << '\n';
}