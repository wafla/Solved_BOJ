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
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '<')
		{
			int j = i;
			for (; j < s.size(); j++)
			{
				cout << s[j];
				if (s[j] == '>')
					break;
			}
			i = j;
		}
		else if (s[i] == ' ')
			cout << " ";
		else
		{
			int idx = i, j;
			for (j = idx; j < s.size(); j++)
			{
				if (s[j] == ' ' || s[j] == '>' || s[j] == '<')
					break;
			}
			j--;
			i = j;
			for (; j >= idx; j--)
				cout << s[j];
		}
	}
	cout << '\n';
}