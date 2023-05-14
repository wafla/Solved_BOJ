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
	while (t--)
	{
		string s;
		cin >> s;
		int flag = 0;
		while (s.size())
		{
			if (s.size() > 1)
			{
				if (s.size() > 2)
				{
					if (s[0] == '1' && s[1] == '0' && s[2] == '0')
					{
						s.erase(0, 3);
						while (s[0] == '0')
							s.erase(0, 1);
						if (s[0] == '1')
						{
							s.erase(0, 1);
							while (s[0] == '1')
							{
								if (s[0] == '1' && s[1] == '0' && s[2] == '0')
									break;
								s.erase(0, 1);
							}
						}
						else
						{
							flag = 1;
							break;
						}
					}
					else if (s[0] == '0' && s[1] == '1')
						s.erase(0, 2);
					else
					{
						flag = 1;
						break;
					}
				}
				else
				{
					if (s[0] == '0' && s[1] == '1')
						s.erase(0, 2);
					else
					{
						flag = 1;
						break;
					}
				}
			}
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
}