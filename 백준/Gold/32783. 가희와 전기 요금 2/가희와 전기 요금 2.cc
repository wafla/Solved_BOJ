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
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<pi,pi>
#define MAX_NUM 300001
#define N 21
using namespace std;

int dp[MAX_NUM][2] = { 0 };

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	vector<pi> v(n);
	for (auto& i : v) {
		cin >> i.X >> i.Y;
	}

	vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		nums[i] = ((double(v[i].X) / 1000) * (double(v[i].Y) / 60)) * 96;
	}
	sort(nums.begin(), nums.end(), greater<>());

	int c1, c2;
	cin >> c1 >> c2;

	memset(dp, -1, sizeof(dp));
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= c2; j++) {
			if (j + nums[i] <= c2 && dp[j][0] != -1) {
				if (dp[j + nums[i]][0] == -1) 
					dp[j + nums[i]][1] = dp[j][0];
				else
					dp[j + nums[i]][1] += dp[j][0];
			}
			if (j + nums[i] > c2)
				break;
		}
        if (nums[i] > c2)
			continue;
		if (dp[nums[i]][0] == -1)
			dp[nums[i]][1] = 1;
		else
			dp[nums[i]][1]++;

		for (int j = 1; j <= c2; j++) {
			dp[j][0] = dp[j][1] % MOD;
		}
	}

	int ans = 0;
	for (int i = c1; i <= c2; i++) {
		if (dp[i][1] != -1) {
			ans = (ans + dp[i][1]) % MOD;
		}
	}
	cout << ans << '\n';
}