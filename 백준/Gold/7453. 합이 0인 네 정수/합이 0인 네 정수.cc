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
#define LINF 9223372036854775807
#define MOD 10000000000
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<pi, int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> a(n), b(n), c(n), d(n);
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i] >> c[i] >> d[i];

	vector<int> v1, v2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			v1.push_back(a[i] + b[j]);
			v2.push_back(c[i] + d[j]);
		}
	}

	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	int ans = 0;
	for (int i = 0; i < v1.size(); i++)
	{
		int num = v1[i];
		int idx = lower_bound(v2.begin(), v2.end(), -num) - v2.begin();
		int ridx = upper_bound(v2.begin(), v2.end(), -num) - v2.begin();
		if (idx < v2.size())
		{
			int w = num + v2[idx];
			if (w == 0)
				ans+=ridx-idx;
		}
		if (idx > 0)
		{
			int w = num + v2[idx - 1];
			if (w == 0)
				ans+=ridx-idx;
		}
	}
	cout << ans << '\n';
}