#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	int n, ans = 0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		int x;
		cin >> x;
		ans += x;
	}
	ans -= n - 1;
	cout << ans;
}