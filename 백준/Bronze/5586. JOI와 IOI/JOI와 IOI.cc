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
	cin >> s;
	int a = 0, b = 0;
	for (int i = 0; i < s.size() - 2; i++)
	{
		if (s[i + 1] == 'O' && s[i + 2] == 'I')
		{
			if (s[i] == 'J')
				a++;
			else if (s[i] == 'I')
				b++;
		}
	}
	cout << a << '\n' << b;
}