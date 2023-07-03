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
int arr[500001] = { 0 }, r_arr[500001] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		r_arr[i] = arr[i];
		arr[i] += i * k;
		r_arr[i] -= i * k;
	}
	int ans = -INF, maxx = arr[1];
	for (int i = 2; i <= n; i++)
	{
		ans = max(ans, maxx - arr[i]);
		maxx = max(maxx, arr[i]);
	}
	maxx = r_arr[n];
	for (int i = n - 1; i >= 1; i--)
	{
		ans = max(ans, maxx - r_arr[i]);
		maxx = max(maxx, r_arr[i]);
	}
	cout << ans << '\n';
}