#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <deque>
#include <set>
#define X first
#define Y second
using namespace std;
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	long long s, sum = 0, i = 1;
	cin >> s;
	if (s == 1)
	{
		cout << 1;
		return 0;
	}
	while (sum <= s)
		sum += i++;
	cout << i - 2;
}