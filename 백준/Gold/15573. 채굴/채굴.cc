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
int arr[1001][1001] = { 0 };
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
bool v[1001][1001];
int n, m, k;
bool solve(int mid)
{
	memset(v, 0, sizeof(v));
	int cnt = 0;
	queue<T> Q;
	for (int i = 0; i < n; i++)
	{
		if (!v[i][0] && arr[i][0] <= mid)
		{
			Q.push({ arr[i][0],{i,0} });
			v[i][0] = 1;
		}
		if (!v[i][m - 1] && arr[i][m - 1] <= mid)
		{
			Q.push({ arr[i][m - 1],{i,m - 1} });
			v[i][m - 1] = 1;
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (!v[n - 1][i] && arr[n - 1][i] <= mid)
		{
			Q.push({ arr[n - 1][i],{n - 1,i} });
			v[n - 1][i] = 1;
		}
	}
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		cnt++;
		if (cnt >= k)
			break;
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.Y.X + dx[i];
			int ny = cur.Y.Y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (arr[nx][ny] <= mid && !v[nx][ny])
			{
				Q.push({ arr[nx][ny],{nx,ny} });
				v[nx][ny] = 1;
			}
		}
	}
	if (cnt >= k)
		return 1;
	else
		return 0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> k;
	for (int i = n - 1; i >= 0; i--)
		for (int j = m - 1; j >= 0; j--)
			cin >> arr[i][j];

	int left = 1, right = 1000000;
	int ans = right;
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (solve(mid))
		{
			right = mid - 1;
			if(ans > mid)
				ans = mid;
		}
		else
			left = mid + 1;
	}
	cout << ans << '\n';
}