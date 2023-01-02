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
	string str;
	cin >> str;
	stack<int> st;
	st.push(-1);
	int maxx = 0;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '(')
			st.push(i);
		else if (str[i] == ')')
		{
			st.pop();
			if (!st.empty())
				maxx = max(maxx, i - st.top());
			else
				st.push(i);
		}
	}
	cout << maxx << '\n';
}
// 참고 : https://justicehui.github.io/sunrin-ps/2018/12/17/BOJ15926/