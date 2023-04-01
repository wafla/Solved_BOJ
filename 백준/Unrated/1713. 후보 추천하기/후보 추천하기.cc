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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	map<int, pair<int,int>> M; // 번호, 추천수, 날짜
	int n, k, x;
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> x;
		if (M.find(x) != M.end()) // 값이 있는 경우
			M[x].X++;
		else if (M.size() < n) // 없는 경우
			M.insert({ x, {1,i} });
		else // 새로 추가할 경우
		{
			int num = 0, r = INF, l = INF;
			for (auto j : M)
			{
				if (j.Y.X < r || (j.Y.X == r && j.Y.Y < l))
				{
					num = j.X;
					r = j.Y.X;
					l = j.Y.Y;
				}
			}
			M.erase(num);
			M.insert({ x,{1,i} });
		}
	}
	for (auto i : M)
		cout << i.X << " ";
	cout << '\n';
}
// 참고 : https://velog.io/@beclever/C-%EB%B0%B1%EC%A4%80-1713%EB%B2%88-%ED%9B%84%EB%B3%B4-%EC%B6%94%EC%B2%9C%ED%95%98%EA%B8%B0