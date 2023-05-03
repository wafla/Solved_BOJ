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
	int a, b;
	cin >> a >> b;
	bitset<10> A(a), B(b);
	bitset<10> x = (A ^ B);
	string s = x.to_string();
	int num = 512, ans = 0;
	for (int i = 0; i < 10; i++)
	{
		if (s[i] == '1')
			ans += num;
		num /= 2;
	}
	cout << ans << '\n';
}