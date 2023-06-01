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
	int n;
	cin >> n;
	vector<pi> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i].X;
		v[i].Y = i;
	}
	int prv = v[n - 1].X, cnt = 0;
	vector<int> ans;
	stack<pi> st;
	st.push(v[n - 1]);
	ans.push_back(0);
	for (int i = n - 2; i >= 0; i--)
	{
		if (v[i].X > st.top().X)
		{
			ans.push_back(st.top().Y - v[i].Y);
			st.push(v[i]);
		}
		else
		{
			while (!st.empty() && v[i].X < st.top().X)
				st.pop();
			if (st.empty())
				ans.push_back(0);
			else
				ans.push_back(st.top().Y - v[i].Y);
			st.push(v[i]);
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		if (ans[i] == 0)
			cout << "infinity\n";
		else
			cout << ans[i] << '\n';
	}
}