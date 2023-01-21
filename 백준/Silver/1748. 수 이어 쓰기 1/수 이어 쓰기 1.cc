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
	int i;
	cin >> i;
	if (i <= 9)
		cout << i * 1;
	else if (i <= 99)
		cout << 9 + (i - 9) * 2;
	else if (i <= 999)
		cout << 9 + 90 * 2 + (i - 99) * 3;
	else if (i <= 9999)
		cout << 9 + 90 * 2 + 900 * 3 + (i - 999) * 4;
	else if (i <= 99999)
		cout << 9 + 90 * 2 + 900 * 3 + 9000 * 4 + (i - 9999) * 5;
	else if (i <= 999999)
		cout << 9 + 90 * 2 + 900 * 3 + 9000 * 4 + 90000 * 5 + (i - 99999) * 6;
	else if (i <= 9999999)
		cout << 9 + 90 * 2 + 900 * 3 + 9000 * 4 + 90000 * 5 + 900000 * 6 + (i - 999999) * 7;
	else if (i <= 99999999)
		cout << 9 + 90 * 2 + 900 * 3 + 9000 * 4 + 90000 * 5 + 900000 * 6 + 9000000 * 7 + (i - 9999999) * 8;
	else
		cout << 9 + 90 * 2 + 900 * 3 + 9000 * 4 + 90000 * 5 + 900000 * 6 + 9000000 * 7 + 90000000 * 8 + (i - 99999999) * 9;
}