#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#define X first
#define Y second
using namespace std;
int arr[21][21] = { 0 }, dx[4] = { -1, 0, 0, 1 }, dy[4] = { 0, -1, 1, 0 }, n, ans = 0, babyshark = 2, babyshark_count = 0, Nx, Ny;
int find(int x, int y)
{
	vector <pair <pair<int, int>, int>> eat;
	queue<pair<int, int>> Q;
	int min = 999;
	int vis[21][21] = { 0 };
	vis[x][y] = 1;
	Q.push({ x,y });
	while(!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (int dir = 0; dir < 4; dir++)
		{
			int nx = cur.X + dx[dir];
			int ny = cur.Y + dy[dir];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (vis[nx][ny] > 0 || arr[nx][ny] > babyshark)
				continue;
			vis[nx][ny] = vis[cur.X][cur.Y] + 1;
			if (arr[nx][ny] < babyshark && arr[nx][ny] > 0)
			{
				int dis = vis[nx][ny];
				if (min >= dis)
				{
					min = dis;
					eat.push_back(make_pair(make_pair(min, nx), ny));
				}
			}
			Q.push({ nx,ny });
		}
	}
	if (min != 999)
	{
		sort(eat.begin(), eat.end());
		Nx = eat[0].first.second;
		Ny = eat[0].second;
		babyshark_count++;
		ans += eat[0].first.first - 1;
		arr[x][y] = 0;
		arr[Nx][Ny] = 9;
		if (babyshark_count == babyshark)
		{
			babyshark++;
			babyshark_count = 0;
		}
		return 1;
	}
	else
		return 0;
}
void simulate(int x, int y)
{
	if (find(x, y) > 0)
		simulate(Nx, Ny);
	else
		cout << ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	int x, y;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 9)
			{
				x = i;
				y = j;
			}
		}
	}
	simulate(x, y);
}