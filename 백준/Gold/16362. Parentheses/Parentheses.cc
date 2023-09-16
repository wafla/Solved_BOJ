#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 998244353
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string s;
	getline(cin, s);
	s.push_back(')');
	s.insert(s.begin(), '(');
	stack<char> S;
	int flag = 0;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ')
			continue;
		else
		{
			if (s[i] == ')')
			{
				stack<char> tmp;
				int idx = 1;
				while (1)
				{
					if (S.size() == 0)
					{
						cout << "error\n";
						return 0;
					}
					if (S.top() == '(')
					{
						S.pop();
						S.push('a');
						if (tmp.size())
						{
							char x = tmp.top();
							if (x == '+' || x == '-' || x == '*' || x == '/' || x == '%')
							{
								cout << "error\n";
								return 0;
							}
						}
						else
						{
							cout << "error\n";
							return 0;
						}
						if (tmp.size() == 3)
							break;
						else
							flag = 1;
						break;
					}
					else
					{
						char x = S.top();
						tmp.push(x);
						S.pop();
						if (idx % 2 == 1) // 문자
						{
							if (x == '+' || x == '-' || x == '*' || x == '/' || x == '%')
							{
								cout << "error\n";
								return 0;
							}
						}
						else // 연산자
						{
							if (!(x == '+' || x == '-' || x == '*' || x == '/' || x == '%'))
							{
								cout << "error\n";
								return 0;
							}
						}
						idx++;
					}
				}
			}
			else
				S.push(s[i]);
		}
	}
	if (S.size() == 1)
	{
		if (flag)
			cout << "improper\n";
		else
			cout << "proper\n";
	}
	else
		cout << "error\n";
}