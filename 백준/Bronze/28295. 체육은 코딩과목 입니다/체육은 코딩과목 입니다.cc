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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int a = 1, x; // 1 북쪽 2 동쪽 3 남쪽 4 서쪽
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		if (a == 1)
		{
			if (x == 1)
				a = 2;
			else if (x == 2)
				a = 3;
			else if (x == 3)
				a = 4;
		}
		else if (a == 2)
		{
			if (x == 1)
				a = 3;
			else if (x == 2)
				a = 4;
			else if (x == 3)
				a = 1;
		}
		else if (a == 3)
		{
			if (x == 1)
				a = 4;
			else if (x == 2)
				a = 1;
			else if (x == 3)
				a = 2;
		}
		else if (a == 4)
		{
			if (x == 1)
				a = 1;
			else if (x == 2)
				a = 2;
			else if (x == 3)
				a = 3;
		}
	}
	if (a == 1)
		cout << "N\n";
	else if (a == 2)
		cout << "E\n";
	else if (a == 3)
		cout << "S\n";
	else
		cout << "W\n";
}