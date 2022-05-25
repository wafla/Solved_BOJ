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
	int t;
	cin >> t;
	while (t--)
	{
		vector<string> str;
		int n;
		cin >> n;
		for (int i = 0;i < n;i++)
		{
			string x;
			cin >> x;
			str.push_back(x);
		}
		sort(str.begin(), str.end());
		int check = 0;
		for (int i = 0;i < n - 1;i++)
		{
			if (str[i].size() == str[i + 1].size())
				continue;
			if (str[i][0] == str[i + 1][0])
			{
				int x = 1;
				while (x < str[i].size())
				{
					if (str[i][x] != str[i + 1][x])
						break;
					x++;
				}
				if (x == str[i].size())
				{
					check = 1;
					cout << "NO\n";
					break;
				}
			}
		}
		if (check == 0)
			cout << "YES\n";
	}
}