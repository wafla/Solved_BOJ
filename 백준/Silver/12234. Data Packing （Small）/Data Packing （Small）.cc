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
	int t;
	cin >> t;
	for (int k = 1; k <= t; k++)
	{
		int n, x;
		cin >> n >> x;
		vector<int> v(n);
		for (int i = 0; i < n; i++)
			cin >> v[i];
		sort(v.begin(), v.end());
		int ans = 0;
		int idx = n - 1;
		while (idx >= 0)
		{
			int sum = v[idx];
			int tmp = idx - 1;
			v.pop_back();
			while (tmp >= 0)
			{
				if (sum + v[tmp] <= x)
				{
					v.erase(v.begin() + tmp);
					break;
				}
				tmp--;
			}
			ans++;
			idx = v.size() - 1;
		}
		cout << "Case #" << k << ": " << ans << '\n';
	}
}