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
pi arr[21][21];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, flag = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			arr[i][j] = { INF,0 };
			cin >> arr[i][j].X;
		}
	}

	for (int k = 0; k < n; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (k == i || k == j)
					continue;
				if (arr[i][k].X + arr[k][j].X == arr[i][j].X)
					arr[i][j].Y = 1;
				if (arr[i][k].X + arr[k][j].X < arr[i][j].X)
					flag = 1;
			}
		}
	}

	if (flag)
	{
		cout << -1 << '\n';
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if(!arr[i][j].Y)
				ans += arr[i][j].X;
	cout << ans / 2 << '\n';
}