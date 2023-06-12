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
int mx = -INF, mn = INF;
int n, a1, a2, a3, a4;
int arr[11] = { 0 };
void solve(int idx, int b1, int b2, int b3, int b4, int sum)
{
	if (idx == n - 1)
	{
		if (sum > mx)
			mx = sum;
		if (sum < mn)
			mn = sum;
		return;
	}
	if (b1 < a1)
		solve(idx + 1, b1 + 1, b2, b3, b4, sum + arr[idx + 1]);
	if (b2 < a2)
		solve(idx + 1, b1, b2 + 1, b3, b4, sum - arr[idx + 1]);
	if (b3 < a3)
		solve(idx + 1, b1, b2, b3 + 1, b4, sum * arr[idx + 1]);
	if (b4 < a4)
		solve(idx + 1, b1, b2, b3, b4 + 1, sum / arr[idx + 1]);
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	int i;
	for (i = 0; i < n; i++)
		cin >> arr[i];
	cin >> a1 >> a2 >> a3 >> a4;
	solve(0, 0, 0, 0, 0, arr[0]);
	cout << mx << "\n" << mn << '\n';
}