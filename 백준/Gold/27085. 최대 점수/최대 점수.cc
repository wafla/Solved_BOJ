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
	int n, s;
	cin >> n >> s;
	s--;
	vector<ll> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	int left = s, right = s;
	ll sum = 0;
	ll maxx = 0;
	ll left_sum = 0, right_sum = 0;
	while (left >=0 || right < n)
	{
		if (left >= 0 && left_sum + sum >= 0)
		{
			left_sum += v[left];
			if (left_sum >= 0)
			{
				sum += left_sum;
				maxx = max(maxx, sum);
				left_sum = 0;
			}
			left--;
		}
		if (right <= n && right_sum + sum >= 0)
		{
			right_sum += v[right];
			if (right_sum >= 0)
			{
				sum += right_sum;
				maxx = max(maxx, sum);
				right_sum = 0;
			}
			right++;
		}
		if ((left < 0 && right_sum + sum < 0) || (right >= n && left_sum + sum < 0) || (right_sum + sum < 0 && left_sum + sum < 0))
			break;
	}
	cout << maxx << '\n';
}