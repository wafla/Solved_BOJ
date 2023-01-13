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
	cin >> n;
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	ll ans = v[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		if (ans > v[i])
		{
			if (ans % v[i])
				ans = (ans / v[i] + 1) * v[i];
		}
		else
			ans = v[i];
	}
	cout << ans << '\n';
}