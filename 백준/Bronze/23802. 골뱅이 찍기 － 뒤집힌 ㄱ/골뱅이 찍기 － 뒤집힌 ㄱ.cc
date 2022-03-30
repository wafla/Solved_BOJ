#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0;i < n * 5;i++)
	{
		for (int j = 0;j < n * 5;j++)
			if (i < n || j < n)
				cout << '@';
		cout << '\n';
	}
}