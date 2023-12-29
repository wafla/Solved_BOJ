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
#define T pair<int, pi>
using namespace std;
int tmp[2000001] = { 0 }, arr[2000001] = { 0 };
int merge_sort(int left, int right)
{
	if (left >= right)
		return 0;
	int mid = left + (right - left) / 2;
	int res = merge_sort(left, mid) + merge_sort(mid + 1, right);
	int k = left, i = left, j = mid + 1;
	while (i <= mid && j <= right)
	{
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
		{
			res += j - k;
			tmp[k++] = arr[j++];
		}
	}
	while (i <= mid)
		tmp[k++] = arr[i++];
	while (j <= right)
		tmp[k++] = arr[j++];
	for (k = left; k <= right; k++)
		arr[k] = tmp[k];
	return res;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<pi> v(m);
	for (int i = 0; i < m; i++)
		cin >> v[i].X >> v[i].Y;
	sort(v.begin(), v.end());
	for (int i = 0; i < m; i++)
		arr[i] = v[i].Y;
	cout << merge_sort(0, m - 1) << '\n';
}