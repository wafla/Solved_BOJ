#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &i : v)
        cin >> i;
    sort(v.begin(),v.end());
    for(auto i : v)
        cout << i << '\n';
}