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
char arr[12][12] = { 0 }, tmp[12][12] = { 0 };
int dx[5] = { 0,0,0,-1,1 }, dy[5] = { 0,1,-1,0,0 };
void fill()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			tmp[i][j] = arr[i][j];
}
void click(int x, int y)
{
	for (int i = 0; i < 5; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx > 10 || ny > 10)
			continue;
		if (tmp[nx][ny] == '#')
			tmp[nx][ny] = 'O';
		else
			tmp[nx][ny] = '#';
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> arr[i][j];
	int ans = INF;
	for (int i = 0; i < (1 << 10); i++) // 첫번째줄 경우의 수 탐색
	{
		int cnt = 0;
		fill();
		for (int j = 0; j < 10; j++)
		{
			if (i & (1 << j)) // 켜져 있어서 꺼야할 경우
			{
				cnt++;
				click(0, j);
			}
		}
		for (int j = 1; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (tmp[j - 1][k] == 'O') // 위의 칸이 켜져 있으면 꺼야함
				{
					cnt++;
					click(j, k);
				}
			}
		}
		bool flag = 0;
		for (int j = 0; j < 10; j++)
		{
			if (tmp[9][j] == 'O') // 이미 버튼을 다 눌렀지만 불이 켜져 있는 경우
			{
				flag = 1;
				break;
			}
		}
		if (!flag) ans = min(ans, cnt);
	}
	if (ans == INF)
		cout << -1 << '\n';
	else
		cout << ans << '\n';
}
// 참고 : https://technicolour.tistory.com/19