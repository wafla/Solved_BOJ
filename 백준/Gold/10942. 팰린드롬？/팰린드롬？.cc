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
#define T pair<int, pi>
using namespace std;
bool dp[2001][2001];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> arr(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 1; i <= n; i++)
	{
		dp[i][i] = true;
		if (i < n && arr[i] == arr[i + 1])
			dp[i][i + 1] = true;
	}
	for (int i = 2; i < n; i++)
		for (int j = 1; i + j <= n; j++)
			if (arr[j] == arr[i + j] && dp[j + 1][i + j - 1])
				dp[j][i + j] = true;
	int m, s, e;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e;
		cout << dp[s][e] << '\n';
	}
}