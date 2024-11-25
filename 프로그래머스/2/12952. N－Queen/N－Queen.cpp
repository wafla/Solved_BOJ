#include <string>
#include <vector>
#include <iostream>
using namespace std;
int arr[13] = { 0 };
int answer = 0;
int check(int i, int n)
{
    for(int j=0;j<i;j++)
    {
        if(arr[i]==arr[j] || abs(arr[i]-arr[j]) == abs(i-j))
            return 0;
    }
    return 1;
}
void solve(int i, int n)
{
    if(i==n)
    {
        answer++;
        return;
    }
    for(int j=0;j<n;j++)
    {
        arr[i] = j;
        if(check(i,n))
            solve(i+1,n);
    }
}
int solution(int n) {
    solve(0,n);
    return answer;
}