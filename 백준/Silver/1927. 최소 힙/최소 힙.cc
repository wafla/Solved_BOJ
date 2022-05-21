#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	priority_queue<int> h;
	int n, k;
	cin >> n;
	while (n--)
	{
		cin >> k;
		if (k == 0)
		{
			if (h.empty() == 1)
				cout << "0\n";
			else
			{
				cout << -h.top() << "\n";
				h.pop();
			}
		}
		else
			h.push(-k);
	}
}