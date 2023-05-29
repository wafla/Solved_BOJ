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
	int t;
	cin >> t;
	cin.ignore();
	while (t--)
	{
		string s;
		getline(cin, s);
		int idx = 0;
		while (s[idx] != ' ')
			idx++;
		cout << "god";
		for (int i = idx; i < s.size(); i++)
		{
			if (s[i] == ' ')
				continue;
			else
				cout << s[i];
		}
		cout << '\n';
	}
}