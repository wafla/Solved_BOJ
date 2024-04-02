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
#define int long long
#define pi piar<int, int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, x;
	cin >> n >> x;

	int ans = 0, maxx = x, last = x;
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		if (x < maxx)
		{
			if (x < last)
			{
				ans += last - x;
				last = x;
			}
			else if (x == last)
				continue;
			else if (x > last)
				last = x;
		}
		else if (x == maxx)
			last = x;
		else if(x > maxx)
		{
			ans += x - maxx;
			maxx = x;
			last = x;
		}
	}
	cout << ans << '\n';
}