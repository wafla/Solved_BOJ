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
#include <bitset>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define pi pair<int, int>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n;
	set<string> S;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		string tmp, str = "";
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			str += "*" + tmp;
			S.insert(str);
		}
	}
	for (auto i : S)
	{
		int cnt = count(i.begin(), i.end(), '*');
		int idx = i.find_last_of("*");
		string ans = i.substr(idx + 1);
		for (int i = 0; i < cnt - 1; i++)
			cout << "--";
		cout << ans << '\n';
	}
}
// 참고 : https://cocoon1787.tistory.com/809