#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
	int ans = 0, idx = 0;
	while (budget && idx < d.size())
	{
		budget -= d[idx++];
		if (budget < 0)
			break;
		ans++;
	}
	return ans;
}