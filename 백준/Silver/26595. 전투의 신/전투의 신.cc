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
	ll n, a, x, b, y;
	cin >> n >> a >> x >> b >> y;
	ll cnt_a, cnt_b;
	ll ans_a = 0, ans_b = 0, maxx = 0;
	for (ll i = 0; i <= n; i++)
	{
		cnt_b = (n - i) / y;
		cnt_a = i / x;
		ll sum = a * cnt_a + b * cnt_b;
		if (maxx < sum)
		{
			maxx = sum;
			ans_a = cnt_a;
			ans_b = cnt_b;
		}
	}
	cout << ans_a << " " << ans_b << '\n';
}