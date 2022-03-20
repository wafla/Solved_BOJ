#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	string s;
	while (getline(cin,s))
	{
		int a = 0, b = 0, c = 0, d = 0;
		for (int i = 0; i<s.size(); i++)
		{
			if (s[i] >= 97 && s[i] <= 122)
				a++;
			else if (s[i] >= 65 && s[i] <= 90)
				b++;
			else if (s[i] >= 48 && s[i] <= 57)
				c++;
			else if (s[i] == 32)
				d++;
		}
		cout << a << " " << b << " " << c << " " << d << '\n';
	}
}