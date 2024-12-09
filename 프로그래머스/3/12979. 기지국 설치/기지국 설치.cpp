#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int num = 1;
    stations.push_back(n+1+w);
    for(int i=0;i<stations.size();i++)
    {
        int mid = stations[i];
        int left = mid - w;
        int right = mid + w;
        if(num < left)
        {
            int x = ceil(double(left-num)/double(2*w+1));
            answer+=x;
        }
        num = right + 1;
    }

    return answer;
}