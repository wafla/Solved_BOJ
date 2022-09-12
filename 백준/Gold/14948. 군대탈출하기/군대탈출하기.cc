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
int n, m, dx[9] = { 1,-1,0,0,2,-2,0,0,0 }, dy[9] = { 0,0,1,-1,0,0,2,-2,0 };
int arr[101][101] = { 0 };
int val[101][101][2] = { 0 };
bool v[101][101] = { 0 };
typedef pair<int, pair<int, int>> T;
void bfs(int sx, int sy, int x)
{
	memset(v, 0, sizeof(v));
	priority_queue<T, vector<T>, greater<T>> Q;
	Q.push({ arr[sx][sy],{sx,sy} });
	int maxx = arr[sx][sy];
	v[sx][sy] = 1;
	val[sx][sy][x] = arr[sx][sy];
	while (!Q.empty())
	{
		auto cur = Q.top();
		Q.pop();
		if (maxx < cur.X)
			maxx = cur.X;
		val[cur.Y.X][cur.Y.Y][x] = maxx;
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.Y.X + dx[i];
			int ny = cur.Y.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (v[nx][ny])
				continue;
			v[nx][ny] = 1;
			Q.push({ arr[nx][ny],{nx,ny} });
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	memset(v, -1, sizeof(v));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	bfs(0, 0, 0);
	bfs(n - 1, m - 1, 1);
	int ans = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 4; k < 9; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;
				int x = max(val[i][j][0], val[nx][ny][1]);
				if (ans > x || ans == -1)
					ans = x;
			}
		}
	}
	cout << ans;
}
// 참고 :  https://sina-sina.tistory.com/77