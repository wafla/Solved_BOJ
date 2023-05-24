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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, sum = 0;
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
		sum += v[i];
	}
	sort(v.begin(), v.end());
	bool flag = false;
	if (sum % 2 == 0)
		cout << sum << '\n';
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (v[i] % 2 == 1)
			{
				sum -= v[i];
				flag = true;
				break;
			}
		}
		if (flag)
			cout << sum << '\n';
		else
			cout << 0 << '\n';
	}
}