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
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
int arr[1001][11] = { 0 };
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vector<set<int>> v(n + 1);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 5; j++)
			cin >> arr[i][j];

	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (j == k)
					continue;
				if (arr[j][i] == arr[k][i])
					v[j].insert(k);
			}
		}
	}
	pi ans = { 0,1 };
	for (int i = 1; i <= n; i++)
	{
		if (ans.X < v[i].size())
		{
			ans.X = v[i].size();
			ans.Y = i;
		}
	}
	cout << ans.Y << '\n';
}