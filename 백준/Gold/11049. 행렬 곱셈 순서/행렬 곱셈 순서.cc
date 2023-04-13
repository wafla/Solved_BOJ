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
int dp[501][501] = { 0 }, arr[501][2] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i][0] >> arr[i][1];
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; i + j <= n; j++)
		{
			dp[j][i + j] = INF;
			for (int k = j; k <= i + j; k++)
				dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j] + arr[j][0] * arr[k][1] * arr[i + j][1]);
		}
	}
	cout << dp[1][n] << '\n';
}
// 참고 : https://cocoon1787.tistory.com/318