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
#define INF 987654321
#define MOD 1000000007
#define ll long long
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int t;
	cin >> t;
	int maxx = 0;
	string ans;
	map<string, int> M;
	for (int i = 0; i < t; i++)
	{
		string s;
		cin >> s;
		M[s]++;
		if (M[s] > maxx)
		{
			maxx = M[s];
			ans = s;
		}
		else if (M[s] == maxx && s < ans)
			ans = s;
	}
	cout << ans;
}