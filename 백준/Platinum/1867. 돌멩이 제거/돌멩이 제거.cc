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
using namespace std;

int n, k;
vector<vector<int>> v(501);
int bi[501] = { 0 }; // Bipartite Matching
bool visited[501] = { 0 };

bool dfs(int row) {
	if (visited[row])
		return false;
	visited[row] = true;
	
	for (int i = 0; i < v[row].size(); i++) {
		int col = v[row][i];
		if (bi[col] == 0 || dfs(bi[col])) {
			bi[col] = row;
			return true;
		}
	}
	return false;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		if (dfs(i))
			ans++;
	}
	cout << ans << '\n';
}