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
	int n, b, a;
	cin >> n >> b >> a;
	vector<int> v(n);
	for (auto& i : v)
		cin >> i;
	sort(v.begin(), v.end());

	int sum = 0, ans = 0;
	for (int i = 0; i < a; i++)
	{
		sum += v[i] / 2;
		if (sum <= b)
			ans = max(ans, i + 1);
	}
	for (int i = a; i < n; i++)
	{
		sum -= v[i - a] / 2;
		sum += v[i - a];
		sum += v[i] / 2;
		if (sum <= b)
			ans = max(ans, i + 1);
	}
	cout << ans << '\n';
}