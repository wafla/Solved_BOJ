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
int R, C, M, ans = 0;
int arr[101][101] = { 0 };//칸에 몇마리
int sz[101][101] = { 0 };//크기
int speed[101][101] = { 0 };
int dir[101][101] = { 0 };
void fishing(int t)
{
	for (int i = 1; i <= R; i++)
	{
		if (arr[i][t] != 0)
		{
			ans += sz[i][t];
			arr[i][t] = 0;
			sz[i][t] = 0;
			speed[i][t] = 0;
			dir[i][t] = 0;
			break;
		}
	}
}
void del(int i, int j)
{
	arr[i][j] = 0;
	sz[i][j] = 0;
	dir[i][j] = 0;
	speed[i][j] = 0;
}
void simulate()
{
	int tmp[101][101] = { 0 };
	int tsz[101][101] = { 0 };
	int tspeed[101][101] = { 0 };
	int tdir[101][101] = { 0 };
	for (int i = 1; i <= R; i++)
	{
		for (int j = 1; j <= C; j++)
		{
			if (arr[i][j] == 1)
			{
				if (dir[i][j] == 1 || dir[i][j] == 2)//위 아래
				{
					int k = i;
					int x = speed[i][j] % ((R - 1) * 2);
					while (x--)
					{
						if (dir[i][j] == 1)
						{
							k--;
							if (k < 1)
							{
								k+=2;
								dir[i][j] = 2;
							}
						}
						else if (dir[i][j] == 2)
						{
							k++;
							if (k > R)
							{
								k-=2;
								dir[i][j] = 1;
							}
						}
					}
					if (tmp[k][j] == 0)//상어가 없다
					{
						tmp[k][j] = 1;
						tsz[k][j] = sz[i][j];
						tdir[k][j] = dir[i][j];
						tspeed[k][j] = speed[i][j];
						//제거
						del(i, j);
					}
					else if (tmp[k][j] == 1)//상어가 있다
					{
						if (tsz[k][j] > sz[i][j])//원래 있던 상어가 크다
							del(i, j);
						else//원래 있던 상어가 작다
						{
							tmp[k][j] = 1;
							tsz[k][j] = sz[i][j];
							tdir[k][j] = dir[i][j];
							tspeed[k][j] = speed[i][j];
							del(i, j);
						}
					}
				}
				else if (dir[i][j] == 3 || dir[i][j] == 4)//오른쪽 왼쪽
				{
					int k = j;
					int x = speed[i][j] % ((C - 1) * 2);
					while (x--)
					{
						if (dir[i][j] == 4)
						{
							k--;
							if (k < 1)
							{
								k+=2;
								dir[i][j] = 3;
							}
						}
						else if (dir[i][j] == 3)
						{
							k++;
							if (k > C)
							{
								k-=2;
								dir[i][j] = 4;
							}
						}
					}
					if (tmp[i][k] == 0)
					{
						tmp[i][k] = 1;
						tsz[i][k] = sz[i][j];
						tdir[i][k] = dir[i][j];
						tspeed[i][k] = speed[i][j];
						//제거
						del(i, j);
					}
					else if (tmp[i][k] == 1)
					{
						if (tsz[i][k] > sz[i][j])
							del(i, j);
						else
						{
							tmp[i][k] = 1;
							tsz[i][k] = sz[i][j];
							tdir[i][k] = dir[i][j];
							tspeed[i][k] = speed[i][j];
							del(i, j);
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			arr[i][j] = tmp[i][j];
			sz[i][j] = tsz[i][j];
			dir[i][j] = tdir[i][j];
			speed[i][j] = tspeed[i][j];
		}
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	cin >> R >> C >> M;
	for (int i = 0; i < M; i++)
	{
		int r, c, s, d, z;
		cin >> r >> c >> s >> d >> z;
		arr[r][c] = 1;
		sz[r][c] = z;
		speed[r][c] = s;
		dir[r][c] = d;
	}
	for (int t = 1; t <= C; t++)
	{
		fishing(t);
		simulate();
	}
	cout << ans;
}