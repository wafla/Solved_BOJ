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
int dp[101][10001] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m, sum = 0;
	cin >> n >> m;
	vector<pair<int, int>> v(n+1);
	for (int i = 1; i <= n; i++)
		cin >> v[i].X;
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i].Y;
		sum += v[i].Y;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= sum; j++)
		{
			if (j - v[i].Y >= 0)
				dp[i][j] = max(dp[i][j], dp[i - 1][j - v[i].Y] + v[i].X);
			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
		}
	}
	for (int i = 0; i <= sum; i++)
		if (dp[n][i] >= m)
		{
			cout << i << '\n';
			break;
		}
}
// 참고 : https://cocoon1787.tistory.com/319