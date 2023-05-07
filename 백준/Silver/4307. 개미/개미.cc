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
	int t;
	cin >> t;
	while (t--)
	{
		int l, n, minn = 0, maxx = 0;
		cin >> l >> n;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
		{
			cin >> v[i];
			if (l - v[i] > maxx)
				maxx = l - v[i];
			if (v[i] > maxx)
				maxx = v[i];
			if (v[i] >= l/2)
			{
				if (l - v[i] > minn)
					minn = l - v[i];
			}
			else
			{
				if (v[i] > minn)
					minn = v[i];
			}
		}
		cout << minn << " " << maxx << '\n';
	}
}