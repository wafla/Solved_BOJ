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
	ll a, b, ans = 0;
	cin >> a >> b;
	for (ll i = 1; i <= 1000000; i++)
	{
		ll x = i;
		ll mul = 1;
		while (x * mul <= 1000000)
			dp[x * mul++] += x;
	}
	for (ll i = a; i <= b; i++)
		ans += dp[i];
	cout << ans;
}