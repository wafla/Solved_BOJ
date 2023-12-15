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
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m, t;
	cin >> n >> m >> t;
	pi ans = { 0, t };
	for (int i = 0; i <= t / n; i++)
	{
		for (int j = 0; j <= t / m; j++)
		{
			if (i * n + j * m > t)
				break;
			int x = t - i * n - j * m;
			if (ans.Y > x)
				ans = { i + j , x };
			else if (ans.Y == x && i + j > ans.X)
				ans = { i + j , x };
		}
	}
	cout << ans.X << " " << ans.Y << '\n';
}