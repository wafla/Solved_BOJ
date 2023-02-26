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
	int n;
	ll ans = 1;
	cin >> n;
	map<ll, int> M;
	for (int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		M[x]++;
	}
	ll num = 1;
	for (int i = 0; i < 64; i++)
	{
		if (M[num] > 0)
		{
			int x = M[num] / 2;
			M[num * 2] += x;
		}
		if (M[num * 2] > 0)
			ans = max(ans, num * 2);
		num *= 2;
	}
	cout << ans << '\n';
}