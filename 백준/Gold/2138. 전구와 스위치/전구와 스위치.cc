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
int n, ans = INF;
string s, str;
int num(char a)
{
	if (a == '0')
		return '1';
	else
		return '0';
}
void solve(int start)
{
	string tmp = s;
	int cnt = 0;
	if (start == 0)
	{
		tmp[0] = num(tmp[0]);
		tmp[1] = num(tmp[1]);
		cnt++;
	}
	for (int i = 1; i < n; i++)
	{
		if (tmp[i - 1] != str[i - 1])
		{
			tmp[i - 1] = num(tmp[i - 1]);
			tmp[i] = num(tmp[i]);
			tmp[i + 1] = num(tmp[i + 1]);
			cnt++;
		}
	}
	if (tmp == str)
		ans = min(cnt, ans);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	cin >> s >> str;
	solve(0);
	solve(1);
	if (ans == INF)
		cout << -1;
	else
		cout << ans;
}
//참고 : https://astrid-dm.tistory.com/429