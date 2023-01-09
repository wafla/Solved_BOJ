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
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n;
		vector<int> v(n);
		int dp[10001] = { 0 };
		dp[0] = 1;
		for (int i = 0; i < n; i++)
			cin >> v[i];
		cin >> m;
		for (int i = 0; i < n; i++)
			for (int j = v[i]; j <= m; j++)
				dp[j] += dp[j - v[i]];
		cout << dp[m] << '\n';
	}
}