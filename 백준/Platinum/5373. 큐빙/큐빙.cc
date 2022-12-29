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
char v[7][7][7] = { 0 };
// string s = "wyrogb";
int u[5] = { 2,5,3,4,2 };
int u_[5] = { 2,4,3,5,2 };
int f[5] = { 0,4,1,5,0 };
int f_[5] = { 0,5,1,4,0 };
int l[5] = { 0,3,1,2,0 };
int l_[5] = { 0,2,1,3,0 };
void solve_(int idx, int x)
{
	char tmp[7][7] = { 0 };
	for (int i = 0; i < 3; i++)
		tmp[0][i] = v[idx][0][i];
	for (int i = 0; i < 3; i++)
		tmp[1][i] = v[idx][2-i][2];
	for (int i = 0; i < 3; i++)
		tmp[2][i] = v[idx][2][i];
	for (int i = 0; i < 3; i++)
		tmp[3][i] = v[idx][2-i][0];

	if (x == 0) // 시계
	{
		for (int i = 0; i < 3; i++)
			v[idx][i][2] = tmp[0][i];
		for (int i = 0; i < 3; i++)
			v[idx][2][i] = tmp[1][i];
		for (int i = 0; i < 3; i++)
			v[idx][i][0] = tmp[2][i];
		for (int i = 0; i < 3; i++)
			v[idx][0][i] = tmp[3][i];
	}
	else if (x == 1) // 반시계
	{
		for (int i = 0; i < 3; i++)
			v[idx][i][2] = tmp[2][2-i];
		for (int i = 0; i < 3; i++)
			v[idx][2][i] = tmp[3][2-i];
		for (int i = 0; i < 3; i++)
			v[idx][i][0] = tmp[0][2-i];
		for (int i = 0; i < 3; i++)
			v[idx][0][i] = tmp[1][2-i];
	}
}
void solve(char x, char y)
{
	if (x == 'U') // 윗 면
	{
		char tmp[3] = { 0 };
		for (int i = 0; i < 3; i++)
			tmp[i] = v[2][0][i];
		if (y == '+')
		{
			for (int i = 0; i < 3; i++)
				if (u[i] == 2 || u[i] == 3 || u[i] == 5)
					for (int j = 0; j < 3; j++)
						v[u[i]][0][j] = v[u[i + 1]][0][j];
			for (int i = 0; i < 3; i++)
				v[4][0][i] = tmp[i];
			solve_(0, 0);
		}
		else if (y == '-')
		{
			for (int i = 0; i < 3; i++)
				if (u_[i] == 2 || u_[i] == 3 || u_[i] == 4)
					for (int j = 0; j < 3; j++)
						v[u_[i]][0][j] = v[u_[i + 1]][0][j];
			for (int i = 0; i < 3; i++)
				v[5][0][i] = tmp[i];
			solve_(0, 1);
		}
	}
	else if (x == 'D') // 아랫 면
	{
		char tmp[3] = { 0 };
		for (int i = 0; i < 3; i++)
			tmp[i] = v[2][2][i];
		if (y == '+')
		{
			for (int i = 0; i < 3; i++)
				if (u_[i] == 2 || u_[i] == 3 || u_[i] == 4)
					for (int j = 0; j < 3; j++)
						v[u_[i]][2][j] = v[u_[i + 1]][2][j];
			for (int i = 0; i < 3; i++)
				v[5][2][i] = tmp[i];
			solve_(1, 0);
		}
		else if (y == '-')
		{
			for (int i = 0; i < 3; i++)
				if (u[i] == 2 || u[i] == 3 || u[i] == 5)
					for (int j = 0; j < 3; j++)
						v[u[i]][2][j] = v[u[i + 1]][2][j];
			for (int i = 0; i < 3; i++)
				v[4][2][i] = tmp[i];
			solve_(1, 1);
		}
	}
	else if (x == 'F') // 앞 면
	{
		char tmp[3] = { 0 };
		for (int i = 0; i < 3; i++)
			tmp[i] = v[0][2][i];
		if (y == '+')
		{
			for (int i = 0; i < 3; i++)
			{
				if (f[i] == 0)
					for (int j = 0; j < 3; j++)
						v[f[i]][2][j] = v[f[i + 1]][2 - j][2];
				else if (f[i] == 1)
					for (int j = 0; j < 3; j++)
						v[f[i]][2][j] = v[f[i + 1]][j][0];
				else if (f[i] == 4)
					for (int j = 0; j < 3; j++)
						v[f[i]][j][2] = v[f[i + 1]][2][2 - j];
			}
			for (int i = 0; i < 3; i++)
				v[5][i][0] = tmp[i];
			solve_(2, 0);
		}
		else if (y == '-')
		{
			for (int i = 0; i < 3; i++)
			{
				if (f_[i] == 0)
					for (int j = 0; j < 3; j++)
						v[f_[i]][2][j] = v[f_[i + 1]][j][0];
				else if (f_[i] == 1)
					for (int j = 0; j < 3; j++)
						v[f_[i]][2][j] = v[f_[i + 1]][2 - j][2];
				else if (f_[i] == 5)
					for (int j = 0; j < 3; j++)
						v[f_[i]][j][0] = v[f_[i + 1]][2][j];
			}
			for (int i = 0; i < 3; i++)
				v[4][i][2] = tmp[2 - i];
			solve_(2, 1);
		}
	}
	else if (x == 'B') // 뒷 면
	{
		char tmp[3] = { 0 };
		for (int i = 0; i < 3; i++)
			tmp[i] = v[0][0][i];
		if (y == '+')
		{
			for (int i = 0; i < 3; i++)
			{
				if (f_[i] == 0)
					for (int j = 0; j < 3; j++)
						v[f_[i]][0][j] = v[f_[i + 1]][j][2];
				else if (f_[i] == 1)
					for (int j = 0; j < 3; j++)
						v[f_[i]][0][j] = v[f_[i + 1]][2 - j][0];
				else if (f_[i] == 5)
					for (int j = 0; j < 3; j++)
						v[f_[i]][j][2] = v[f_[i + 1]][0][j];
			}
			for (int i = 0; i < 3; i++)
				v[4][i][0] = tmp[2 - i];
			solve_(3, 0);
		}
		else if (y == '-')
		{
			for (int i = 0; i < 3; i++)
			{
				if (f[i] == 0)
					for (int j = 0; j < 3; j++)
						v[f[i]][0][j] = v[f[i + 1]][2 - j][0];
				else if (f[i] == 1)
					for (int j = 0; j < 3; j++)
						v[f[i]][0][j] = v[f[i + 1]][j][2];
				else if (f[i] == 4)
					for (int j = 0; j < 3; j++)
						v[f[i]][j][0] = v[f[i + 1]][0][2 - j];
			}
			for (int i = 0; i < 3; i++)
				v[5][i][2] = tmp[i];
			solve_(3, 1);
		}
	}
	else if (x == 'L') // 왼쪽 면
	{
		char tmp[3] = { 0 };
		for (int i = 0; i < 3; i++)
			tmp[i] = v[0][i][0];
		if (y == '+')
		{
			for (int i = 0; i < 3; i++)
			{
				if (l[i] == 0)
					for (int j = 0; j < 3; j++)
						v[l[i]][j][0] = v[l[i + 1]][2 - j][2];
				else if (l[i] == 1)
					for (int j = 0; j < 3; j++)
						v[l[i]][j][2] = v[l[i + 1]][2 - j][0];
				else if (l[i] == 3)
					for (int j = 0; j < 3; j++)
						v[l[i]][j][2] = v[l[i + 1]][j][2];
			}
			for (int i = 0; i < 3; i++)
				v[2][i][0] = tmp[i];
			solve_(4, 0);
		}
		else if (y == '-')
		{
			for (int i = 0; i < 3; i++)
			{
				if (l_[i] == 0)
					for (int j = 0; j < 3; j++)
						v[l_[i]][j][0] = v[l_[i + 1]][j][0];
				else if (l_[i] == 1)
					for (int j = 0; j < 3; j++)
						v[l_[i]][j][2] = v[l_[i + 1]][j][2];
				else if (l_[i] == 2)
					for (int j = 0; j < 3; j++)
						v[l_[i]][j][0] = v[l_[i + 1]][2 - j][2];
			}
			for (int i = 0; i < 3; i++)
				v[3][i][2] = tmp[2 - i];
			solve_(4, 1);
		}
	}
	else if (x == 'R') // 오른쪽 면
	{
		char tmp[3] = { 0 };
		for (int i = 0; i < 3; i++)
			tmp[i] = v[0][i][2];
		if (y == '+')
		{
			for (int i = 0; i < 3; i++)
			{
				if (l_[i] == 0)
					for (int j = 0; j < 3; j++)
						v[l_[i]][j][2] = v[l_[i + 1]][j][2];
				else if (l_[i] == 1)
					for (int j = 0; j < 3; j++)
						v[l_[i]][j][0] = v[l_[i + 1]][j][0];
				else if (l_[i] == 2)
					for (int j = 0; j < 3; j++)
						v[l_[i]][j][2] = v[l_[i + 1]][2 - j][0];
			}
			for (int i = 0; i < 3; i++)
				v[3][i][0] = tmp[2 - i];
			solve_(5, 0);
		}
		else if (y == '-')
		{
			for (int i = 0; i < 3; i++)
			{
				if (l[i] == 0)
					for (int j = 0; j < 3; j++)
						v[l[i]][j][2] = v[l[i + 1]][2 - j][0];
				else if (l[i] == 1)
					for (int j = 0; j < 3; j++)
						v[l[i]][j][0] = v[l[i + 1]][2 - j][2];
				else if (l[i] == 3)
					for (int j = 0; j < 3; j++)
						v[l[i]][j][0] = v[l[i + 1]][j][0];
			}
			for (int i = 0; i < 3; i++)
				v[2][i][2] = tmp[i];
			solve_(5, 1);
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string s = "wyrogb";
	int t;
	cin >> t;
	while(t--)
	{
		for (int i = 0; i < 6; i++)
			for (int j = 0; j < 3; j++)
				for (int k = 0; k < 3; k++)
					v[i][j][k] = s[i];
		int n;
		cin >> n;
		while (n--)
		{
			string str;
			cin >> str;
			solve(str[0], str[1]);
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << v[0][i][j];
			cout << '\n';
		}
	}
}