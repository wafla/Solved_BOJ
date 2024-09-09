#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> a={1,2,3,4,5};
    vector<int> b={2,1,2,3,2,4,2,5};
    vector<int> c={3,3,1,1,2,2,4,4,5,5};
    vector<int> cnt(3, 0);
    int maxx = 0;
    int idx_a=0,idx_b=0,idx_c=0;
    for(int i=0;i<answers.size();i++)
    {
        if(answers[i]==a[idx_a])
            cnt[0]++;
        if(answers[i]==b[idx_b])
            cnt[1]++;
        if(answers[i]==c[idx_c])
            cnt[2]++;
        idx_a++;
        idx_b++;
        idx_c++;
        if(idx_a>=a.size())
            idx_a=0;
        if(idx_b>=b.size())
            idx_b=0;
        if(idx_c>=c.size())
            idx_c=0;
    }
    maxx = max(cnt[0],max(cnt[1],cnt[2]));
    for(int i=0;i<3;i++)
        if(cnt[i]==maxx)
            answer.push_back(i + 1);
    return answer;
}