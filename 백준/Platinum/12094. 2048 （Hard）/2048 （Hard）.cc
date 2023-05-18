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
	queue<int> Q;
	if (dir == 0)
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < n; i++)
			{
				if (board[i][j])
				{
					Q.push(board[i][j]);
					board[i][j] = 0;
				}
			}
			int idx = 0;
			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();
				if (!board[idx][j])
					board[idx][j] = cur;
				else if (board[idx][j] == cur)
					board[idx++][j] += cur;
				else
					board[++idx][j] = cur;
			}
		}
	}
	else if (dir == 1)
	{
		for (int j = 0; j < n; j++)
		{
			for (int i = n - 1; i >= 0; i--)
			{
				if (board[i][j])
				{
					Q.push(board[i][j]);
					board[i][j] = 0;
				}
			}
			int idx = n - 1;
			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();
				if (!board[idx][j])
					board[idx][j] = cur;
				else if (board[idx][j] == cur)
					board[idx--][j] += cur;
				else
					board[--idx][j] = cur;
			}
		}
	}
	else if (dir == 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j])
				{
					Q.push(board[i][j]);
					board[i][j] = 0;
				}
			}
			int idx = 0;
			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();
				if (!board[i][idx])
					board[i][idx] = cur;
				else if (board[i][idx] == cur)
					board[i][idx++] += cur;
				else
					board[i][++idx] = cur;
			}
		}
	}
	else if (dir == 3)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = n - 1; j >= 0; j--)
			{
				if (board[i][j])
				{
					Q.push(board[i][j]);
					board[i][j] = 0;
				}
			}
			int idx = n - 1;
			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();
				if (!board[i][idx])
					board[i][idx] = cur;
				else if (board[i][idx] == cur)
					board[i][idx--] += cur;
				else
					board[i][--idx] = cur;
			}
		}
	}
}
void solve(int cnt)
{
	int num = findMax();
	if (num <= value[cnt])
		return;
	if (cnt == 10)
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