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
	int n;
	cin >> n;
	vector<vector<int>> v(n);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x;
			cin >> x;
			v[j].push_back(x); 
		}
	}
	for (int i = 0; i < n; i++)
	{
		sort(v[i].begin(), v[i].end());
		if (i == 0)
			v[i][1] = v[i][0];
		else
		{
			if (v[i][0] > v[i - 1][1])
				v[i][1] = v[i][0];
			else if (v[i][2] > v[i - 1][1])
				v[i][1] = v[i - 1][1] + 1;
			sort(v[i].begin(), v[i].end());
			if (v[i][1] <= v[i - 1][1])
			{
				cout << "NO\n";
				return 0;
			}
		}
	}
	cout << "YES\n";
}