#include <iostream>
using namespace std;
int arr[200001] = { 0 }, ans = 0, n, k;
void solve(int m, int idx, int sum)
{
	if (idx == k)
	{
		if (ans < sum)
			ans = sum;
		if (m < n * 2)
			solve(m + 1, idx, sum + arr[m] - arr[m - k]);
	}
	if (idx < k)
		solve(m+1, idx+1, sum + arr[m]);
}
int main()
{
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	cin >> n >> k;
	for (int i = 0;i < n;i++)
	{
		cin >> arr[i];
		arr[i + n] = arr[i];
	}
	solve(1, 1, arr[0]);
	cout << ans;
}