#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <sstream> // stringstream 추가
#define X first
#define Y second
using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(), 0); // answer를 id_list 크기만큼 0으로 초기화
    map<string, int> M; // 신고당한 횟수 저장
    map<string, set<string>> S; // 신고자별로 신고한 대상 저장

    // 신고 처리
    for (const auto& r : report) {
        stringstream ss(r);
        string a, b;
        ss >> a >> b; // 공백을 기준으로 신고자와 신고 대상 분리

        // 동일 사용자가 동일 대상을 여러번 신고하는 것 방지
        if (S[a].count(b) == 0) {
            M[b]++; // 신고당한 횟수 증가
            S[a].insert(b); // 신고 처리
        }
    }

    // 정지된 사용자 저장
    set<string> banned;
    for (const auto& it : M) {
        if (it.Y >= k) {
            banned.insert(it.X); // k번 이상 신고당한 사용자 추가
        }
    }

    // 각 사용자가 받은 메일 횟수 계산
    map<string, int> cnt; // 신고자가 정지된 사용자를 신고했는지 카운트
    for (const auto& s : S) {
        for (const auto& b : s.Y) {
            if (banned.count(b)) {
                cnt[s.X]++; // 정지된 사용자를 신고한 경우 카운트 증가
            }
        }
    }

    // id_list에 맞춰서 결과 저장
    for (int i = 0; i < id_list.size(); i++) {
        answer[i] = cnt[id_list[i]];
    }

    return answer;
}
