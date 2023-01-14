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
	map<string, int> M;
	for (int i = 0; i < n; i++)
	{
		string s;
		int x;
		cin >> s >> x;
		M[s] += x;
	}
	if (M["BANANA"] == 5 || M["PLUM"] == 5 || M["LIME"] == 5 || M["STRAWBERRY"] == 5)
		cout << "YES\n";
	else
		cout << "NO\n";
}