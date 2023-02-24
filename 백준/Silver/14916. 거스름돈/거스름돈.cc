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
int dp[100001] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	dp[2] = 1;
	dp[4] = 2;
	dp[5] = 1;
	for (int i = 6; i <= n; i++)
	{
		int a = dp[i - 2];
		int b = dp[i - 5];
		if (!a && !b)
			continue;
		else if (a && b)
			dp[i] = min(a + 1, b + 1);
		else if (a)
			dp[i] = a + 1;
		else if (b)
			dp[i] = b + 1;
	}
	if (dp[n])
		cout << dp[n] << '\n';
	else
		cout << -1 << '\n';
}