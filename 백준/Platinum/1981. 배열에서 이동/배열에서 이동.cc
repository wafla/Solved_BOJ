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
#define pi pair<int,int>
using namespace std;
int arr[101][101] = { 0 };
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int n;
bool bfs(int s, int e)
{
	bool vis[101][101] = { 0 };
	queue<pi> Q;
	Q.push({ 0,0 });
	vis[0][0] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		if (cur.X == n - 1 && cur.Y == n - 1)
			return 1;
		for (int k = 0; k < 4; k++)
		{
			int nx = cur.X + dx[k];
			int ny = cur.Y + dy[k];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n || vis[nx][ny])
				continue;
			if (arr[nx][ny] >= s && arr[nx][ny] <= e)
			{
				vis[nx][ny] = 1;
				Q.push({ nx,ny });
			}
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int Min = INF, Max = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] < Min)
				Min = arr[i][j];
			if (arr[i][j] > Max)
				Max = arr[i][j];
		}
	}
	int ans = INF, s = 0, e = Max - Min, mid;
	while (s <= e)
	{
		mid = (s + e) / 2;
		int flag = 0;
		for (int i = Min; i <= Max; i++)
		{
			if (arr[0][0] >= i && arr[0][0] <= i + mid)
			{
				if (bfs(i, i + mid))
				{
					flag = 1;
					break;
				}
			}
		}
		if (flag)
		{
			if (ans > mid)
				ans = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
	cout << ans << '\n';
}
// 참고 : https://hae-ong.tistory.com/45