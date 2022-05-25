#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <math.h>
#include <map>
#include <stack>
#include <memory.h>
#include <deque>
#include <set>
#define X first
#define Y second
using namespace std;
int main()
{
	ios::sync_with_stdio(NULL);
	cin.tie(NULL), cout.tie(NULL);
	string S, T;
	cin >> S >> T;
	int ans = 0;
	vector<int> A(T.size());
	for (int i = 0;i < S.size();i++)
	{
		for (int j = 0;j < T.size();j++)
		{
			if (S[i] == T[j])
			{
				if (j == 0)//맨 처음 문자면 바로 +1
					A[j]++;
				else if (A[j - 1] > A[j])//이전 문자가 크면 +1
					A[j]++;
			}
			if (A[T.size() - 1] == 1)//문자를 다 찾았으면 답 +1하고 A 하나씩 빼주기
			{
				for (int i = 0;i < A.size();i++)
					A[i]--;
				ans++;
			}
		}
	}
	cout << ans;
}
//참고 : https://intrepidgeeks.com/tutorial/baijun-24524-beautiful-string