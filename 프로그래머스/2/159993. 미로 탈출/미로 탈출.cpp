#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define pi pair<int,int>
#define X first
#define Y second
using namespace std;
bool v1[101][101] = { 0 };
bool v2[101][101] = { 0 };
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
int solution(vector<string> maps) {
	pi s;
	for (int i = 0; i < maps.size(); i++)
		for (int j = 0; j < maps[i].size(); j++)
			if (maps[i][j] == 'S')
				s = { i,j };

	queue<pair<pi, pi>> Q; // 시간, 레버 상태, x, y
	Q.push({ {0,0},{s.X,s.Y} });
	v1[s.X][s.Y] = 1;
    cout << s.X << " " << s.Y << '\n';
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		int time = cur.X.X;
		int flag = cur.X.Y;
		int x = cur.Y.X;
		int y = cur.Y.Y;
		if (maps[x][y] == 'E' && flag)
			return time;
		if (flag == 0)
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < maps.size() && ny < maps[0].size())
				{
					if (maps[nx][ny] == 'O' || maps[nx][ny] == 'S' || maps[nx][ny] == 'L' || maps[nx][ny] == 'E')
					{
						if (!v1[nx][ny])
						{
							v1[nx][ny] = 1;
							if (maps[nx][ny] == 'L')
								Q.push({ {time + 1,1},{nx,ny} });
							else
								Q.push({ {time + 1,0},{nx,ny} });
						}
					}
				}
			}
		}
		else if (flag == 1)
		{
			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < maps.size() && ny < maps[0].size())
				{
					if (maps[nx][ny] == 'O' || maps[nx][ny] == 'S' || maps[nx][ny] == 'L' || maps[nx][ny] == 'E')
					{
						if (!v2[nx][ny])
						{
							v2[nx][ny] = 1;
							Q.push({ {time + 1,1},{nx,ny} });
						}
					}
				}
			}
		}
	}
	return -1;
}