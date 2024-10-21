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
#define LINF 9223372036854775807
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, val;
	cin >> n;
	vector<int> v(n);
	vector<int> mxL(n), mnL(n), mxR(n), mnR(n);
	for (auto& i : v)
		cin >> i;
	
	for (int i = 0, val = 0; i < n; i++)
	{
		val += v[i];
		mxL[i] = val;
		if (val < 0)
			val = 0;
	}
	for (int i = 0, val = 0; i < n; i++)
	{
		val += v[i];
		mnL[i] = val;
		if (val > 0)
			val = 0;
	}
	for (int i = n - 1, val=0; i >= 0; i--)
	{
		val += v[i];
		mxR[i] = val;
		if (val < 0)
			val = 0;
	}
	for (int i = n - 1, val = 0; i >= 0; i--)
	{
		val += v[i];
		mnR[i] = val;
		if (val > 0)
			val = 0;
	}
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
	{
		ans = max(ans, abs(mxL[i] - mnR[i + 1]));
		ans = max(ans, abs(mnL[i] - mxR[i + 1]));
	}
	cout << ans << '\n';
}
// 참고 : https://measurezero.tistory.com/2167