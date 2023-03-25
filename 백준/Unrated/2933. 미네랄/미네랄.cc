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
vector<vector<pair<int, int>>> points;
int dx[4] = { 1,-1,0,0 }, dy[4] = { 0,0,1,-1 };
char arr[102][102] = { 0 };
bool v[101][101] = { 0 };
int r, c;
void fall(vector<pair<int, int>> f_arr) // 떨어뜨리기
{
	vector<pair<int, int>> tmp = f_arr;
	for (int i = 0; i < f_arr.size(); i++)
		arr[f_arr[i].X][f_arr[i].Y] = '.';
	int flag = 0;
	while (1)
	{
		for (int i = 0; i < tmp.size(); i++)
		{
			int nx = tmp[i].X + 1;
			if (arr[nx][tmp[i].Y] == 'x' || nx > r)
			{
				flag = 1;
				break;
			}
			tmp[i].X = nx;
		}
		if (flag)
			break;
		f_arr = tmp;
	}
	for (int i = 0; i < f_arr.size(); i++)
		arr[f_arr[i].X][f_arr[i].Y] = 'x';
}
void check() // 덩어리 확인
{
	points.clear();
	memset(v, 0, sizeof(v));
	int num = 0;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (arr[i][j] == 'x' && !v[i][j])
			{
				points.resize(++num);
				queue<pair<int, int>> Q;
				Q.push({ i,j });
				points[num - 1].push_back({ i,j });
				v[i][j] = 1;
				while (!Q.empty())
				{
					auto cur = Q.front();
					Q.pop();
					for (int k = 0; k < 4; k++)
					{
						int nx = cur.X + dx[k];
						int ny = cur.Y + dy[k];
						if (nx < 1 || ny < 1 || nx > r || ny > c)
							continue;
						if (arr[nx][ny] == 'x' && v[nx][ny] == 0)
						{
							v[nx][ny] = 1;
							Q.push({ nx,ny });
							points[num - 1].push_back({ nx,ny });
						}
					}
				}
			}
		}
	}
	int flag;
	for (int i = 0; i < points.size(); i++)
	{
		flag = 0;
		for (int j = 0; j < points[i].size(); j++)
		{
			if (points[i][j].X == r)
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
			fall(points[i]);
	}
}
void smash(int h, int k) // 부수기
{
	int x, y, dx;
	if (k == 0)
	{
		x = 1;
		dx = 1;
	}
	else
	{
		x = c;
		dx = -1;
	}
	y = r - h + 1;
	for (int i = 1; i <= c; i++)
	{
		if (arr[y][x] == 'x')
		{
			arr[y][x] = '.';
			check();
			return;
		}
		x += dx;
	}
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			cin >> arr[i][j];
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		if (i % 2 == 0)
			smash(x, 0);
		else
			smash(x, 1);
	}
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
			cout << arr[i][j];
		cout << '\n';
	}
}