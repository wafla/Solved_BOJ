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
#define MAX_NUM 40001
#define N 51
using namespace std;
int dp[MAX_NUM][2] = {0};
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& i : v)
		cin >> i;

	for (int i = 0;i < n;i++) {
		for (int j = 1;j < MAX_NUM;j++) {
			if (dp[j][0] && v[i] - j > 0) {
				dp[v[i] - j][1] = 1;
			}
			if (dp[j][0] && j - v[i] > 0) {
				dp[j - v[i]][1] = 1;
			}
			if (dp[j][0] && v[i] + j < MAX_NUM) {
				dp[v[i] + j][1] = 1;
			}
		}
		dp[v[i]][1] = 1;
		for (int j = 1;j < MAX_NUM;j++) {
			dp[j][0] = dp[j][1];
		}
	}

	int t;
	cin >> t;
	for (int i = 0;i < t;i++) {
		int x;
		cin >> x;
		cout << (dp[x][1] ? "Y " : "N ");
	}
}