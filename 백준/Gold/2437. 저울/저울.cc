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
	int n;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	int left = 0, right = 1, ans = 1;
	if (v[0] > 1)
	{
		cout << ans << '\n';
		return 0;
	}
	if (n == 1)
	{
		cout << 2 << '\n';
		return 0;
	}
	for (int i = 1; i < n; i++)
	{
		if (v[i] > right + 1)
		{
			ans = right + 1;
			break;
		}
		else
		{
			right += v[i];
			ans = right + 1;
		}
	}
	cout << ans << '\n';
}
// 참고 : https://aerocode.net/392