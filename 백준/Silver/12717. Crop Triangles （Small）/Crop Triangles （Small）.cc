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
	ll n, a, b, c, d, x, y, m;
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> n >> a >> b >> c >> d >> x >> y >> m;
		vector<pair<ll, ll>> v;
		v.push_back({ x,y });
		for (int j = 1; j < n; j++)
		{
			x = (a*x+b)%m;
			y = (c*y+d)%m;
			v.push_back({ x,y });
		}
		int ans = 0;
		for (int q = 0; q < v.size() - 2; q++)
		{
			for (int w = q + 1; w < v.size() - 1; w++)
			{
				for (int e = w + 1; e < v.size(); e++)
				{
					int xx = (v[q].X + v[w].X + v[e].X) % 3;
					int yy = (v[q].Y + v[w].Y + v[e].Y) % 3;
					if (xx == 0 && yy == 0)
						ans++;
				}
			}
		}
		cout << "Case #" << i << ": " << ans << '\n';
	}
}