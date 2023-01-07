#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;
int main()
{
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	long long a, ans = 0;
	int l;
	char arr[51] = { 0 };
	cin >> l;
	for (int i = 0; i < l; i++)
		cin >> arr[i];
	for (int i = 0; i < l; i++)
	{
		long long mod = 1234567891;
		long long x = arr[i] - 96;
		long long r = 31;
		long long num = 1;
		for (int j = 1; j <= i; j++)
		{
			num *= r;
			num %= mod;
		}
		ans += x * num;
		ans %= mod;
	}
	cout << ans;
}