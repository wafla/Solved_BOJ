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
#define MAX_NUM 30001
#define N 21
using namespace std;

int parent[MAX_NUM] = { 0 };
int sum[MAX_NUM] = { 0 };
int cnt[MAX_NUM] = { 0 };
int dp[MAX_NUM][2] = {};
int n, m, k;

int find(int x) {
	if (parent[x] == x)
		return x;
	return parent[x] = find(parent[x]);
}

void merge(int a, int b) {
	int pa = find(a);
	int pb = find(b);
	if (pa > pb)
		swap(pa, pb);
	parent[pb] = pa;
	sum[pa] += sum[pb]; sum[pb] = 0;
	cnt[pa] += cnt[pb]; cnt[pb] = 0;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> m >> k;
	iota(parent, parent + MAX_NUM, 0);

	for (int i = 1; i <= n; i++) {
		cin >> sum[i];
		cnt[i] = 1;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b)) {
			merge(a, b);
		}
	}

	vector<pi> v;
	for (int i = 1; i <= n; i++) {
		if (parent[i] == i) {
			v.push_back({ sum[i], i });
		}
	}
	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < v.size(); i++) {
		int tmp = cnt[v[i].Y];
		for (int j = 1; j < k; j++) {
			int num = tmp + j;
			if (num >= k)
				break;
			dp[num][1] = max(dp[num][1], dp[num - tmp][0] + v[i].X);
		}
		if (tmp >= k)
			continue;
		dp[tmp][1] = max(dp[tmp][1], v[i].X);

		for (int j = 1; j < k; j++) {
			dp[j][0] = dp[j][1];
		}
	}

	cout << dp[k - 1][1] << '\n';
}