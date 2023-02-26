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
int num[8] = { 10,8,6,5,4,3,2,1 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	vector<pair<string, char>> v(8);
	for (int i = 0; i < 8; i++)
		cin >> v[i].X >> v[i].Y;
	sort(v.begin(), v.end());
	int r = 0, b = 0;
	int idx = 0;
	for (auto i : v)
	{
		if (i.Y == 'R')
			r += num[idx++];
		else
			b += num[idx++];
	}
	if (r < b)
		cout << "Blue\n";
	else
		cout << "Red\n";
}