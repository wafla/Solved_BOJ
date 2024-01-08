#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<int, pi>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, x;
	cin >> n;
	vector<vector<int>> v(4);
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x > 0)
			v[0].push_back(x); // 남자 양
		else
			v[1].push_back(x); // 남자 음
	}
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (x > 0)
			v[2].push_back(x); // 여자 양
		else
			v[3].push_back(x); // 여자 음
	}
	sort(v[0].begin(), v[0].end());
	sort(v[1].begin(), v[1].end());
	sort(v[2].begin(), v[2].end());
	sort(v[3].begin(), v[3].end());
	
	int cnt = 0, i = 0, j = v[3].size() - 1;
	while (i < v[0].size() && j >= 0)
	{
		if (v[0][i] < abs(v[3][j]))
		{
			cnt++;
			i++;
		}
		j--;
	}
	i = 0, j = v[2].size() - 1;
	while (i < v[1].size() && j >= 0)
	{
		if (abs(v[1][i]) > v[2][j])
		{
			cnt++;
			i++;
		}
		j--;
	}
	cout << cnt << '\n';
}