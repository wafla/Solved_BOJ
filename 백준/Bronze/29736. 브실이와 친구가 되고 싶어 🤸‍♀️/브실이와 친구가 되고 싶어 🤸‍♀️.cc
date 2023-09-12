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
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a, b;
	cin >> a >> b;
	int k, x;
	cin >> k >> x;
	int ans = 0;
	for (int i = k - x; i <= k + x; i++)
		if (i >= a && i <= b)
			ans++;
	if (ans)
		cout << ans << '\n';
	else
		cout << "IMPOSSIBLE\n";
}