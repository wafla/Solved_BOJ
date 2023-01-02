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
	string str;
	cin >> str;
	stack<char> st;
	int ans = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
			st.push('(');
		else if (str[i] == ')')
		{
			if (!st.empty())
			{
				if (st.top() == '(')
					st.pop();
				else
					ans++;
			}
			else
				ans++;
		}
	}
	while (!st.empty())
	{
		if (st.top() == '(')
		{
			ans++;
			st.pop();
		}
		else
			st.pop();
	}
	cout << ans << '\n';
}