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
#define a first
#define b second
using namespace std;
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	string str;
	stack<char> st;
	cin >> str;
	for (int i = 0;i < str.length();i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			cout << str[i];
		else if (str[i] == '*' || str[i] == '/')
		{
			while (!st.empty() && (st.top() == '*' || st.top() == '/'))
			{
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		else if (str[i] == '+' || str[i] == '-')
		{
			while (!st.empty() && st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			st.push(str[i]);
		}
		else if(str[i]=='(')
		{
			st.push(str[i]);
		}
		else if (str[i] == ')')
		{
			while (st.top() != '(')
			{
				cout << st.top();
				st.pop();
			}
			st.pop();
		}
	}
	while (!st.empty())
	{
		cout << st.top();
		st.pop();
	}
}