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
int parent[100001] = { 0 };
int n, k;
queue<pair<int, int>> Q, q;
int v[2001][2001]; //카운트 문명
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int cnt = 0;
int year = 0;
int find(int x)
{
	if (x == parent[x])
		return x;
	return parent[x] = find(parent[x]);
}
void bfs()
{
	while (1)
	{
		while (!Q.empty()) //문명 합치기
		{
			auto cur = Q.front();
			q.push(Q.front());
			Q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 1 || nx > n || ny < 1 || ny > n)
					continue;
				if (v[nx][ny] != 0 && v[nx][ny] != v[cur.X][cur.Y])
				{
					int x = find(v[cur.X][cur.Y]);
					int y = find(v[nx][ny]);
					if (x != y)
					{
						cnt++;
						if (x < y)
							parent[x] = y;
						else
							parent[y] = x;
					}
				}
			}
		}
		if (cnt == k - 1)
		{
			cout << year;
			return;
		}
		while (!q.empty()) //문명 전파
		{
			auto cur = q.front();
			q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.X + dx[i];
				int ny = cur.Y + dy[i];
				if (nx < 1 || nx > n || ny < 1 || ny > n)
					continue;
				if (v[nx][ny] == 0)
				{
					v[nx][ny] = v[cur.X][cur.Y];
					Q.push({ nx,ny });
				}
				else if (v[nx][ny] != v[cur.X][cur.Y])
				{
					int x = find(v[cur.X][cur.Y]);
					int y = find(v[nx][ny]);
					if (x != y)
					{
						cnt++;
						if (x < y)
							parent[x] = y;
						else
							parent[y] = x;
					}
				}
			}
		}
		year++;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	memset(v, 0, sizeof(v));
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		parent[i + 1] = i + 1;
		v[x][y] = i + 1;
		Q.push({ x,y });
	}
	bfs();
}
//참고 : https://sanghyu.tistory.com/75