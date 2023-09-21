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
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, c;
	cin >> n >> c;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	
	int start = 1, end = v[n - 1] - v[0], ans = 0;
	while (start <= end)
	{
		int mid = start + (end - start) / 2;
		int cnt = 1;
		int prev = v[0];
		for (int i = 1; i < n; i++)
		{
			if (v[i] - prev >= mid)
			{
				cnt++;
				prev = v[i];
			}
		}
		if (cnt >= c)
		{
			ans = max(ans, mid);
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	cout << ans << '\n';
}