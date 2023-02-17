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
ll arr[33][33] = { 0 }, dp[33][33][3] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	dp[0][1][0] = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (arr[i][j] == 1)
				continue;
			if (arr[i][j + 1] == 0)
				dp[i][j + 1][0] = dp[i][j][0] + dp[i][j][2];
			if (arr[i + 1][j] == 0)
				dp[i + 1][j][1] = dp[i][j][1] + dp[i][j][2];
			if (i + 1 < n && j + 1 < n)
				if (!arr[i + 1][j + 1] && !arr[i + 1][j] && !arr[i][j + 1])
					dp[i + 1][j + 1][2] = dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
		}
	}
	cout << dp[n - 1][n - 1][0] + dp[n - 1][n - 1][1] + dp[n - 1][n - 1][2] << '\n';
}