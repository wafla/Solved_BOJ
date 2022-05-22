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
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cout << "Scenario #" << i << ":\n";
		int a, b, c;
		cin >> a >> b >> c;
		if (a * a == b * b + c * c)
			cout << "yes\n";
		else if (b * b == a * a + c * c)
			cout << "yes\n";
		else if (c * c == a * a + b * b)
			cout << "yes\n";
		else
			cout << "no\n";
		cout << '\n';
	}
}