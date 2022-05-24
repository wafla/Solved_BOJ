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
		string s, k, tmp = "";
		cin >> s;
		int x;
		cin >> x;
		deque<int> Q;
		cin >> k;
		for (int i = 0;i < k.size();i++)
		{
			if (k[i] == ',' || k[i] == ']')
			{
				if (tmp.size() == 0)
					break;
				Q.push_back(stoi(tmp));
				tmp = "";
			}
			else if (k[i] == '[')
				continue;
			else
				tmp.push_back(k[i]);
		}
		int check = 1;
		for (int i = 0;i < s.size();i++)
		{
			if (s[i] == 'R')
				check = -check;
			else if (s[i] == 'D')
			{
				if (x == 0)
				{
					check = 0;
					break;
				}
				if (check == 1)
				{
					x--;
					Q.pop_front();
				}
				else if (check == -1)
				{
					x--;
					Q.pop_back();
				}
			}
		}
		if (check == 0)
			cout << "error\n";
		else if (check == 1)
		{
			cout << "[";
			for (int i = 0;i < Q.size();i++)
			{
				if (i == Q.size() - 1)
					cout << Q[i];
				else
					cout << Q[i] << ",";
			}
			cout << "]\n";
		}
		else if (check == -1)
		{
			cout << "[";
			for (int i = Q.size() - 1;i >= 0;i--)
			{
				if (i == 0)
					cout << Q[i];
				else
					cout << Q[i] << ",";
			}
			cout << "]\n";
		}
	}
}