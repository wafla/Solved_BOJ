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
#define MAX_NUM 550
#define N 101
using namespace std;

int n, m;
vector<vector<int>> v(MAX_NUM);
int arr[N][N] = { 0 };
int r[N][N] = { 0 };
int l[N][N] = { 0 };
int R[MAX_NUM] = { 0 };
bool visited[MAX_NUM] = { 0 };

bool dfs(int from) {
	if (visited[from])
		return false;
	visited[from] = true;
	
	for (int i = 0; i < v[from].size(); i++) {
		int to = v[from][i];
		if (R[to] == 0 || dfs(R[to])) {
			R[to] = from;
			return true;
		}
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	int t;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a - 1][b - 1] = -1;
	}

	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (r[i][j] == 0 && arr[i][j] != -1) {
				int ti = i, tj = j;
				while (ti >= 0 && tj >= 0 && ti < n && tj < n && arr[ti][tj] != -1 && !r[ti][tj]) {
					r[ti][tj] = cnt;
					ti++, tj++;
				}
				cnt++;
			}
		}
	}

	cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (l[i][j] == 0 && arr[i][j] != -1) {
				int ti = i, tj = j;
				while (ti >= 0 && tj >= 0 && ti < n && tj < n && arr[ti][tj] != -1 && !l[ti][tj]) {
					l[ti][tj] = cnt;
					ti++, tj--;
				}
				cnt++;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] != -1) {
				v[l[i][j]].push_back(r[i][j]);
			}
		}
	}
	
	int ans = 0;
	for (int i = 1; i < cnt; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i))
			ans++;
	}

	cout << ans << '\n';
}