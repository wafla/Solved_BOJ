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
	int x, y;
	cin >> x >> y;
	int a = 100 - x;
	int b = 100 - y;
	int c = 100 - a - b;
	int d = a * b;
	int q = d / 100;
	int r = d % 100;
	cout << a << " " << b << " " << c << " " << d << " " << q << " " << r << '\n';
	cout << c + q << " " << r;
}