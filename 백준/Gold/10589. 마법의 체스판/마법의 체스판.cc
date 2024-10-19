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
using namespace std;
struct T {
	int a, b, c, d;
};
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m, k = 0;
	cin >> n >> m;
	vector<T> ans;
	for (int i = 2; i <= n; i += 2)
	{
		k++;
		ans.push_back({ i,1,i,m });
	}
	for (int j = 2; j <= m; j += 2)
	{
		k++;
		ans.push_back({ 1,j,n,j });
	}
	cout << k << '\n';
	for (auto &i : ans)
		cout << i.a << " " << i.b << " " << i.c << " " << i.d << '\n';
}