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
#define MAX_NUM 1300
using namespace std;

int n, m;
vector<vector<int>> v(MAX_NUM);
int col[51][51] = { 0 };
int row[51][51] = { 0 };
int L[MAX_NUM] = { 0 };
int R[MAX_NUM] = { 0 };
bool visited[MAX_NUM] = { 0 };

bool dfs(int from) {
	if (visited[from])
		return false;
	visited[from] = true;
	
	for (int i = 0; i < v[from].size(); i++) {
		int to = v[from][i];
		if (R[to] == -1 || dfs(R[to])) {
			L[from] = to;
			R[to] = from;
			return true;
		}
	}
	return false;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	vector<string> str(n + 1);
	for (int i = 0; i < n; i++) 
		cin >> str[i];

	int cnt = 0;
	bool flag = true;
	for (int i = 0; i < n; i++) {
		if (flag) {
			cnt++;
			flag = false;
		}
		for (int j = 0; j < m; j++) {
			if (str[i][j] == '*') {
				row[i][j] = cnt;
				flag = true;
			}
			else {
				if (flag) {
					cnt++;
					flag = false;
				}
			}
		}
	}

	int tmp = cnt;
	cnt = 0;
	flag = true;
	for (int i = 0; i < m; i++) {
		if (flag) {
			cnt++;
			flag = false;
		}
		for (int j = 0; j < n; j++) {
			if (str[j][i] == '*') {
				col[j][i] = cnt;
				flag = true;
			}
			else {
				if (flag) {
					cnt++;
					flag = false;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (row[i][j] != 0)
				v[row[i][j]].push_back(col[i][j]);
		}
	}

	cnt = max(tmp, cnt);
	memset(L, -1, sizeof(L));
	memset(R, -1, sizeof(R));

	int ans = 0;
	for (int i = 1; i <= cnt; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i))
			ans++;
	}
	cout << ans << '\n';
}
// 참고 : https://www.crocus.co.kr/750