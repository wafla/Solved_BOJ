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
#define pi pair<int, int>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, k, t, idx = 0;
	cin >> n >> k;
	t = k;
	string s;
	cin >> s;
	deque<int> dq;
	while (k && idx < s.size())
	{
		while (!dq.empty() && k)
		{
			if (dq.back() >= s[idx])
				break;
			else
			{
				dq.pop_back();
				k--;
			}
		}
		dq.push_back(s[idx++]);
	}
	while (idx < s.size())
		dq.push_back(s[idx++]);
	while (dq.size() > n - t)
		dq.pop_back();
	for (auto i : dq)
		cout << char(i);
	cout << '\n';
}