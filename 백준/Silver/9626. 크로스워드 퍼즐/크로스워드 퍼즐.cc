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
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<int, pi>
using namespace std;
char arr[101][101] = { 0 };
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			arr[i][j] = (((i + j) % 2) ? '.' : '#');

	int n, m;
	cin >> n >> m;
	int u, l, r, d;
	cin >> u >> l >> r >> d;

	for (int i = u; i < u + n; i++)
		for (int j = l; j < l + m; j++)
			cin >> arr[i][j];

	for (int i = 0; i < n + u + d; i++)
	{
		for (int j = 0; j < m + l + r; j++)
			cout << arr[i][j];
		cout << '\n';
	}
}