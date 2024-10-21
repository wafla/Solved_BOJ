#include <vector>
#include <set>
#include <math.h>
using namespace std;

int solution(vector<int> nums)
{
    set<int> S;
    for(int i=0;i<nums.size();i++)
        S.insert(nums[i]);
    
    if (S.size() >= nums.size()/2)
    {
        return nums.size()/2;
    }
    else
    {
        return S.size();
    }
}