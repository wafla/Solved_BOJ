#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
int arr[4][4] = { 0 };
bool check()
{
	if (arr[1][1] == arr[2][2] && arr[2][2] == arr[3][3] && arr[1][1] > 0)
		return 1;
	if (arr[3][1] == arr[2][2] && arr[2][2] == arr[1][3] && arr[3][1] > 0)
		return 1;
	for (int i = 1; i <= 3; i++)
	{
		if (arr[i][1] == arr[i][2] && arr[i][2] == arr[i][3] && arr[i][1] > 0)
			return 1;
		if (arr[1][i] == arr[2][i] && arr[2][i] == arr[3][i] && arr[1][i] > 0)
			return 1;
	}
	return 0;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int start;
	cin >> start;
	for (int i = 0; i < 9; i++)
	{
		int x, y;
		cin >> x >> y;
		if (i % 2 == 0)
			arr[x][y] = start;
		else
			arr[x][y] = 3 - start;
		if (check())
		{
			if (i % 2 == 0)
				cout << start << '\n';
			else
				cout << 3 - start << '\n';
			return 0;
		}
	}
	cout << "0\n";
}