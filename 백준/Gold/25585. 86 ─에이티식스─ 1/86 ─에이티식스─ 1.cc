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
int dx[4] = { -1,-1,1,1 }, dy[4] = { -1,1,-1,1 };
int arr[101][101] = { 0 };
int n, cnt = 0;
bool v[1 << 10][101][101] = { 0 };
void bfs(int sx, int sy)
{
	queue < pair<pair<int, int>, pair<int, int>>> Q; //이동시간, 방문 개수, 좌표
	Q.push({ {0,0},{sx,sy} });
	v[0][sx][sy] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		//cout << cur.X.X << " " << cur.X.Y << " " << cur.Y.X << " " << cur.Y.Y << '\n';
		if (cur.X.Y == (1<<cnt)-1)
		{
			cout << "Undertaker" << '\n' << cur.X.X;
			return;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.Y.X + dx[i];
			int ny = cur.Y.Y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			int key;
			if (arr[nx][ny] >= 65)
				key = (cur.X.Y | (1 << arr[nx][ny] - 65));
			else
				key = cur.X.Y;
			if (v[key][nx][ny])
				continue;
			v[cur.X.Y][nx][ny] = 1;
			v[key][nx][ny] = 1;
			Q.push({ {cur.X.X + 1, key}, {nx, ny} });
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	int sx, sy;
	int num = 65;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 1)
			{
				cnt++;
				arr[i][j] = num++;
			}
			if (arr[i][j] == 2)
			{
				sx = i;
				sy = j;
			}
		}
	}
	int check = (sx + sy) % 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] >= 65 && (i + j) % 2 != check)
			{
				cout << "Shorei";
				return 0;
			}
		}
	}
	bfs(sx, sy);
}