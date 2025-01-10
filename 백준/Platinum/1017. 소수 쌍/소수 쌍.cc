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
#define MAX_NUM 2002
#define N 101
using namespace std;

int n, m;
vector<vector<int>> v(MAX_NUM);
vector<int> a, b;
int R[MAX_NUM] = { 0 };
int check[MAX_NUM] = { 0 };
bool visited[MAX_NUM] = { 0 };

bool dfs(int from) {
	if (from == 0 || visited[from])
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
	int x;
	cin >> x;
	bool is_odd = false;
	if (x % 2) 
		is_odd = true;
	a.push_back(x);
	for (int i = 1; i < n; i++)
	{
		cin >> x;
		if (is_odd) {
			if (x % 2) {
				a.push_back(x);
			}
			else {
				b.push_back(x);
			}
		}
		else
		{
			if (x % 2) {
				b.push_back(x);
			}
			else {
				a.push_back(x);
			}
		}
	}

	if (a.size() != b.size()) {
		cout << -1 << '\n';
		return 0;
	}
    
	for (int i = 2; i <= MAX_NUM; i++) {
		if (check[i] == 0) {
			check[i] = 1;
			for (int j = i * i; j <= MAX_NUM; j += i) {
				check[j] = -1;
			}
		}
	}

	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b.size(); j++) {
			if (check[a[i] + b[j]] == 1) {
				v[i].push_back(j);
			}
		}
	}

	vector<int> ans;
	for (int i = 0; i < v[0].size(); i++) {
		memset(R, -1, sizeof(R));
		int cnt = 1;
		int num_a = 0;
		int num_b = v[0][i];
		R[num_b] = num_a;
		for (int j = 1; j < a.size(); j++) {
			memset(visited, 0, sizeof(visited));
			if (dfs(j))
				cnt++;
		}
		if (cnt == b.size()) {
			ans.push_back(b[num_b]);
		}
	}
	if (ans.empty())
		cout << -1 << '\n';
	else {
		sort(ans.begin(), ans.end());
		for (auto i : ans)
			cout << i << " ";
		cout << '\n';
	}
}
// 참고 : https://everenew.tistory.com/185