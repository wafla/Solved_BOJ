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
vector<string> ans;
void cal(int num, string s)
{
	deque<int> S;
	deque<char> Oper;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 32)
			continue;
		else if (s[i] == '4')
			S.push_back(4);
		else if (s[i] == '*' || s[i] == '/')
		{
			int x = S.back();
			S.pop_back();
			int NextNum;
			if (s[i] == '*')
				NextNum = x * 4;
			else if (s[i] == '/')
				NextNum = x / 4;
			S.push_back(NextNum);
			i += 2;
		}
		else if (s[i] == '+' || s[i] == '-')
		{
			if (s[i] == '+')
				Oper.push_back('+');
			else if (s[i] == '-')
				Oper.push_back('-');
		}
	}
	int X = S.front();
	S.pop_front();
	while (!Oper.empty())
	{
		char x = Oper.front();
		Oper.pop_front();
		if (x == '+')
			X = X + S.front();
		else if (x == '-')
			X = X - S.front();
		S.pop_front();
	}
	if (X == num)
		ans.push_back(s);
}
void solve(int num, int cnt, string s)
{
	if (cnt == 3)
		cal(num, s);
	else
	{
		solve(num, cnt + 1, s + " + 4");
		solve(num, cnt + 1, s + " - 4");
		solve(num, cnt + 1, s + " / 4");
		solve(num, cnt + 1, s + " * 4");
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	while (t--)
	{
		ans.clear();
		int num;
		cin >> num;
		solve(num, 0, "4");
		if (!ans.size())
			cout << "no solution\n";
		else
			cout << ans[0] << " = " << num << '\n';
	}
}