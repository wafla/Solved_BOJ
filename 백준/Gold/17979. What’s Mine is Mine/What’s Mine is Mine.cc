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
int dp[15001] = { 0 };
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int m, n;
	cin >> m >> n;
	vector<int> minerals(m + 1);
	for (int i = 1; i <= m; i++)
		cin >> minerals[i];
	vector<vector<pi>> v(15001);
	int last = 0;
	for (int i = 0; i < n; i++)
	{
		int s, e, t;
		cin >> s >> e >> t;
		if (last < e)
			last = e;
		v[e].push_back({ s,(e - s) * minerals[t] });
	}
	
	for (int i = 1; i <= last; i++)
	{
		dp[i] = dp[i - 1];
		for (int j = 0; j < v[i].size(); j++)
		{
			if (dp[i] < dp[v[i][j].X] + v[i][j].Y)
				dp[i] = dp[v[i][j].X] + v[i][j].Y;
		}
	}
	cout << dp[last] << '\n';
}
// 참고 : https://tunsi-niley.tistory.com/42