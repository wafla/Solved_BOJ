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
#include <unordered_map>
#include <tuple>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define LINF 9223372036854775807
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int, int>
using namespace std;
int solve(int a, int m)
{
	if (m == 0) return 1;

	int x = solve(a, m / 2) % MOD;
	if (m % 2 == 1)
		return ((x * x) % MOD) * a % MOD;
	return (x * x) % MOD;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	if (k == 0 || n == k)
	{
		cout << 1 << '\n';
		return 0;
	}
	if (n - k == 1 || k == 1)
	{
		cout << n << '\n';
		return 0;
	}

	int a = 1, b = 1;
	for (int i = n; i >= n - k + 1; i--)
		a = (a * i) % MOD;
	for (int i = 1; i <= k; i++)
		b = (b * i) % MOD;
	cout << ((a % MOD) * solve(b, MOD - 2) % MOD) % MOD << '\n';
}