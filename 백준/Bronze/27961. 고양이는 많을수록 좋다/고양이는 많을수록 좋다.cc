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
#include <bitset>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pi pair<int, int>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	ll x, n = 1;
	int ans = 1;
	cin >> x;
	if (x == 0)
	{
		cout << 0 << '\n';
		return 0;
	}
	while (x > n)
	{
		n *= 2;
		ans++;
	}
	cout << ans << '\n';
}