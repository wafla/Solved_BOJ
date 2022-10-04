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
    int k;
    cin >> k;
    int num = 1;
    while (num < k)
        num *= 2;
    int cnt = 0, sum = 0;
    if (k == num)
    {
        cout << num << " " << 0;
        return 0;
    }
    cout << num;
    while (sum < k)
    {
        num /= 2;
        sum += num;
        if (sum > k)
            sum -= num;
        cnt++;
    }
    cout << " " << cnt;
}