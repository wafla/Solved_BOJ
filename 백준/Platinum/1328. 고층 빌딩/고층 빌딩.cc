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
int dp[101][101][101] = { 0 };
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, L, R;
	cin >> n >> L >> R;
	dp[1][1][1] = 1;
	for (int stick = 2; stick <= n; stick++)
		for (int l = 1; l <= L; l++)
			for (int r = 1; r <= R; r++)
				dp[stick][l][r] = (dp[stick - 1][l - 1][r] + dp[stick - 1][l][r - 1] + dp[stick - 1][l][r] * (stick - 2)) % MOD;
	cout << dp[n][L][R] << '\n';
}