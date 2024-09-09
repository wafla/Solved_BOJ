#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int left = 1, right = 1;
	int sum = 1, ans = 0;
	while (left <= right && right <= n)
	{
		if (sum == n)
		{
			ans++;
			sum += ++right;
		}
		else if (sum < n)
		{
			sum += ++right;
		}
		else if (sum > n)
		{
			sum -= left++;
		}
	}
	return ans;
}