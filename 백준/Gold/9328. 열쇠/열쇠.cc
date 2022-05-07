#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <math.h>
#include <memory.h>
#define x first
#define y second
using namespace std;
int h, w, v[103][103] = { 0 }, dx[4] = { -1,0,1,0 }, dy[4] = { 0,1,0,-1 };
char arr[103][103] = { 0 };
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		memset(arr, 0, sizeof(arr));
		memset(v, -1, sizeof(v));
		cin >> h >> w;
		int ans = 0;
		for (int i = 0; i < h+2; i++)
		{
			for (int j = 0; j < w+2; j++)
			{
				if (i == 0 || j == 0 || i == h + 1 || j == w + 1)
					arr[i][j] = '.';
				else
					cin >> arr[i][j];
			}
		}
		string s;
		cin >> s;
		int num = 0;
		if(s[0]!='0')
			for (int i = 0; i < s.size(); i++)
				num += 1 << (s[i] - 96);
		queue<pair<pair<int, int>,int>> Q;//x좌표 y좌표 열쇠
		Q.push({ { 0,0 }, num});
		v[0][0] = num;
		while (!Q.empty())
		{
			auto cur = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.x.x + dx[i];
				int ny = cur.x.y + dy[i];
				if (nx < 0 || ny < 0 || nx > h + 1 || ny > w + 1)
					continue;
				else if (arr[nx][ny] == '.' && cur.y > v[nx][ny])
				{
					v[nx][ny] = cur.y;
					Q.push({ {nx,ny},cur.y });
				}
				else if (arr[nx][ny] >= 'A' && arr[nx][ny] <= 'Z' && cur.y > v[nx][ny])
				{
					if ((1<<(arr[nx][ny]-64)) & cur.y)
					{
						v[nx][ny] = cur.y;
						Q.push({ {nx,ny},cur.y });
					}
				}
				else if (arr[nx][ny] >= 'a' && arr[nx][ny] <= 'z' && cur.y > v[nx][ny])
				{
					cur.y = ((1 << (arr[nx][ny] - 96)) | cur.y);
					v[nx][ny] = cur.y;
					Q.push({ {nx,ny},cur.y });
				}
				else if (arr[nx][ny] == '$' && cur.y > v[nx][ny])
				{
					v[nx][ny] = cur.y;
					arr[nx][ny] = '.';
					Q.push({ {nx,ny},cur.y });
					ans++;
				}
			}
		}
		cout << ans << '\n';
	}
}