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
#define x first
#define y second
using namespace std;
int n, m, bx, by, rx, ry;
char arr[11][11] = { 0 };
int v[11][11][11][11] = {0};
queue <pair<pair<pair<int, int>, pair<int, int>>, pair<int, int>>> Q;//rx, ry, bx, by, 방향, 횟수
int R_first(int nrx, int nry, int nbx, int nby, int sign_x, int sign_y, int count)
{
	v[nrx][nry][nbx][nby] = 1;
	int check = 0;
	while (nrx + sign_x >= 0 && nrx + sign_x < n && nry + sign_y >= 0 && nry + sign_y < m)
	{
		if (arr[nrx + sign_x][nry + sign_y] == '#')
			break;
		nrx += sign_x;
		nry += sign_y;
		if (arr[nrx][nry] == 'O')
		{
			check = 1;
			break;
		}
	}
	while (nbx + sign_x >= 0 && nbx + sign_x < n && nby + sign_y >= 0 && nby + sign_y < m)
	{
		if (arr[nbx + sign_x][nby + sign_y] == '#')
			break;
		nbx += sign_x;
		nby += sign_y;
		if (arr[nbx][nby] == 'O')
		{
			check = 2;
			break;
		}
	}
	if (nbx == nrx && nby == nry)
	{
		nbx -= sign_x;
		nby -= sign_y;
	}
	if (check == 1)
	{
		cout << count + 1;
		return 1;
	}
	if (check == 0)
	{
		if (v[nrx][nry][nbx][nby] == 0)
		{
			Q.push({ {{nrx,nry},{nbx,nby}},{1,count + 1} });
			Q.push({ {{nrx,nry},{nbx,nby}},{2,count + 1} });
			Q.push({ {{nrx,nry},{nbx,nby}},{3,count + 1} });
			Q.push({ {{nrx,nry},{nbx,nby}},{4,count + 1} });
		}
	}
	return 0;
}
int B_first(int nrx, int nry, int nbx, int nby, int sign_x, int sign_y, int count)
{
	auto cur = Q.front();
	int check = 0;
	v[nrx][nry][nbx][nby] = 1;
	while (nbx + sign_x >= 0 && nbx + sign_x < n && nby + sign_y >= 0 && nby + sign_y < m)
	{
		if (arr[nbx + sign_x][nby + sign_y] == '#')
			break;
		nbx += sign_x;
		nby += sign_y;
		if (arr[nbx][nby] == 'O')
		{
			nbx += sign_x;
			nby += sign_y;
			check = 2;
			break;
		}
	}
	if (check == 2)
		return 0;
	while (nrx + sign_x >= 0 && nrx + sign_x < n && nry + sign_y >= 0 && nry + sign_y< m)
	{
		if (arr[nrx + sign_x][nry + sign_y] == '#')
			break;
		nrx += sign_x;
		nry += sign_y;
		if (arr[nrx][nry] == 'O')
		{
			check = 1;
			break;
		}
	}
	if (nrx  == nbx && nry == nby)
	{
		nrx -= sign_x;
		nry -= sign_y;
	}
	if (check == 1)
	{
		cout << count + 1;
		return 1;
	}
	if (check == 0)
	{
		if (v[nrx][nry][nbx][nby] == 0)
		{
			Q.push({ {{nrx,nry},{nbx,nby}},{1,count + 1} });
			Q.push({ {{nrx,nry},{nbx,nby}},{2,count + 1} });
			Q.push({ {{nrx,nry},{nbx,nby}},{3,count + 1} });
			Q.push({ {{nrx,nry},{nbx,nby}},{4,count + 1} });
		}
	}
	return 0;
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < m;j++)
		{
			cin >> arr[i][j];
			if (arr[i][j] == 'R')
			{
				rx = i;
				ry = j;
				arr[i][j] = '.';
			}
			else if (arr[i][j] == 'B')
			{

				bx = i;
				by = j;
				arr[i][j] = '.';
			}
		}
	}
	Q.push({ {{rx,ry},{bx,by}},{1,0} });
	Q.push({ {{rx,ry},{bx,by}},{2,0} });
	Q.push({ {{rx,ry},{bx,by}},{3,0} });
	Q.push({ {{rx,ry},{bx,by}},{4,0} });
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		if (cur.x.x.y == cur.x.y.y)//같은 열
		{
			if (cur.y.x == 1)//위
			{
				if (cur.x.x.x < cur.x.y.x)//R 먼저
				{
					int x = R_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, -1, 0, cur.y.y);
					if (x == 1)
						return 0;
				}
				else//B먼저
				{
					int x = B_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, -1, 0, cur.y.y);
					if (x == 1)
						return 0;
				}
			}
			else if (cur.y.x == 2)//아래
			{
				if (cur.x.x.x < cur.x.y.x)//B 먼저
				{
					int x = B_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, 1, 0, cur.y.y);
					if (x == 1)
						return 0;
				}
				else//B먼저
				{
					int x = R_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, 1, 0, cur.y.y);
					if (x == 1)
						return 0;
				}
			}
			else if (cur.y.x == 3)//오른쪽
			{
				int x = B_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, 0, 1, cur.y.y);
				if (x == 1)
					return 0;
			}
			else if (cur.y.x == 4)//왼쪽
			{
				int x = R_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, 0, -1, cur.y.y);
				if (x == 1)
					return 0;
			}
		}
		else if (cur.x.x.x == cur.x.y.x)//같은 행
		{
			if (cur.y.x == 1)//위
			{
				int x = R_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, -1, 0, cur.y.y);
				if (x == 1)
					return 0;
			}
			else if (cur.y.x == 2)//아래
			{
				int x = R_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, 1, 0, cur.y.y);
				if (x == 1)
					return 0;
			}
			else if (cur.y.x == 3)//오른쪽
			{
				if (cur.x.x.y < cur.x.y.y)//B먼저
				{
					int x = B_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, 0, 1, cur.y.y);
					if (x == 1)
						return 0;
				}
				else//R먼저
				{
					int x = R_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, 0, 1, cur.y.y);
					if (x == 1)
						return 0;
				}
			}
			else if (cur.y.x == 4)//왼쪽
			{
				if (cur.x.x.y < cur.x.y.y)//R먼저
				{
					int x = R_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, 0, -1, cur.y.y);
					if (x == 1)
						return 0;
				}
				else
				{
					int x = B_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, 0, -1, cur.y.y);
					if (x == 1)
						return 0;
				}
			}
		}
		else
		{
			if (cur.y.x == 1)//위
			{
				int x = R_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, -1, 0, cur.y.y);
				if (x == 1)
					return 0;
			}
			else if (cur.y.x == 2)//아래
			{
				int x = R_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, 1, 0, cur.y.y);
				if (x == 1)
					return 0;
			}
			else if (cur.y.x == 3)//오른쪽
			{
				int x = R_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, 0, 1, cur.y.y);
				if (x == 1)
					return 0;
			}
			else if (cur.y.x == 4)//왼쪽
			{
				int x = R_first(cur.x.x.x, cur.x.x.y, cur.x.y.x, cur.x.y.y, 0, -1, cur.y.y);
				if (x == 1)
					return 0;
			}
		}
	}
	cout << -1;
}