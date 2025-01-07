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
#define MAX_NUM 6500
#define N 81
using namespace std;

int n, m;
vector<vector<int>> v(MAX_NUM);
int odd[N][N] = { 0 };
int even[N][N] = { 0 };
int R[MAX_NUM] = { 0 };
int dx[6] = {-1,0,1,-1,0,1};
int dy[6] = {-1,-1,-1,1,1,1};
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

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<string> str(n + 1);
		memset(R, 0, sizeof(R));
		memset(odd, 0, sizeof(odd));
		memset(even, 0, sizeof(even));
		for (int i = 0; i < v.size(); i++)
			v[i].clear();

		int cnt = 1;
		for (int i = 0; i < n; i++) {
			cin >> str[i];
			for (int j = 0; j < m; j++) {
				if (str[i][j] == '.') {
					if (j % 2) {
						odd[i][j] = cnt++;
					}
					else {
						even[i][j] = cnt++;
					}
				}
			}
		}
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (str[i][j] == '.') {
					for (int k = 0; k < 6; k++) {
						int nx = i + dx[k];
						int ny = j + dy[k];
						if (nx < 0 || ny < 0 || nx >= n || ny >= m || str[nx][ny] == 'x')
							continue;
						if (j % 2) {
							v[even[nx][ny]].push_back(odd[i][j]);
						}
						else {
							v[odd[nx][ny]].push_back(even[i][j]);
						}
					}
				}
			}
		}

		int ans = 0;
		for (int i = 0; i < n;i++) {
			for (int j = 0; j < m; j += 2) {
				memset(visited, 0, sizeof(visited));
				if (str[i][j] == '.' && dfs(even[i][j]))
					ans++;
			}
		}
		cout << cnt - ans - 1 << '\n';
	}
}