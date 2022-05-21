#include <iostream>
#include <queue>
#define X first
#define Y second
using namespace std;
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	priority_queue <pair<long long,int>> h;
	int n;
	cin >> n;
	while (n--)
	{
		int x;
		cin >> x;
		if (x == 0)
		{
			if (h.size() == 0)
				cout << 0 << '\n';
			else {
				cout << h.top().X * h.top().Y << '\n';
				h.pop();
			}
		}
		else {
			if (x > 0)
				h.push({ -x, -1 });
			else
				h.push({ x, 1 });
		}
	}
}