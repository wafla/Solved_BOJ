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
#define MOD 987654321
#define ll long long
using namespace std;
ll dp[10001] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	dp[0] = 1;
	dp[2] = 1;
	for (int i = 4; i <= n; i += 2)
	{
		ll sum = 0;
		for (int j = i - 2; j >= 0; j -= 2)
        {
            sum += (dp[j] * dp[i - j - 2]) % MOD;
            sum %= MOD;
        }
		dp[i] = sum;
	}
	cout << dp[n] << '\n';
}
// 참고 : https://for-development.tistory.com/118