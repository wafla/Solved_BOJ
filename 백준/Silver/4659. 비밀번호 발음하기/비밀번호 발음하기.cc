#include <iostream>
#include <string>
using namespace std;

int moem(char s)
{
	if (s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
	{
		return 1;
	}
	else return 0;
}

int check(string s)
{
	int firstflag = 0; 
	for (int i = 0; i < s.length(); i++)
	{
		if (moem(s[i]) == 1) 
		{
			firstflag = 1;
			break;
		}
	}

	if (s.length() >= 3)
	{

		for (int i = 0; i < s.length() - 2; i++)
		{
			if (moem(s[i]) == 1 && moem(s[i + 1]) == 1 && moem(s[i + 2]) == 1)
			{
				return 0;
			}
			else if (moem(s[i]) == 0 && moem(s[i + 1]) == 0 && moem(s[i + 2]) == 0)
			{
				return 0;
			}
		}
	}

	if (s.size() >= 2)
	{

		for (int i = 0; i < s.size() - 1; i++)
		{
			if (s[i] == s[i + 1] && s[i] != 'e' && s[i] != 'o')
			{
				return 0;
			}
		}

	}



	if (firstflag == 1) return 1;
    else return 0;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s;
	while (1)
	{
		cin >> s;
		if (s == "end") break;
		if (check(s) == 1)
		{
			cout << "<" + s + "> is acceptable.\n";
		}
		else
		{
			cout << "<" + s + "> is not acceptable.\n";
		}
	}
}
//https://www.acmicpc.net/board/view/125944