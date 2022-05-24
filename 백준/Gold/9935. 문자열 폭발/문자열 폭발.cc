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
	string str, b;
	cin >> str >> b;
	deque<char> st;
	for (int i = 0;i < str.size();i++)
	{
		int x = b.size() - 1;
		st.push_back(str[i]);
		stack<char> tmp;
		while (st.back() == b[x])
		{
			tmp.push(st.back());
			st.pop_back();
			x--;
			if (x < 0 || st.empty())
				break;
		}
		if (x >= 0)
		{
			while (!tmp.empty())
			{
				st.push_back(tmp.top());
				tmp.pop();
			}
		}
	}
	if (st.size() == 0)
		cout << "FRULA";
	else
	{
		while (!st.empty())
		{
			cout << st.front();
			st.pop_front();
		}
	}
}