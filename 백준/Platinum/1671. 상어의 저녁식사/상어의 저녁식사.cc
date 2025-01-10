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
#define MAX_NUM 52
#define N 101
using namespace std;

int n, m;
vector<vector<int>> v(MAX_NUM);
vector<int> a, b;
int R[MAX_NUM] = { 0 };
bool visited[MAX_NUM] = { 0 };

bool dfs(int from) {
	for (int i = 0; i < v[from].size(); i++) {
		int to = v[from][i];
		if (visited[to])
			continue;
		visited[to] = true;
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
	vector<pair<int, pi>> arr(n);
	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		arr[i].X = x;
		arr[i].Y = { y,z };
	}
	sort(arr.begin(), arr.end(), greater<>());

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (arr[i].X == arr[j].X && arr[i].Y.X == arr[j].Y.X && arr[i].Y.Y == arr[j].Y.Y) {
				v[i].push_back(j);
			}
			else if (arr[i].X >= arr[j].X && arr[i].Y.X >= arr[j].Y.X && arr[i].Y.Y >= arr[j].Y.Y) {
				v[i].push_back(j);
			}
			else if (arr[i].X <= arr[j].X && arr[i].Y.X <= arr[j].Y.X && arr[i].Y.Y <= arr[j].Y.Y) {
				v[j].push_back(i);
			}
		}
	}

	memset(R, -1, sizeof(R));
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2; j++) {
			memset(visited, 0, sizeof(visited));
			if (dfs(i))
				ans++;
		}
	}
	cout << n - ans << '\n';
}