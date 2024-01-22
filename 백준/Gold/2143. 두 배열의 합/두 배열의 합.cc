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
	int t, n, m;
	cin >> t >> n;
	vector<int> a(n);
	for (auto& i : a)
		cin >> i;
	cin >> m;
	vector<int> b(m);
	for (auto& i : b)
		cin >> i;

	vector<int> v1, v2;
	int tmp;
	for (int i = 0; i < a.size(); i++)
	{
		tmp = a[i];
		v1.push_back(tmp);
		for (int j = i + 1; j < a.size(); j++)
		{
			tmp += a[j];
			v1.push_back(tmp);
		}
	}
	for (int i = 0; i < b.size(); i++)
	{
		tmp = b[i];
		v2.push_back(tmp);
		for (int j = i + 1; j < b.size(); j++)
		{
			tmp += b[j];
			v2.push_back(tmp);
		}
	}
	sort(v2.begin(), v2.end());

	int ans = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		int num = t - v1[i];
		auto x1 = lower_bound(v2.begin(), v2.end(), num);
		if (x1 != v2.end() && *x1 == num)
		{
			auto x2 = upper_bound(v2.begin(), v2.end(), num);
			ans += x2 - x1;
		}
	}
	cout << ans << '\n';
}