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
#include <unordered_map>
#include <tuple>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define LINF 9223372036854775807
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int, int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string s;
	cin >> s;
	stack<pair<char, int>> st;
	stack<pair<char, int>> tmp;
	for (auto i : s)
		st.push({ i,0 });

	while (st.size())
	{
		auto cur = st.top();
		st.pop();
		if (cur.X == 'x')
		{
			tmp.push(cur);
		}
		else if (cur.X == 'g')
		{
			if (!tmp.size())
			{
				cout << -1 << '\n';
				return 0;
			}

			auto cur2 = tmp.top();
			tmp.pop();
			if (cur2.X == 'x')
				tmp.push({ 'x', 1 + cur2.Y });
			else
			{
				cout << -1 << '\n';
				return 0;
			}
		}
		else if (cur.X == 'f')
		{
			if (tmp.size() < 2)
			{
				cout << -1 << '\n';
				return 0;
			}
			auto cur3 = tmp.top();
			tmp.pop();
			auto cur4 = tmp.top();
			tmp.pop();
			if (cur3.X == 'x' && cur4.X == 'x')
				tmp.push({ 'x', min(cur3.Y, cur4.Y) });
			else
			{
				cout << -1 << '\n';
				return 0;
			}
		}
	}

	if (tmp.size() > 1)
		cout << -1 << '\n';
	else
		cout << tmp.top().Y << '\n';
}