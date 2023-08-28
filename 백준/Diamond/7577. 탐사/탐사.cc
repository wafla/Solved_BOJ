#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <deque>
#include <cmath>
#include <memory.h>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#define X first
#define Y second
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define ll long long
#define int long long
#define pi pair<int,int>
using namespace std;
int arr[41][41] = { 0 };
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, k;
	cin >> n >> k;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			if (i != j)
				arr[i][j] = INF;
	
	// 0 <= psum[i+1] - psum[i] <= 1
	for (int i = 0; i < n; i++)
	{
		arr[i + 1][i] = 0;
		arr[i][i + 1] = 1;
	}

	// psum[y] - psum[x-1] = r
	for (int i = 0; i < k; i++)
	{
		int x, y, z;
		cin >> x >> y >> z;
		if (arr[x - 1][y] > z) // 가장 많은 값으로 저장
			arr[x - 1][y] = z;
		arr[y][x - 1] = -z; // 구간을 계산하기 위해 반대 위치([y][x-1])에 반대값 저장
		// ex) 1~12 = 1~8 + 9~12 -> 1~8 = 1~12 - 12~9
	}

	for (int k = 0; k <= n; k++)
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= n; j++)
				arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);

	for (int i = 0; i <= n; i++)
	{
		if (arr[i][i] < 0) // 음수인 경우 불가능
		{
			cout << "NONE\n";
			return 0;
		}
	}

	// arr[0][n]에는 누적값이 저장돼 있음.
	for (int i = 0; i < n; i++)
	{
		if (arr[0][i + 1] - arr[0][i])
			cout << '#';
		else
			cout << '-';
	}
	cout << '\n';
}
/* 참고: https://ksj14.tistory.com/entry/BaekJoon7577-%ED%83%90%EC%82%AC
 https://m.blog.naver.com/3587jjh/221713610536
 http://codersbrunch.blogspot.com/2016/07/7577.html */