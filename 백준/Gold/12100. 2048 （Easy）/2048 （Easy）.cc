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
#include <bitset>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pi pair<int, int>
using namespace std;
int board[21][21] = { 0 }, value[11] = { 0 };
int n, ans = 0;
int findMax()
{
	int x = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j] > x)
				x = board[i][j];
	return x;
}
bool compare(int(*board)[21], int(*tmp)[21])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j] != tmp[i][j])
				return 1;
	return 0;
}
void copy(int (*board)[21], int (*tmp)[21])
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			tmp[i][j] = board[i][j];
}
void move(int dir)
{
	if (dir == 0)
	{
		for (int j = 0; j < n; j++)//위로 올리기
		{
			for (int i = 1; i < n; i++)
			{
				if (board[i][j] != 0 && board[i - 1][j] == 0)
				{
					int k = i;
					while (board[k][j] != 0 && board[k - 1][j] == 0 && k != 0)
					{
						board[k - 1][j] = board[k][j];
						board[k][j] = 0;
						k--;
					}
				}
			}
		}
		for (int j = 0; j < n; j++)//합치기
		{
			for (int i = 0; i < n - 1; i++)
			{
				if (board[i][j] == board[i + 1][j])
				{
					board[i][j] = 2 * board[i][j];
					board[i + 1][j] = 0;
					i++;
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int i = 1; i < n; i++)
			{
				if (board[i][j] != 0 && board[i - 1][j] == 0)
				{
					int k = i;
					while (board[k][j] != 0 && board[k - 1][j] == 0 && k != 0)
					{
						board[k - 1][j] = board[k][j];
						board[k][j] = 0;
						k--;
					}
				}
			}
		}
	}
	else if (dir == 1)
	{
		for (int j = 0; j < n; j++)//밑으로 내리기
		{
			for (int i = n - 2; i >= 0; i--)
			{
				if (board[i][j] != 0 && board[i + 1][j] == 0)
				{
					int k = i;
					while (board[k][j] != 0 && board[k + 1][j] == 0 && k != n - 1)
					{
						board[k + 1][j] = board[k][j];
						board[k][j] = 0;
						k++;
					}
				}
			}
		}
		for (int j = 0; j < n; j++)//합치기
		{
			for (int i = n - 1; i > 0; i--)
			{
				if (board[i][j] == board[i - 1][j])
				{
					board[i][j] = 2 * board[i][j];
					board[i - 1][j] = 0;
					i--;
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			for (int i = n - 2; i >= 0; i--)
			{
				if (board[i][j] != 0 && board[i + 1][j] == 0)
				{
					int k = i;
					while (board[k][j] != 0 && board[k + 1][j] == 0 && k != n - 1)
					{
						board[k + 1][j] = board[k][j];
						board[k][j] = 0;
						k++;
					}
				}
			}
		}
	}
	else if (dir == 2)
	{
		for (int i = 0; i < n; i++)//오른쪽으로 밀기
		{
			for (int j = n - 2; j >= 0; j--)
			{
				if (board[i][j] != 0 && board[i][j + 1] == 0)
				{
					int k = j;
					while (board[i][k] != 0 && board[i][k + 1] == 0 && k != n - 1)
					{
						board[i][k + 1] = board[i][k];
						board[i][k] = 0;
						k++;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j > 0; j--)
			{
				if (board[i][j] == board[i][j - 1])
				{
					board[i][j] = 2 * board[i][j];
					board[i][j - 1] = 0;
					j--;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 2; j >= 0; j--)
			{
				if (board[i][j] != 0 && board[i][j + 1] == 0)
				{
					int k = j;
					while (board[i][k] != 0 && board[i][k + 1] == 0 && k != n - 1)
					{
						board[i][k + 1] = board[i][k];
						board[i][k] = 0;
						k++;
					}
				}
			}
		}
	}
	else if (dir == 3)
	{
		for (int i = 0; i < n; i++)//왼쪽으로 밀기
		{
			for (int j = 1; j < n; j++)
			{
				if (board[i][j] != 0 && board[i][j - 1] == 0)
				{
					int k = j;
					while (board[i][k] != 0 && board[i][k - 1] == 0 && k != 0)
					{
						board[i][k - 1] = board[i][k];
						board[i][k] = 0;
						k--;
					}
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (board[i][j] == board[i][j + 1])
				{
					board[i][j] = 2 * board[i][j];
					board[i][j + 1] = 0;
					j++;
				}
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (board[i][j] != 0 && board[i][j - 1] == 0)
				{
					int k = j;
					while (board[i][k] != 0 && board[i][k - 1] == 0 && k != 0)
					{
						board[i][k - 1] = board[i][k];
						board[i][k] = 0;
						k--;
					}
				}
			}
		}
	}
}
void solve(int cnt)
{
	int num = findMax();
	if (num <= value[cnt])
		return;
	if (cnt == 5)
	{
		ans = max(ans, num);
		int tmp = ans;
		while (cnt > 0)
		{
			value[cnt--] = tmp;
			tmp /= 2;
		}
		return;
	}
	int arr[21][21] = { 0 };
	copy(board, arr);
	for (int i = 0; i < 4; i++)
	{
		move(i);
		if (compare(board, arr))
		{
			solve(cnt + 1);
			copy(arr, board);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
			if (ans < board[i][j])
				ans = board[i][j];
		}
	solve(0);
	cout << ans << '\n';
}