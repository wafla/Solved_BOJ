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
#define pi pair<int,int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	int left = x, right = y;
	for (int i = 2; i < n; i++)
	{
		int w;
		cin >> w;
		if (left <= right)
			left += w;
		else
			right += w;
	}
	int maxx = max(left, right);
	int minn = min(left, right);
	int ans = 0;
	while (minn < maxx)
	{
		int num = 0;
		if (maxx - minn >= 100)
			num = 100;
		else if (maxx - minn >= 50)
			num = 50;
		else if (maxx - minn >= 20)
			num = 20;
		else if (maxx - minn >= 10)
			num = 10;
		else if (maxx - minn >= 5)
			num = 5;
		else if (maxx - minn >= 2)
			num = 2;
		else if (maxx - minn >= 1)
			num = 1;
		ans++;
		minn += num;
	}
	cout << ans << '\n';
}