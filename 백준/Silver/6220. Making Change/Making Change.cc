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
	int c, n;
	cin >> c >> n;
	vector<int> v(n), dp(c + 1);
	for (auto& i : v)
		cin >> i;
	sort(v.begin(), v.end());
	for (int i = 1; i <= c; i++)
		dp[i] = INF;
	for (int i = 0; i < n; i++)
		for (int j = 1; j <= c; j++)
			if (j >= v[i])
				dp[j] = min(dp[j], dp[j - v[i]] + 1);
	cout << dp[c] << '\n';
}