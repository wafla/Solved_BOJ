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
bool cmp(int x, int y)
{
	return x > y;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string s;
	cin >> s;
	vector<int> v(12);
	map<int, int> M;
	set<int> S;
	for (int i = 0; i < 3; i++)
	{
		int x;
		cin >> x;
		M[x]++;
		S.insert(x);
	}
	if (s[0] == 'Y')
		v[0] = M[1]*1 + 2;
	if (s[1] == 'Y')
		v[1] = M[2]*2 + 4;
	if (s[2] == 'Y')
		v[2] = M[3]*3 + 6;
	if (s[3] == 'Y')
		v[3] = M[4]*4 + 8;
	if (s[4] == 'Y')
		v[4] = M[5]*5 + 10;
	if (s[5] == 'Y')
		v[5] = M[6]*6 + 12;
	if (s[6] == 'Y') // Four of a Kind
		for (int i = 1; i <= 6; i++)
			if (M[i] >= 2)
				v[6] = max(v[6], i * 4);
	if (s[7] == 'Y') // Full House
	{
		for (int i = 1; i <= 6; i++)
		{
			if (M[i] == 1)
			{
				if (S.size() == 2)
				{
					int sum = i * 3;
					for (int j = 1; j <= 6; j++)
					{
						if (i == j)
							continue;
						if (M[j] == 2)
							sum += j * 2;
					}
					v[7] = max(v[7], sum);
				}
			}
			else if (M[i] == 2)
			{
				int sum = i * 3;
				for (int j = 1; j <= 6; j++)
					if (M[j] == 1)
						sum += j*2;
				v[7] = max(v[7], sum);
			}
			else if (M[i] == 3)
			{
				int sum = i * 3;
				for (int j = 6; j >= 1; j--)
				{
					if (i == j)
						continue;
					sum += j * 2;
					break;
				}
				v[7] = max(v[7], sum);
			}
		}
	}
	if (s[8] == 'Y') // Little Straight
	{
		int cnt = 0;
		for (int i = 1; i <= 5; i++)
			if (M[i] == 1)
				cnt++;
		if (cnt == 3)
			v[8] = max(v[8], 30);
	}
	if (s[9] == 'Y') // Big Straight
	{
		int cnt = 0;
		for (int i = 2; i <= 6; i++)
			if (M[i] == 1)
				cnt++;
		if (cnt == 3)
			v[9] = max(v[9], 30);
	}
	if (s[10] == 'Y') // Yacht
	{
		for (int i = 1; i <= 6; i++)
			if (M[i] == 3)
				v[10] = max(v[10], 50);
	}
	if (s[11] == 'Y') // Choice
	{
		int sum = 0;
		for (int i = 1; i <= 6; i++)
			if (M[i] >= 1)
				sum += i * M[i];
		sum += 12;
		v[11] = max(v[11], sum);
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0] << '\n';
}