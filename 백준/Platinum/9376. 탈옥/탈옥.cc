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
int h, w, dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int check[3][103][103] = { 0 };
char arr[103][103] = { 0 };
bool v[3][103][103] = { 0 };
typedef pair<int, pair<int, int>> T;
void bfs(int idx, int x, int y)
{
	priority_queue<T, vector<T>, greater<T>> Q;
	Q.push({ 0,{x,y} });
	v[idx][x][y] = 1;
	while (!Q.empty())
	{
		auto cur = Q.top();
		Q.pop();
		check[idx][cur.Y.X][cur.Y.Y] = cur.X;
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.Y.X + dx[i];
			int ny = cur.Y.Y + dy[i];
			if (nx < 0 || nx > h + 1 || ny < 0 || ny > w + 1)
				continue;
			if (v[idx][nx][ny] == 0)
			{
				if (arr[nx][ny] == '.')
				{
					v[idx][nx][ny] = 1;
					Q.push({ cur.X, {nx,ny} });
				}
				else if (arr[nx][ny] == '#')
				{
					v[idx][nx][ny] = 1;
					Q.push({ cur.X + 1, {nx,ny} });
				}
			}
		}
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
		memset(check, 0, sizeof(check));
		memset(v, 0, sizeof(v));
		int sx1, sy1, sx2, sy2, x = 0, ans = INF;
		cin >> h >> w;
		for (int i = 0; i <= h + 1; i++)
		{
			for (int j = 0; j <= w + 1; j++)
			{
				if (i == 0 || j == 0 || i == h + 1 || j == w + 1)
					arr[i][j] = '.';
				else
				{
					cin >> arr[i][j];
					if (arr[i][j] == '$')
					{
						if (x == 0)
						{
							sx1 = i;
							sy1 = j;
							x++;
							arr[i][j] = '.';
						}
						else
						{
							sx2 = i;
							sy2 = j;
							arr[i][j] = '.';
						}
					}
				}
			}
		}
		bfs(0, 0, 0);
		bfs(1, sx1, sy1);
		bfs(2, sx2, sy2);
		for (int i = 1; i < 3; i++)
			for (int j = 0; j <= h + 1; j++)
				for (int k = 0; k <= w + 1; k++)
					check[0][j][k] += check[i][j][k];
		for (int i = 0; i <= h + 1; i++)
			for (int j = 0; j <= w + 1; j++)
				if (arr[i][j] == '#' || ((arr[i][j] == '.' && (i == 1 || j == 1 || i == h || j == w)) && check[0][i][j] == 0))
					ans = min(ans, check[0][i][j]);
		if (ans == 0)
			cout << 0 << '\n';
		else
			cout << ans - 2 << '\n';
	}
}
//참고 : https://everenew.tistory.com/161