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
	int time = 1, vec = 1;
	string say = "NO";
	for (int i = 0; i < n; i++)
	{
		string s;
		int x;
		cin >> s >> x;
		if (time == 13)
			time = 1;
		else if (time == 0)
			time = 12;
		if (s == "HOURGLASS" && time == x)
		{
			say = "NO";
			cout << time << " " << say << '\n';
			time += vec;
			continue;
		}
		say = "NO";
		if (s == "HOURGLASS")
		{
			vec *= -1;
			say = "NO";
		}
		else if (x == time)
			say = "YES";
		cout << time << " " << say << '\n';
		time += vec;
	}
}