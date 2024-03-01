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
#define MOD 1000000009
#define ll long long
#define int long long
#define pi pair<int,int>
#define T pair<int, pi>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string s;
	cin >> s;
	vector<char> st;
	for (int i = 0; i < s.size(); i++)
	{
		st.push_back(s[i]);
		if (st.size() > 3)
		{
			int idx = st.size() - 1;
			if (st[idx - 1] == 'A' && st[idx] == 'P' && st[idx - 2] == 'P' && st[idx - 3] == 'P')
			{
				for (int j = 0; j < 4; j++)
					st.pop_back();
				st.push_back('P');
			}
		}
	}
	s = "";
	for (auto i : st)
		s += i;
	if (s == "P" || s == "PPAP")
		cout << "PPAP\n";
	else
		cout << "NP\n";
}