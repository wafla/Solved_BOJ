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
#define pi pair<int,int>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	stack<pair<ll,ll>> st;
	ll ans = 0;
	for (int i = 0; i < n; i++)
	{
		ll num;
		cin >> num;
		pair<ll, ll> tmp = { num, 1 };
		while (!st.empty())
		{
			if (st.top().X <= tmp.X)
			{
				ans += st.top().Y;
				if (st.top().X == tmp.X)
					tmp.Y = st.top().Y + 1;
				st.pop();
			}
			else
				break;
		}
		if (!st.empty())
			ans++;
		st.push(tmp);
	}
	cout << ans << '\n';
}
// 참고 : https://chanho0912.tistory.com/39