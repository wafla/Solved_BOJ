#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <deque>
#include <set>
#define X first
#define Y second
using namespace std;
int n, m;
int arr[51][51] = { 0 };
int water[51][51] = { 0 };
bool visit[51][51] = { 0 };
int maxx = 0, minn=987654321;
int dx[4] = { 0,0,1,-1 }, dy[4] = { -1,1,0,0 };
void bfs(int x, int y, int h)
{
	queue<pair<int, int>> Q;
	Q.push({ x,y });
	visit[x][y] = 1;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		water[cur.X][cur.Y]--;

		for (int i = 0;i < 4;i++)
		{
			int nx = cur.X + dx[i];
			int ny = cur.Y + dy[i];
			if (visit[nx][ny])
				continue;
			if (nx == 0 || nx == n - 1 || ny == 0 || ny == m - 1)
				continue;
			if (arr[nx][ny] + water[nx][ny] == h && water[nx][ny] > 0)//현재 층에 물이 차있고 흘러내리는 경우
			{
				visit[nx][ny] = 1;
				Q.push({ nx,ny });
			}
		}
	}
}
void solve()
{
	for (int h = maxx; h > minn; h--)
	{
		memset(visit, 0, sizeof(visit));//각 높이마다 따로 물 제거
		for (int i = 1;i < n - 1;i++)
		{
			for (int j = 1;j < m - 1;j++)
			{
				if (water[i][j] > 0 && visit[i][j] == 0)//물이 차있고 방문하지 않음
				{
					for (int k = 0;k < 4;k++)
					{
						int nx = i + dx[k];
						int ny = j + dy[k];
						
						if (arr[nx][ny] + water[nx][ny] < arr[i][j] + water[i][j])//현재 칸보다 옆 칸이 더 낮아서 흘러내림
						{
							bfs(i, j, h);
							break;
						}
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1;i < n - 1;i++)
		for (int j = 1;j < m - 1;j++)
			ans += water[i][j];
	cout << ans;
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		string s;
		cin >> s;
		for (int j = 0;j < m;j++)
		{
			arr[i][j] = s[j] - '0';
			if (arr[i][j] > maxx)//물 최대 높이
				maxx = arr[i][j];
			if (arr[i][j] < minn)//물 최저 높이
				minn = arr[i][j];
		}
	}

	for (int i = 1;i < n - 1;i++)//최대 높이까지 물 채우기
		for (int j = 1;j < m - 1;j++)//가장자리는 물 빠져서 채울 필요 없음
			water[i][j] = maxx - arr[i][j];

	solve();
}
//참고 : https://injae-kim.github.io/problem_solving/2020/02/15/baekjoon-1113.html