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
	int zero = 0, one = 0;
	if (s[0] == '0')
		zero++;
	else
		one++;
	for (int i = 1; i < s.size(); i++)
	{
		if (s[i] != s[i - 1])
		{
			if (s[i] == '0')
				zero++;
			else
				one++;
		}
	}
	cout << min(zero, one);
	return 0;
}