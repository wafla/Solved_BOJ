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
#define MAX_NUM 5500
#define N 101
using namespace std;

int n, m;
vector<vector<int>> v(MAX_NUM);
int one[N][N] = { 0 };
int two[N][N] = { 0 };
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

	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0, tcnt;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (flag) {
			cnt++;
			flag = false;
		}
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				one[i][j] = cnt;
				flag = true;
			}
			else if (arr[i][j] == 2 && flag) {
				cnt++;
				flag = false;
			}
		}
	}
	tcnt = cnt;

	cnt = 0;
	flag = true;
	for (int j = 0; j < m; j++) {
		if (flag) {
			cnt++;
			flag = false;
		}
		for (int i = 0; i < n; i++) {
			if (arr[i][j] == 0) {
				two[i][j] = cnt;
				flag = true;
			}
			else if (arr[i][j] == 2 && flag) {
				cnt++;
				flag = false;
			}
		}
	}
	tcnt = max(cnt, tcnt);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				v[one[i][j]].push_back(two[i][j]);
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= tcnt; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i))
			ans++;
	}
	cout << ans << '\n'; " ";
}