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
	vector<string> a;
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		string x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end(), greater<string>());
	for (int i = 0;i < a.size() - 1;i++)
	{
		string tmp1, tmp2;
		tmp1 = a[i] + a[i+1];
		tmp2 = a[i + 1] + a[i];
		if (tmp1 < tmp2)
		{
			string tmp = a[i + 1];
			a[i + 1] = a[i];
			a[i] = tmp;
			i -= 2;
		}
	}
	if (a[0][0] == '0')
		cout << '0';
	else 
		for (string i : a)
			cout << i;
}
//참고 : https://eochodevlog.tistory.com/83