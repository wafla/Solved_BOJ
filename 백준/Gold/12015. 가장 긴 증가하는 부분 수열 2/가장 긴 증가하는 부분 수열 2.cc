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
	vector<int> v;
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
//참고: https://velog.io/@pjh612/%EB%B0%B1%EC%A4%80-12015%EB%B2%88-%EA%B0%80%EC%9E%A5-%EA%B8%B4-%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94-%EB%B6%80%EB%B6%84-%EC%88%98%EC%97%B42