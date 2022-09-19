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
	int x = 0;
	for (int i = 1; i <= 100000; i++)
	{
		x += i;
		if (i%2 && x > n)
		{
			cout << x - n;
			return 0;
		}
		else if(x > n)
			break;
	}
	cout << 0;
}