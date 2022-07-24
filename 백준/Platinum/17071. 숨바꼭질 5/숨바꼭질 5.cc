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
#define INF 987654321
#define MOD 1000000007
#define ll long long
using namespace std;
int n, k;
int v[2][500001]; 
//짝수초에 접근한 위치는 짝수초에 다시 접근 할 수 있고 홀수초에 접근한 위치는 홀수초에 접근 가능.
//수빈이 10초에 X의 위치고 동생이 16초에 X의 위치에 도달한다고 하면 수빈은 6초동안 X-1, X+1을 반복하면 16초에 X에 갈 수 있음.
//따라서 짝수초와 홀수초를 따로 나눠서 v 배열에 저장.
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> k;
	queue<pair<int,int>> S; //위치, 시간
	S.push({ n,0 });
	memset(v, -1, sizeof(v));
	while (!S.empty())
	{
		auto cur = S.front();
		S.pop();
		if (cur.X < 0 || cur.X > 500000)
			continue;
		if (v[cur.Y % 2][cur.X] != -1)
			continue;
		v[cur.Y % 2][cur.X] = cur.Y;
		S.push({ cur.X + 1, cur.Y + 1 });
		S.push({ cur.X - 1, cur.Y + 1 });
		S.push({ cur.X * 2, cur.Y + 1 });
	}
	for (int i = 0; i < 500000; i++)
	{
		int nk = k + i * (i + 1) / 2;
		if (nk > 500000)
			break;
		if (v[i % 2][nk] != -1 && v[i % 2][nk] <= i)
		{
			cout << i << '\n';
			return 0;
		}
	}
	cout << -1 << '\n';
}
//참고 : https://imucoding.tistory.com/736