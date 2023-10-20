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
bool cmp(pi a, pi b)
{
	if (a.Y > b.Y)
		return 1;
	return 0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vector<pi> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i].X >> v[i].Y;
	sort(v.begin(), v.end(), cmp);

	vector<int> arr(1001);
	for (int i = 0; i < n; i++)
	{
		if (!arr[v[i].X])
			arr[v[i].X] = v[i].Y;
		else
		{
			int idx = v[i].X - 1;
			while (idx > 0)
			{
				if (!arr[idx])
				{
					arr[idx] = v[i].Y;
					break;
				}
				idx--;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= 1000; i++)
		ans += arr[i];
	cout << ans << '\n';
}