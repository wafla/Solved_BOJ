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
	vector<pair<int, int>> v(n);
	ll l_sum = 0, r_sum = 0, minn;
	int ans;
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].X >> v[i].Y;
		r_sum += v[i].Y;
	}
	sort(v.begin(), v.end());
	r_sum -= v[0].Y;
	ans = v[0].X;
	minn = r_sum;
	for (int i = 1; i < n; i++)
	{
		r_sum -= v[i].Y;
		l_sum += v[i - 1].Y;
		if (minn > abs(r_sum - l_sum))
		{
			minn = abs(r_sum - l_sum);
			ans = v[i].X;
		}
	}
	cout << ans;
}