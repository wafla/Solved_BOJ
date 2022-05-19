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
	string str;
	cin >> str;
	int cnt = 0;
	for (int i = 0;i < n;i++)
		if (str[i] == 'C')
			cnt++;
	cout << ceil((float)cnt / (float)(n - cnt + 1));
}