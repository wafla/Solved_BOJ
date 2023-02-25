#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <math.h>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
using namespace std;
bool v[9][9] = { 0 };
int ans[99] = { 0 };
int arr[9][9] = { 0 };
int n, m;
int i, j, a, b;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
bool flag = 0;
void dfs(int x, int y, int cnt)
{
	if (flag)
		return;
	if (cnt == n * m)
	{
		if (x == a && y == b)
		{
			flag = 1;
			return;
		}
		return;
	}
	else if ((x == a && y == b) && cnt < n * m)
		return;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			continue;
		if (v[nx][ny])
			continue;
		ans[cnt] = 10 * x + y;
		v[nx][ny] = 1;
		dfs(nx, ny, cnt + 1);
		v[nx][ny] = 0;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		memset(arr, 0, sizeof(arr));
		memset(v, 0, sizeof(v));
		memset(ans, 0, sizeof(ans));
		flag = 0;
		cin >> n >> m;
		cin >> a >> b;
		cin >> i >> j;
		a--;
		b--;
		i--;
		j--;
		v[i][j] = 1;
		dfs(i, j, 1);
		if (!flag)
			cout << -1 << '\n';
		else
		{
			cout << 1 << '\n';
			for (int i = 1; i < n * m; i++)
				cout << ans[i] / 10 + 1 << " " << ans[i] % 10 + 1 << '\n';
			cout << a + 1 << " " << b + 1 << '\n';
		}
	}
}