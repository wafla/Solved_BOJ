#include <iostream>
using namespace std;
char arr[4][4] = { 0 };
int check_w()
{
	int a, b, A = 0, B = 0;
	for (int i = 0;i < 3;i++)
	{
		a = 0, b = 0;
		for (int j = 0;j < 3;j++)
		{
			if (arr[i][j] == 'X')
				a++;
			else if (arr[i][j] == 'O')
				b++;
		}
		if (a == 3)
			A++;
		else if (b == 3)
			B++;
	}
	if (A > 0 && B > 0)
		return 3;
	else if (A == 1)
		return 1;
	else if (B == 1)
		return 2;
	else
		return 0;
}
int check_h()
{
	int a, b, A = 0, B = 0;
	for (int i = 0;i < 3;i++)
	{
		a = 0, b = 0;
		for (int j = 0;j < 3;j++)
		{
			if (arr[j][i] == 'X')
				a++;
			else if (arr[j][i] == 'O')
				b++;
		}
		if (a == 3)
			A++;
		else if (b == 3)
			B++;
	}
	if (A > 0 && B > 0)
		return 3;
	else if (A == 1)
		return 1;
	else if (B == 1)
		return 2;
	else
		return 0;
}
int check_r()
{
	int a = 0, b = 0;
	for (int i = 0;i < 3;i++)
	{
		if (arr[i][i] == 'X')
			a++;
		else if (arr[i][i] == 'O')
			b++;
	}
	if (a == 3)
		return 1;
	else if (b == 3)
		return 2;
	else
		return 0;
}
int check_l()
{
	int a = 0, b = 0;
	for (int i = 0;i < 3;i++)
	{
		if (arr[2 - i][i] == 'X')
			a++;
		else if (arr[2 - i][i] == 'O')
			b++;
	}
	if (a == 3)
		return 1;
	else if (b == 3)
		return 2;
	else
		return 0;
}
int main()
{
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	while (1)
	{
		cin >> arr[0][0] >> arr[0][1] >> arr[0][2];
		if (arr[0][0] == 'e')
			break;
		for (int i = 1;i < 3;i++)
			for (int j = 0;j < 3;j++)
				cin >> arr[i][j];
		int x = 0, o = 0, t = 0;
		for (int i = 0;i < 3;i++)
		{
			for (int j = 0;j < 3;j++)
			{
				if (arr[i][j] == 'X')
					x++;
				else if (arr[i][j] == 'O')
					o++;
				else
					t++;
			}
		}

		int cw = check_w();
		int ch = check_h();
		int cr = check_r();
		int cl = check_l();
		if (o > x)
			cout << "invalid\n";
		else if (cw == 3 || ch == 3)
			cout << "invalid\n";
		else if (cw == 1 || ch == 1 || cr == 1 || cl == 1)
		{
			if (x == o + 1)
				cout << "valid\n";
			else
				cout << "invalid\n";
		}
		else if (cw == 2 || ch == 2 || cr == 2 || cl == 2)
		{
			if (x == o)
				cout << "valid\n";
			else
				cout << "invalid\n";
		}
		else if (t == 0)
			cout << "valid\n";
		else
			cout << "invalid\n";
	}
}