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
#define LINF 9223372036854775807
#define MOD 10000000000
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<pi, int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int x = 3, prev = 24, sum;
	if (n <= 7)
		cout << "1\n";
	else if (n <= 23)
		cout << "2\n";
	else
	{
		while (1)
		{
			int tmp = x + 1;
			int num = x + 1;
			sum = x;
			while (tmp--)
			{
				sum += num;
				num *= 2;
			}
			if (prev <= n && n <= sum)
			{
				cout << x << '\n';
				break;
			}
			prev = sum + 1;
			x++;
		}
	}
}