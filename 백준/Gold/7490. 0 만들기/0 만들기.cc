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
set<string> S;
int n;
void check(string s)
{
	stack<char> op;
	stack<int> num;
	string tmp = "";
	for (int i = s.size() - 1; i >= 0; i--)
	{
		if (s[i] == '+' || s[i] == '-')
		{
			op.push(s[i]);
			num.push(stoi(tmp));
			tmp = "";
		}
		else if (s[i] == ' ')
			continue;
		else
		{
			tmp = s[i] + tmp;
			if (i == 0)
				num.push(stoi(tmp));
		}
	}
	while (num.size() > 1)
	{
		int a = num.top(); num.pop();
		int b = num.top(); num.pop();
		int c;
		if (op.top() == '+')
			c = a + b;
		else if (op.top() == '-')
			c = a - b;
		num.push(c);
		op.pop();
	}
	if (num.top() == 0)
		S.insert(s);
}
void dfs(string s, int idx)
{
	if (idx >= n)
	{
		check(s);
		return;
	}
	s[idx * 2 - 1] = '+';
	dfs(s, idx + 1);
	s[idx * 2 - 1] = '-';
	dfs(s, idx + 1);
	s[idx * 2 - 1] = ' ';
	dfs(s, idx + 1);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		string s = "";
		S.clear();
		for (int i = 1; i <= n; i++)
		{
			if (i < n)
				s += to_string(i) + " ";
			else
				s += to_string(i);
		}
		dfs(s, 1);
		for (auto i : S)
			cout << i << '\n';
		cout << '\n';
	}
}