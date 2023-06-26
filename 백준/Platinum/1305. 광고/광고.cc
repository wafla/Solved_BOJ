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
int L;
string s;
int getPI()
{
	int j = 0;
	vector<int> PI(L);
	for (int i = 1; i < L; i++)
	{
		while (j > 0 && s[i] != s[j])
			j = PI[j - 1];
		if (s[i] == s[j])
			PI[i] = ++j;
	}
	return PI[L-1];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> L >> s;
	int PI = getPI();
	cout << L - PI << '\n';
}