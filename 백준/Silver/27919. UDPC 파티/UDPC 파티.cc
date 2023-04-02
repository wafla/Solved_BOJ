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
	map<char, int> M;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'U' || s[i] == 'C')
		{
			M['U']++;
			M['C']++;
		}
		else if (s[i] == 'D' || s[i] == 'P')
		{
			M['D']++;
			M['P']++;
		}
	}
	if (M['U'] > 0 && M['P'] > 0)
	{
		if (M['U'] <= ceil((float(M['P']) / 2)))
			cout << "DP\n";
		else
			cout << "UDP\n";
	}
	else if (M['U'] == 0)
		cout << "DP\n";
	else if (M['P'] == 0)
		cout << "U\n";
}