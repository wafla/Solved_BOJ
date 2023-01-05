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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int dp[63] = { 0 };
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i <= 43; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + 1;
	int t;
	cin >> t;
	while (t--)
	{
		int v;
		cin >> v;
		for (int i = 1; i <= 43; i++)
		{
			if (dp[i] > v)
			{
				cout << i - 1 << '\n';
				break;
			}
		}
	}
}
// 참고 : https://atgane.tistory.com/71