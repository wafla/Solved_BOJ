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
#define T pair<pi,pi>
#define MAX_NUM 100001
#define N 51
using namespace std;
int dp[N][MAX_NUM] = { 0 };

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int c, n;
	cin >> c >> n;

	vector<pi> a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i].Y >> a[i].X;
	}
	sort(a.begin(), a.end(), greater<>());

	for (int i = 0;i < N;i++) {
		for (int j = 0;j < MAX_NUM;j++) {
			dp[i][j] = INF;
		}
	}

	for (int j = 1;j * a[0].X < MAX_NUM;j++) {
		dp[0][j * a[0].X] = j * a[0].Y;
	}

	for (int i = 1;i < n;i++) {
		int num = a[i].X;
		int val = a[i].Y;
		for (int j = 1;j < MAX_NUM;j++) {
			if (j % num == 0) {
				dp[i][j] = min(dp[i - 1][j], val * (j / num));
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
			if (j - num > 0) {
				dp[i][j] = min(dp[i][j], dp[i][j - num] + val);
			}
		}
	}

	int ans = INF;
	for (int i = c;i < MAX_NUM;i++) {
		ans = min(dp[n - 1][i], ans);
	}
	cout << ans << '\n';
}