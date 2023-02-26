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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	queue<pair<char, int>> Q;
	if (n % 2 == 1 && m % 2 == 1) // 홀수
	{
		int x = 1, y = 1;
		cout << n * m - 1 << '\n';
		if (n == 3 && m == 3)
		{
			while (x < n)
				cout << x++ << " " << y << '\n';
			while (y < m)
				cout << x << " " << y++ << '\n';
			while (x > 1)
				cout << x-- << " " << y << '\n';
			while (y > 1)
				cout << x << " " << y-- << '\n';
		}
		else
		{
			int flag = -1;
			Q.push({ 'D', n - 1 });
			Q.push({ 'R', m - 2 });
			Q.push({ 'U',1 });
			Q.push({ 'R',1 });
			Q.push({ 'U',1 });
			Q.push({ 'L',1 });
			for (int i = 0; i < m - 3; i++)
			{
				Q.push({ 'L',1 });
				if (flag < 0) // 밑으로
					Q.push({ 'D', 1 });
				else if (flag > 0) // 위로
					Q.push({ 'U', 1 });
				flag *= -1;
			}
			flag = 1;
			for (int i = 0; i < n - 3; i++)
			{
				Q.push({ 'U', 1 });
				if (flag < 0) // 왼쪽
					Q.push({ 'L', m - 2 });
				else if (flag > 0) // 오른쪽
					Q.push({ 'R', m - 2 });
				flag *= -1;
			}
			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();
				if (cur.X == 'U')
				{
					for (int i = 0; i < cur.Y; i++)
						cout << x-- << " " << y << '\n';
				}
				else if (cur.X == 'D')
				{
					for (int i = 0; i < cur.Y; i++)
						cout << x++ << " " << y << '\n';
				}
				else if (cur.X == 'L')
				{
					for (int i = 0; i < cur.Y; i++)
						cout << x << " " << y-- << '\n';
				}
				else if (cur.X == 'R')
				{
					for (int i = 0; i < cur.Y; i++)
						cout << x << " " << y++ << '\n';
				}
			}
			cout << x << " " << y << '\n';
		}
	}
	else if (n % 2 == 1 && m % 2 == 0) // 홀 짝
	{
		cout << n * m << '\n';
		int x = 1, y = 1;
		int flag = -1;
		Q.push({ 'D', n - 1 });
		Q.push({ 'R', m - 1 });
		for (int i = 0; i < n - 3; i++)
		{
			Q.push({ 'U', 1 });
			if (flag < 0) // 왼쪽
				Q.push({ 'L', m - 2 });
			else if (flag > 0) // 오른쪽
				Q.push({ 'R', m - 2 });
			flag *= -1;
		}
		Q.push({ 'U',1 });
		flag = -1;
		for (int i = 0; i < m - 1; i++)
		{
			if (flag < 0) // 위 - 왼
				Q.push({ 'U',1 });
			else if (flag > 0) // 밑 - 왼
				Q.push({ 'D',1 });
			Q.push({ 'L',1 });
			flag *= -1;
		}
		while (!Q.empty())
		{
			auto cur = Q.front();
			Q.pop();
			if (cur.X == 'U')
			{
				for (int i = 0; i < cur.Y; i++)
					cout << x-- << " " << y << '\n';
			}
			else if (cur.X == 'D')
			{
				for (int i = 0; i < cur.Y; i++)
					cout << x++ << " " << y << '\n';
			}
			else if (cur.X == 'L')
			{
				for (int i = 0; i < cur.Y; i++)
					cout << x << " " << y-- << '\n';
			}
			else if (cur.X == 'R')
			{
				for (int i = 0; i < cur.Y; i++)
					cout << x << " " << y++ << '\n';
			}
		}
	}
	else 
	{
		cout << n * m << '\n';
		int x = 1, y = 1;
		if (n == 2 || m == 2)
		{
			while (x < n)
				cout << x++ << " " << y << '\n';
			while (y < m)
				cout << x << " " << y++ << '\n';
			while (x > 1)
				cout << x-- << " " << y << '\n';
			while (y > 1)
				cout << x << " " << y-- << '\n';
		}
		else
		{
			int flag = -1;
			Q.push({ 'D', n - 1 });
			Q.push({ 'R', m - 1 });
			for (int i = 0; i < n - 2; i++)
			{
				Q.push({ 'U', 1 });
				if (flag < 0) // 왼쪽
					Q.push({ 'L', m - 2 });
				else if (flag > 0) // 오른쪽
					Q.push({ 'R', m - 2 });
				flag *= -1;
			}
			Q.push({ 'U',1 });
			Q.push({ 'L', m - 1 });
			while (!Q.empty())
			{
				auto cur = Q.front();
				Q.pop();
				if (cur.X == 'U')
				{
					for (int i = 0; i < cur.Y; i++)
						cout << x-- << " " << y << '\n';
				}
				else if (cur.X == 'D')
				{
					for (int i = 0; i < cur.Y; i++)
						cout << x++ << " " << y << '\n';
				}
				else if (cur.X == 'L')
				{
					for (int i = 0; i < cur.Y; i++)
						cout << x << " " << y-- << '\n';
				}
				else if (cur.X == 'R')
				{
					for (int i = 0; i < cur.Y; i++)
						cout << x << " " << y++ << '\n';
				}
			}
		}
	}
}