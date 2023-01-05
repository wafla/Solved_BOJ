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
bool visit[100001] = { 0 };
vector<int> v;
map<int, int > M;
int dfs(int idx)
{
	visit[idx] = 1;
	if (!visit[M[v[idx]]])
		return dfs(M[v[idx]]) + 1;
	return 1;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	v.resize(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	vector<int> v2 = v;
	sort(v2.begin(), v2.end());
	int cnt = 0;
	for (int i = 0; i < n; i++)
		M[v2[i]] = cnt++;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (!visit[M[v[i]]])
		{
			int x = dfs(M[v[i]]);
			if (x == 1)
				continue;
			else
				sum += x - 1;
		}
	}
	cout << sum << '\n';
}