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
	ll n, q;
	cin >> n >> q;
	map<ll, ll> M;
	for (int i = 0; i < q; i++)
	{
		int x, tmp, ans;
		cin >> x;
		tmp = x;
		int flag = 0;
		while (tmp > 1)
		{
			if (M[tmp] == 1)
			{
				flag = 1;
				ans = tmp;
			}
			tmp /= 2;
		}
		if (flag)
			cout << ans << '\n';
		else
		{
			M[x] = 1;
			cout << 0 << '\n';
		}
	}
}