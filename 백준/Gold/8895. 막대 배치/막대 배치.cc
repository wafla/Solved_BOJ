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
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int dp[21][21][21] = { 0 };
	dp[1][1][1] = 1;
	for (int stick = 2; stick <= 20; stick++)
		for (int l = 1; l <= 20; l++)
			for (int r = 1; r <= 20; r++)
				dp[stick][l][r] = dp[stick - 1][l - 1][r] + dp[stick - 1][l][r - 1] + dp[stick - 1][l][r] * (stick - 2);
	int t;
	cin >> t;
	while (t--)
	{
		int n, l, r;
		cin >> n >> l >> r;
		cout << dp[n][l][r] << '\n';
	}
}
// 참고 : https://everenew.tistory.com/191