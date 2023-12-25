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
using namespace std;
int string_to_int(string s)
{
	int num = 0;
	int i = 1;
	for (int idx = 0; idx < s.size(); idx++)
	{
		num += (s[idx] - 48) * i;
		i *= 10;
	}
	return num;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, ans = 0;
	cin >> n;
	int tmp = n;
	string s = to_string(n);
	for (int i = 0; i < s.size() / 2; i++)
		tmp /= 10;
	while (tmp)
	{
		string l = to_string(tmp);
		string r = l;
		reverse(r.begin(), r.end());
		string value = l + r;
		int num = string_to_int(value);
		if (num <= n)
			ans++;
		for (int i = 0; i < 10; i++)
		{
			string value2 = "";
			value2 += l;
			value2 += i + 48;
			value2 += r;
			int num2 = string_to_int(value2);
			if (num2 <= n)
				ans++;
		}
		tmp--;
	}
	if (n >= 9)
		ans += 9;
	else
		ans += n;
	cout << ans << '\n';
}