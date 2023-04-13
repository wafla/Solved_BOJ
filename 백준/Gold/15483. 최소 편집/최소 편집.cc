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
int dp[1002][1002] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string s, t;
	cin >> s >> t;
	for (int i = 0; i <= s.size(); i++)
		dp[i][0] = i;
	for (int i = 0; i <= t.size(); i++)
		dp[0][i] = i;
	for (int i = 1; i <= s.size(); i++)
	{
		for (int j = 1; j <= t.size(); j++)
		{
			if (s[i - 1] == t[j - 1])
				dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1]));
			else
				dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
		}
	}
	cout << dp[s.size()][t.size()] << '\n';
}