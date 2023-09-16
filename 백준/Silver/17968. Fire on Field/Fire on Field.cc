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
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
int dp[1001] = { 0 };
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	dp[0] = 1; dp[1] = 1;
	for (int i = 2; i <= 1000; i++)
	{
		int num = 1;
		while (1)
		{
			int flag = 0;
			for (int k = 1; 2 * k <= i; k++)
			{
				if (num - dp[i - k] == dp[i - k] - dp[i - 2 * k])
				{
					flag = 1;
					break;
				}
			}
			if (flag)
				num++;
			else
			{
				dp[i] = num;
				break;
			}
		}
	}
	cout << dp[n] << '\n';
}