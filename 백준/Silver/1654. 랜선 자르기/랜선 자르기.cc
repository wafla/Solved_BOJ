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
vector <ll> v;
ll n, k, ans = 0;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> k >> n;
	for (int i = 0; i < k; i++)
	{
		int x;
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	ll left = 1, right = v[v.size() - 1];
	while (left <= right)
	{
		ll sum = 0;
		ll mid = (left + right) / 2;
		for (int i = 0; i < v.size(); i++)
			sum += v[i] / mid;
		if (sum >= n)
		{
			if (mid > ans)
				ans = mid;
			left = mid + 1;
		}
		else if (sum < n)
			right = mid - 1;
	}
	cout << ans;
}