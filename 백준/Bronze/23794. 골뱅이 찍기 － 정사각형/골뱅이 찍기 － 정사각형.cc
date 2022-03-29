#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
    int n;
	cin >> n;
	for (int i = 0;i < n + 2;i++)
	{
		for (int j = 0;j < n + 2;j++)
		{
			if (i == 0)
				cout << "@";
			else if (j == 0)
				cout << '@';
			else if (i == n + 1)
				cout << "@";
			else if (j == n + 1)
				cout << '@';
			else
				cout << ' ';
		}
		cout << '\n';
	}
}