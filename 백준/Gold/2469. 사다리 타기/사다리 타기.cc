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
	int k, n, z=0;
	cin >> k >> n;
	string f="", s;
	cin >> s;
	for (int i = 0; i < k; i++)
		f += char(65 + z++);
	vector<string> v;
	int idx;
	for (int i = 0; i < n; i++)
	{
		string tmp;
		cin >> tmp;
		if (tmp[0] == '?')
			idx = i;
		v.push_back(tmp);
	}
	for (int i = 0; i < idx; i++)
	{
		for (int j = 0; j < k - 1; j++)
		{
			if (v[i][j] == '-')
			{
				char tmp = f[j];
				f[j] = f[j+1];
				f[j+1] = tmp;
			}
		}
	}
	for (int i = n - 1; i > idx; i--)
	{
		for (int j = 0; j < k - 1; j++)
		{
			if (v[i][j] == '-')
			{
				char tmp = s[j];
				s[j] = s[j + 1];
				s[j + 1] = tmp;
			}
		}
	}
	string ans = "";
	int flag = 1;
	for (int i = 0; i < k - 1; i++)
	{
		if (f[i] == s[i])
			ans += "*";
		else if (f[i] == s[i + 1] && s[i] == f[i + 1])
		{
			char tmp = f[i];
			f[i] = f[i + 1];
			f[i + 1] = tmp;
			ans += "-";
		}
		else
		{
			flag = 0;
			break;
		}
	}
	if (!flag)
	{
		for (int i = 0; i < k - 1; i++)
			cout << 'x';
		cout << '\n';
	}
	else
		cout << ans << '\n';
}