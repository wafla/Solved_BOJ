#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 0;
    
    while(1)
    {
        if(a==b)
            break;
        if(a%2)
            a=(a+1)/2;
        else
            a/=2;
        if(b%2)
            b=(b+1)/2;
        else
            b/=2;
        answer++;
    }

    return answer;
}