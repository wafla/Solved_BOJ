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
char arr[52][52] = { 0 }, tmp[301][301] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int r, c, zr, zc;
	cin >> r >> c >> zr >> zc;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> arr[i][j];
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			for (int p = i*zr; p < i*zr + zr; p++)
				for (int q = j*zc; q < j*zc + zc; q++)
					tmp[p][q] = arr[i][j];
	for (int i = 0; i < r * zr; i++)
	{
		for (int j = 0; j < c * zc; j++)
			cout << tmp[i][j];
		cout << '\n';
	}
}