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
#define LINF 9223372036854775807
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string s;
	cin >> s;

	int n = s.size();
	vector<int> dp(n, -INF);

	if (s[0] == '+')
		dp[0] = 10;
	else
		dp[0] = 1;

	if (n > 1)
	{
		if (s[0] == '+' && s[1] == '-')
			dp[1] = 11;
	}

	if (n > 2)
	{
		int a = s[0] == '+' ? 10 : 1;
		int b = s[2] == '+' ? 10 : 1;
		if (s[1] == '+')
			dp[2] = a + b;
		else if (s[1] == '-')
			dp[2] = a - b;
	}

	for (int i = 3; i < dp.size(); i++)
	{
		int num = -INF;
		if (s[i] == '+') // 숫자
		{
			if (s[i - 1] == '+') // 연산자
			{
				if (dp[i - 2] != -INF)
					num = max(num, dp[i - 2] + 10);
			}
			else if (s[i - 1] == '-')
			{
				if (dp[i - 2] != -INF)
					num = max(num, dp[i - 2] - 10);
			}
		}
		else if (s[i] == '-') // +-, --, ++-, -+-
		{
			if (s[i - 1] == '+')
			{
				if (dp[i - 2] != -INF)
					num = max(num, dp[i - 2] + 1);
				if (s[i - 2] == '+')
				{
					if (dp[i - 3] != -INF)
						num = max(num, dp[i - 3] + 11);
				}
				else if (s[i - 2] == '-')
				{
					if (dp[i - 3] != -INF)
						num = max(num, dp[i - 3] - 11);
				}
			}
			else if (s[i - 1] == '-')
			{
				if (dp[i - 2] != -INF)
					num = max(num, dp[i - 2] - 1);
			}
		}
		dp[i] = num;
	}
	cout << dp[n - 1] << '\n';
}
// 참고 : https://wangdo.tistory.com/14