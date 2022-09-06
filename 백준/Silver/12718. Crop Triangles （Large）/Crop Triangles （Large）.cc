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
ll combination(ll x)
{
	if (x == 0)
		return 0;
	ll a = 1;
	for (int i = 0; i < 3; i++)
		a *= x--;
	return a / 6;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	ll n, a, b, c, d, x, y, m;
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> a >> b >> c >> d >> x >> y >> m;
		ll arr[23] = { 0 }, num[9] = { 0,1,2,10,11,12,20,21,22 };
		arr[(x % 3) * 10 + y % 3]++;
		for (int j = 1; j < n; j++)
		{
			x = (a * x + b) % m;
			y = (c * y + d) % m;
			arr[(x % 3) * 10 + y % 3]++;
		}
		ll ans = 0;
		for (int q = 0; q < 9; q++)
		{
			for (int w = q; w < 9; w++)
			{
				for (int e = w; e < 9; e++)
				{
					if ((num[q] / 10 + num[w] / 10 + num[e] / 10) % 3 == 0 && (num[q] % 10 + num[w] % 10 + num[e] % 10) % 3 == 0)
					{
						if (q == w && w == e)
							ans += combination(arr[num[q]]);
						else
							ans += arr[num[q]] * arr[num[w]] * arr[num[e]];
					}
				}
			}
		}
		cout << "Case #" << i << ": " << ans << '\n';
	}
}