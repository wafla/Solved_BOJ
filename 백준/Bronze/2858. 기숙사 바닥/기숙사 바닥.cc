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
	int r, b;
	cin >> r >> b;
	vector<int> v;
	for (int i = 2; i < sqrt(r + b) + 1; i++)
		if ((r + b) % i == 0)
		{
			v.push_back((r + b) / i);
			v.push_back(i);
		}
	sort(v.begin(), v.end());
	int i = 0, j = v.size() - 1;
	while (i <= j)
	{
		if (v[i] * v[j] == r + b && (v[j] - 2) * (v[i] - 2) == b)
		{
			cout << v[j] << " " << v[i] << '\n';
			break;
		}
		i++;
		j--;
	}
}