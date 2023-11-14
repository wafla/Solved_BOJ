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
	int n, m;
	cin >> n >> m;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int left = 1, right = v[n - 1];
	int ans = 0;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		int sum = 0;
		for (int i = 0; i < n; i++)
			if(v[i] > mid)
				sum += v[i] - mid;
		if (sum >= m)
		{
			if (mid > ans)
				ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << ans << '\n';
}