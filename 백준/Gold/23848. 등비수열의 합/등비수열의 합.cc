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
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 2; i <= sqrt(n); i++)
	{
		int tmp = 1 + i + i * i;
		int num = i * i;
		int size = 3;
		while (tmp <= n)
		{
			if (n % tmp == 0)
			{
				cout << size << '\n';
				int x = n / tmp;
				for (int idx = 1; idx <= size; idx++)
				{
					cout << x << " ";
					x *= i;
				}
				cout << '\n';
				return 0;
			}
			num *= i;
			tmp += num;
			size++;
		}
	}
	cout << -1 << '\n';
}