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
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t, n, m;
	cin >> t;
	while (t--)
	{
		cin >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		cin >> m;
		while (m--)
		{
			int x;
			cin >> x;
			int left = 0, right = v.size() - 1;
			int flag = 0;
			while (left <= right)
			{
				int mid = left + (right - left) / 2;
				if (v[mid] == x)
				{
					flag = 1;
					break;
				}
				else if (x < v[mid])
					right = mid - 1;
				else
					left = mid + 1;
			}
			if (flag)
				cout << "1\n";
			else
				cout << "0\n";
		}
	}
}