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
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	int arr1[9] = { 0 }, arr2[9] = { 0 };
	int sum1 = 0, sum2 = 0, check = 0;
	for (int i = 0;i < 9;i++)
		cin >> arr1[i];
	for (int i = 0;i < 9;i++)
		cin >> arr2[i];
	for (int i = 0;i < 9;i++)
	{
		sum1 += arr1[i];
		if (sum1 > sum2)
			check = 1;
		sum2 += arr2[i];
	}
	if (sum1 > sum2)//이김
		cout << "No";
	if (sum1 < sum2)
	{
		if (check == 0)//그냥 짐
			cout << "No";
		else//역전패
			cout << "Yes";
	}
}