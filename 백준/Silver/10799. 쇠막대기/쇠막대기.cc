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
	string s;
	cin >> s;
	stack<char> S;
	int ans = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			S.push('(');
		else if (s[i] == ')' && s[i-1]=='(')
		{
			S.pop();
			ans += S.size();
		}
		else if (s[i] == ')')
		{
			S.pop();
			ans++;
		}
	}
	cout << ans << '\n';
}