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
	string s, str;
	cin >> s >> str;
	queue<string> Q;
	Q.push(str);
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		if (cur.size() < s.size())
			continue;
		if (cur == s)
		{
			cout << 1;
			return 0;
		}
		if (cur[cur.size() - 1] == 'A')
		{
			string tmp = cur;
			tmp.pop_back();
			Q.push(tmp);
		}
		else if (cur[cur.size() - 1] == 'B')
		{
			string tmp = cur;
			tmp.pop_back();
			reverse(tmp.begin(), tmp.end());
			Q.push(tmp);
		}
	}
	cout << 0;
}