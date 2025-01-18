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

int n, maxx = 0;
vector<int> L, J;

void dfs(int idx, int l, int j) {
	if (idx == n || l <= 0)
		return;
	if (j > maxx)
		maxx = j;
	for (int i = idx + 1;i < n;i++) {
		dfs(i, l - L[i], j + J[i]);
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	L.resize(n), J.resize(n);

	for (int i = 0;i < n;i++) {
		cin >> L[i];
	}
	for (int i = 0;i < n;i++) {
		cin >> J[i];
	}

	dfs(-1, 100, 0);
	cout << maxx << '\n';
}