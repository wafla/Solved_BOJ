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
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int arr[101][101] = { 0 };
	int n, x, y;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 10; k++)
				arr[x + j][y + k]++;
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++)
		for (int j = 1; j <= 100; j++)
			if (arr[i][j])
				ans += 1;
	cout << ans << '\n';
}