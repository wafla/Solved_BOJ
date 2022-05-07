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
int n, maxx = 0;
int find_max(int arr[][21])
{
	int x = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (arr[i][j] > x)
				x = arr[i][j];
	return x;
}
void move(int arr[][21], int dir, int cnt)
{
	if (cnt == 6)
	{
		int x = find_max(arr);
		if (x > maxx)
			maxx = x;
		return;
	}
	if (dir == 1)//위
	{
		int tmp[21][21] = { 0 };
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				tmp[i][j] = arr[i][j];
		for (int j = 0; j < n; j++)//위로 올리기
		{
			for (int i = 1; i < n; i++)
			{
				if (tmp[i][j] != 0 && tmp[i - 1][j] == 0)
				{
					int k = i;
					while (tmp[k][j] != 0 && tmp[k - 1][j] == 0 && k != 0)
					{
						tmp[k - 1][j] = tmp[k][j];
						tmp[k][j] = 0;
						k--;
					}
				}
			}
		}
		for (int j = 0; j < n; j++)//합치기
		{
			for (int i = 0; i < n - 1; i++)
			{
				if (tmp[i][j] == tmp[i + 1][j])
				{
					tmp[i][j] = 2 * tmp[i][j];
					tmp[i + 1][j] = 0;
					i++;
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int i = 1; i < n; i++)
			{
				if (tmp[i][j] != 0 && tmp[i - 1][j] == 0)
				{
					int k = i;
					while (tmp[k][j] != 0 && tmp[k - 1][j] == 0 && k != 0)
					{
						tmp[k - 1][j] = tmp[k][j];
						tmp[k][j] = 0;
						k--;
					}
				}
			}
		}
		move(tmp, 1, cnt + 1);
		move(tmp, 2, cnt + 1);
		move(tmp, 3, cnt + 1);
		move(tmp, 4, cnt + 1);
	}
	else if (dir == 2)//아래
	{
		int tmp[21][21] = { 0 };
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				tmp[i][j] = arr[i][j];
		for (int j = 0; j < n; j++)//밑으로 내리기
		{
			for (int i = n - 2; i >= 0; i--)
			{
				if (tmp[i][j] != 0 && tmp[i + 1][j] == 0)
				{
					int k = i;
					while (tmp[k][j] != 0 && tmp[k + 1][j] == 0 && k != n - 1)
					{
						tmp[k + 1][j] = tmp[k][j];
						tmp[k][j] = 0;
						k++;
					}
				}
			}
		}
		for (int j = 0; j < n; j++)//합치기
		{
			for (int i = n - 1; i > 0; i--)
			{
				if (tmp[i][j] == tmp[i - 1][j])
				{
					tmp[i][j] = 2 * tmp[i][j];
					tmp[i - 1][j] = 0;
					i--;
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int i = n - 2; i >= 0; i--)
			{
				if (tmp[i][j] != 0 && tmp[i + 1][j] == 0)
				{
					int k = i;
					while (tmp[k][j] != 0 && tmp[k + 1][j] == 0 && k != n - 1)
					{
						tmp[k + 1][j] = tmp[k][j];
						tmp[k][j] = 0;
						k++;
					}
				}
			}
		}
		move(tmp, 1, cnt + 1);
		move(tmp, 2, cnt + 1);
		move(tmp, 3, cnt + 1);
		move(tmp, 4, cnt + 1);
	}
	else if (dir == 3)//오른쪽
	{
		int tmp[21][21] = { 0 };
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				tmp[i][j] = arr[i][j];
		for (int i = 0; i < n; i++)//오른쪽으로 밀기
		{
			for (int j = n - 2; j >= 0; j--)
			{
				if (tmp[i][j] != 0 && tmp[i][j + 1] == 0)
				{
					int k = j;
					while (tmp[i][k] != 0 && tmp[i][k + 1] == 0 && k != n - 1)
					{
						tmp[i][k + 1] = tmp[i][k];
						tmp[i][k] = 0;
						k++;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j > 0; j--)
			{
				if (tmp[i][j] == tmp[i][j - 1])
				{
					tmp[i][j] = 2 * tmp[i][j];
					tmp[i][j - 1] = 0;
					j--;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 2; j >= 0; j--)
			{
				if (tmp[i][j] != 0 && tmp[i][j + 1] == 0)
				{
					int k = j;
					while (tmp[i][k] != 0 && tmp[i][k + 1] == 0 && k != n - 1)
					{
						tmp[i][k + 1] = tmp[i][k];
						tmp[i][k] = 0;
						k++;
					}
				}
			}
		}
		move(tmp, 1, cnt + 1);
		move(tmp, 2, cnt + 1);
		move(tmp, 3, cnt + 1);
		move(tmp, 4, cnt + 1);
	}
	else if (dir == 4)//왼쪽
	{
		int tmp[21][21] = { 0 };
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				tmp[i][j] = arr[i][j];
		for (int i = 0; i < n; i++)//왼쪽으로 밀기
		{
			for (int j = 1; j < n; j++)
			{
				if (tmp[i][j] != 0 && tmp[i][j - 1] == 0)
				{
					int k = j;
					while (tmp[i][k] != 0 && tmp[i][k - 1] == 0 && k != 0)
					{
						tmp[i][k - 1] = tmp[i][k];
						tmp[i][k] = 0;
						k--;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (tmp[i][j] == tmp[i][j + 1])
				{
					tmp[i][j] = 2 * tmp[i][j];
					tmp[i][j + 1] = 0;
					j++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (tmp[i][j] != 0 && tmp[i][j - 1] == 0)
				{
					int k = j;
					while (tmp[i][k] != 0 && tmp[i][k - 1] == 0 && k != 0)
					{
						tmp[i][k - 1] = tmp[i][k];
						tmp[i][k] = 0;
						k--;
					}
				}
			}
		}
		move(tmp, 1, cnt + 1);
		move(tmp, 2, cnt + 1);
		move(tmp, 3, cnt + 1);
		move(tmp, 4, cnt + 1);
	}
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	int arr[21][21] = { 0 };
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	move(arr, 1, 1);//위
	move(arr, 2, 1);//아래
	move(arr, 3, 1);//오른쪽
	move(arr, 4, 1);//왼쪽
	cout << maxx;
}