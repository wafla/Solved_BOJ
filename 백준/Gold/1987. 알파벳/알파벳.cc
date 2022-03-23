#include <iostream>
using namespace std;
char arr[21][21] = { 0 };
int al[26] = { 0 }, v[21][21] = { 0 };
int dx[4] = { -1,0,1,0 }, dy[4] = { 0,-1,0,1 };
int r, c, maxx = 0;
void solve(int i, int j, int num)
{
	al[arr[i][j] - 65] = 1;
	v[i][j] = 1;
	for (int x = 0; x < 4; x++)
	{
		int nx = i + dx[x];
		int ny = j + dy[x];
		if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			continue;
		if (v[nx][ny] == 0 && al[arr[nx][ny] - 65] == 0)
			solve(nx, ny, num + 1);
	}
	if (maxx < num)
		maxx = num;
	al[arr[i][j] - 65] = 0;
	v[i][j] = 0;
}
int main()
{
	ios::sync_with_stdio();
	cin.tie(0), cout.tie(0);
	cin >> r >> c;
	for (int i = 0;i < r;i++)
		for (int j = 0;j < c;j++)
			cin >> arr[i][j];
	solve(0, 0, 1);
	cout << maxx;
}