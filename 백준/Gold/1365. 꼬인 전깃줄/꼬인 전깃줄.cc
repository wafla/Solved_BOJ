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
	vector<int> arr(n);
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	vector<int> v;
	v.push_back(arr[0]);
	for (int i = 1; i < n; i++)
	{
		if (v.back() < arr[i])
			v.push_back(arr[i]);
		else if (v.back() > arr[i])
		{
			auto num = lower_bound(v.begin(), v.end(), arr[i]);
			*num = arr[i];
		}
	}
	cout << n - v.size() << '\n';
}