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
vector<int> getPI(string p)
{
	int n = p.size(), j = 0;
	vector<int> PI(n);
	for (int i = 1; i < n; i++)
	{
		while (j > 0 && p[i] != p[j])
			j = PI[j - 1];
		if (p[i] == p[j])
			PI[i] = ++j;
	}
	return PI;
}
vector<int> kmp(string t, string p)
{
	vector<int> ans;
	auto PI = getPI(p);
	int n = t.size(), m = p.size(), j = 0;
	for (int i = 0; i < n; i++)
	{
		while (j > 0 && t[i] != p[j])
			j = PI[j - 1];
		if (t[i] == p[j])
		{
			if (j == m - 1)
			{
				ans.push_back(i - m + 1);
				j = PI[j];
			}
			else
				j++;
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string t, p;
	getline(cin, t);
	getline(cin, p);
	auto ans = kmp(t, p);
	cout << ans.size() << '\n';
	for (auto i : ans)
		cout << i + 1 << " ";
	cout << '\n';
}
// 참고 : https://bowbowbow.tistory.com/6, https://chanhuiseok.github.io/posts/algo-14/