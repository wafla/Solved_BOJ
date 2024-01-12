#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n), v2(n);
	for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        v2[i] = v[i];
    }
	sort(v.begin(), v.end());
	v.resize(unique(v.begin(), v.end()) - v.begin());
	for (auto i : v2)
		cout << lower_bound(v.begin(),v.end(),i)-v.begin() << " ";
	cout << '\n';
    return 0;
}