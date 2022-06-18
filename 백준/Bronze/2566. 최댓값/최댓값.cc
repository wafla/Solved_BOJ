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
#define X first
#define Y second
using namespace std;
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	int maxx = 0, x = 1, y = 1;
	for (int i = 0;i < 9;i++)
	{
		for (int j = 0;j < 9;j++)
		{
			int num;
			cin >> num;
			if (num > maxx)
			{
				maxx = num;
				x = i + 1;
				y = j + 1;
			}
		}
	}
	cout << maxx << '\n' << x << " " << y;
}