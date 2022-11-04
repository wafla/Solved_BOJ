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
	ll x, y;
	int z;
	cin >> x >> y;
	z = y * 100 / x;
	int num = z;
	if (num >= 99)
	{
		cout << -1;
		return 0;
	}
	int left = 0, right = x;
	int mid;
	int ans = -1;
	while (left<=right)
	{
		mid = (left + right) / 2;
		z = 100 * (y + mid) / (x + mid);
		int num2 = z;
		if (num < num2)
			right = mid - 1;
		else
		{
			ans = mid + 1;
			left = mid + 1;
		}
	}
	cout << ans;
}