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
int arr[2][100001] = { 0 };
int dp[2][100001] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		memset(arr, 0, sizeof(arr));
		memset(arr, 0, sizeof(dp));
		for (int i = 0; i < n; i++)
			cin >> arr[0][i];
		for (int i = 0; i < n; i++)
			cin >> arr[1][i];
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		dp[0][1] = max(arr[0][0], arr[0][1] + arr[1][0]);
		dp[1][1] = max(arr[1][0], arr[1][1] + arr[0][0]);
		for (int i = 2; i < n; i++)
		{
			dp[0][i] = max(dp[0][i - 2] + arr[0][i], max(dp[1][i - 1] + arr[0][i], max(dp[0][i - 1], dp[1][i - 1])));
			dp[1][i] = max(dp[1][i - 2] + arr[1][i], max(dp[0][i - 1] + arr[1][i], max(dp[0][i - 1], dp[1][i - 1])));
		}
		cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
	}
}