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
ll dp[1000001] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b, d, n, ans = 1, sum = 0;
	cin >> a >> b >> d >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		if (i >= b)
		{
			sum -= dp[i - b] - 1000;
			sum %= 1000;
		}
		if (i >= a)
		{
			sum += dp[i - a];
			sum %= 1000;
		}
		dp[i] = sum;
		ans += dp[i];
		if (i >= d)
		{
			ans -= dp[i - d] - 1000;
			ans %= 1000;
		}
	}
	cout << ans << '\n';
}
// 참고 : https://nnnlog.tistory.com/66