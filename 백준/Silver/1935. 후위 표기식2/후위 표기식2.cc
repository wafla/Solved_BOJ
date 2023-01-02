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
	//ios::sync_with_stdio(false);
	//cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	string str;
	cin >> str;
	stack<double> num;
	map<char, int> M;
	for (int i = 65; i < 65 + n; i++)
	{
		int x;
		cin >> x;
		M[i] = x;
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/')
		{
			double y = num.top();
			num.pop();
			double x = num.top();
			num.pop();
			if (str[i] == '+')
				num.push(x + y);
			else if (str[i] == '-')
				num.push(x - y);
			else if (str[i] == '*')
				num.push(x * y);
			else if (str[i] == '/')
				num.push(x / y);
		}
		else
			num.push(M[str[i]]);
	}
	printf("%.2f", num.top());
}