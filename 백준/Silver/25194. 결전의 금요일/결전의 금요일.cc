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
vector<int> arr;
int n;
void dfs(int idx, long long sum)
{
	if (sum % 7 == 4)
	{
		if (sum == 0)
			return;
		cout << "YES";
		exit(0);
	}
	if (idx + 1 < n)
	{
		dfs(idx + 1, sum + arr[idx + 1]);
		dfs(idx + 1, sum);
	}
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	int list[7] = { 0 };
	for (int i = 0;i < n;i++)
	{
		int x;
		cin >> x;
		arr.push_back(x);
		list[x % 7] += 1;
	}
	for(int i1=0;i1<list[1]+1;i1++)
		for(int i2=0;i2<list[2]+1;i2++)
			for(int i3=0;i3<list[3]+1;i3++)
				for(int i4=0;i4<list[4]+1;i4++)
					for(int i5=0;i5<list[5]+1;i5++)
						for (int i6=0;i6<list[6]+1;i6++)
							if((i1 + 2 * i2 + 3 * i3 + 4 * i4 + 5 * i5 + 6 * i6) % 7 == 4)
							{
								cout << "YES";
								return 0;
							}
	//dfs(-1, 0);
	cout << "NO";
}