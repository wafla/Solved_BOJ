#include <iostream>
using namespace std;
int arr[6145][6145] = {0}, n;
void re(int idx, int x, int y)
{
	if (idx > n + 1)
		return;
	int a = 0;
	int xx = x;
	int yy = y;
	for (int i = idx / 2; i < idx; i++)
	{
		yy = y-a;
		for (int j = y - idx / 2 - a;j <= y - idx / 2 + a;j++)
		{
			arr[i][j] = arr[xx][yy];
			yy++;
		}
		yy = y-a;
		for (int j = y + idx / 2 - a; j <= y + idx / 2 + a; j++)
		{
			arr[i][j] = arr[xx][yy];
			yy++;
		}
		a++;
		xx++;
	}
	re(idx * 2, x, y);
}
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	n--;
	arr[0][n] = '*';//초기 배열(n=3)
	arr[1][n - 1] = '*';
	arr[1][n + 1] = '*';
	arr[2][n - 2] = '*';
	arr[2][n - 1] = '*';
	arr[2][n] = '*';
	arr[2][n + 1] = '*';
	arr[2][n + 2] = '*';
	re(6, 0, n);//재귀로 전 값(idx)을 다음(idx*2) 왼쪽, 오른쪽에 복사
	n++;
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < 2 * n - 1;j++)
		{
			if (arr[i][j] == '*')
				cout << char(arr[i][j]);
			else
				cout << char(32);
		}
		cout << '\n';
	}
}