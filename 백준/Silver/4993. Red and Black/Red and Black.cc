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
#define INF 987654321
#define MOD 1000000007
#define ll long long
using namespace std;
char arr[21][21] = { 0 };
bool v[21][21] = { 0 };
int n, m;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	while (1)
	{
		cin >> m >> n;
		if (n == 0 && m == 0)
			break;
		memset(arr, 0, sizeof(arr));
		memset(v, 0, sizeof(v));
		queue<pair<int, int>> Q;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
				if (arr[i][j] == '@')
				{
					v[i][j] = 1;
					Q.push({ i,j });
				}
			}
		}
		int ans = 1;
		while (!Q.empty())
		{
			auto cur = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;
				if (v[nx][ny] || arr[nx][ny] == '#')
					continue;
				v[nx][ny] = 1;
				Q.push({ nx,ny });
				ans++;
			}
		}
		cout << ans << '\n';
	}
}