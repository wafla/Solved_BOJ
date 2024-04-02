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
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& i : v)
		cin >> i;

	int ans = 0, maxx = v[0], last = v[0];
	for (int i = 1; i < n; i++)
	{
		if (v[i] < maxx)
		{
			if (v[i] < last)
			{
				ans += last - v[i];
				last = v[i];
			}
			else if (v[i] == last)
				continue;
			else if (v[i] > last)
				last = v[i];
		}
		else if (v[i] == maxx)
		{
			last = v[i];
		}
		else if(v[i] > maxx)
		{
			ans += v[i] - maxx;
			maxx = v[i];
			last = v[i];
		}
	}
	cout << ans << '\n';
}