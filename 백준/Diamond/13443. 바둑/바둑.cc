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
#define N 51
using namespace std;

int n, m;
vector<vector<int>> v(MAX_NUM);
int R[MAX_NUM] = { 0 };
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
bool visited[MAX_NUM] = { 0 };

bool dfs(int from) {
	if (visited[from])
		return false;
	visited[from] = true;

	for (int i = 0; i < v[from].size(); i++) {
		int to = v[from][i];
		if (R[to] == -1 || dfs(R[to])) {
			R[to] = from;
			return true;
		}
	}
	return false;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n;
	vector<string> str(n);
	for (int i = 0; i < n; i++)
		cin >> str[i];

	int cnt = 0, total = n * n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (str[i][j] == 'o') {
				cnt++;
				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n)
						continue;
					if (str[nx][ny] == '.') {
						v[cnt - 1].push_back(nx * n + ny);
					}
				}
			}
			else if (str[i][j] == 'x') {
				total--;
			}
		}
	}

	int ans = 0;
	memset(R, -1, sizeof(R));
	for (int i = 0; i < cnt; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i))
			ans++;
	}
	cout << total - ans << '\n';
}