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
	set<string> S;
	string str;
	cin >> str;
	for (int i = 0;i < str.size();i++)
	{
		string s;
		for (int j=i;j<str.size();j++)
		{
			s.push_back(str[j]);
			S.insert(s);
		}
	}
	cout << S.size();
}