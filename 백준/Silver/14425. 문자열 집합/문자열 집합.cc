#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <deque>
#include <set>
#define X first
#define Y second
using namespace std;
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	map<string, int> M;
	int n, m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		string str;
		cin >> str;
		M.insert({ str,i });
	}
	int ans = 0;
	for (int i = 0;i < m;i++)
	{
		string str;
		cin >> str;
		if (M.find(str) != M.end())
			ans++;
	}
	cout << ans;
}