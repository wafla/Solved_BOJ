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
#define x first
#define y second
using namespace std;
int arr[1000001] = { 0 };
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0;i < n;i++)
		cin >> arr[i];
	vector<long long> v;
	v.push_back(arr[0]);
	for (int i = 1;i < n;i++)
	{
		if (v.back() < arr[i])
			v.push_back(arr[i]);
		else if(v.back() > arr[i])
		{
			auto low = lower_bound(v.begin(), v.end(), arr[i]);
			*low = arr[i];
		}
	}
	cout << v.size();
}