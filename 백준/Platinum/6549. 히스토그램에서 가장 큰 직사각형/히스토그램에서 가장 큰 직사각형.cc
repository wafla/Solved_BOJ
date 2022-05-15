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
long long arr[100002] = { 0 }, n, ans;
int main()
{
	while (1)
	{
		ans = 0;
        memset(arr,0,sizeof(arr));
		cin >> n;
		if (n == 0)
			break;
		for (long long i = 1;i <= n;i++)
			cin >> arr[i];
		stack<long long> st;
		st.push(0);
		for (long long i = 1;i <= n + 1;i++)
		{
			while (!st.empty() && arr[st.top()] > arr[i])
			{
				long long x = st.top();
				st.pop();
				ans = max(ans, arr[x] * (i - st.top() - 1));
			}
			st.push(i);
		}
		cout << ans << '\n';
	}
}