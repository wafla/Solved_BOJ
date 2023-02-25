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
	char arr[7] = { 'U','C','P','C','-'};
	string s;
	getline(cin, s);
	int idx = 0;
	for (int i = 0; i < s.size(); i++)
		if (s[i] == arr[idx])
			idx++;
	if (idx == 4)
		cout << "I love UCPC\n";
	else
		cout << "I hate UCPC\n";
}