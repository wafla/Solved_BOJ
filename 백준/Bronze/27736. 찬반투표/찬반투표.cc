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
	int arr[3] = { 0 };
	for (int i = 0; i < n; i++)
	{
		int x;
		cin >> x;
		if (x == 1)
			arr[0]++;
		else if (x == -1)
			arr[1]++;
		else if (x == 0)
			arr[2]++;
	}
	if (n % 2 == 0)
	{
		if (arr[2] >= n / 2)
			cout << "INVALID\n";
		else if (arr[1] >= arr[0])
			cout << "REJECTED\n";
		else
			cout << "APPROVED\n";
	}
	else if (n % 2 == 1)
	{
		if (arr[2] > n / 2)
			cout << "INVALID\n";
		else if (arr[1] >= arr[0])
			cout << "REJECTED\n";
		else
			cout << "APPROVED\n";
	}
}