// ^^
// <{:3
#include <bits/stdc++.h>
// #define int long long
// const int inf = 1e18;
using namespace std;

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<int> v;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        v.push_back(stoi(s, nullptr, 2));
    }

    int ans = 1e9;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            ans = min(ans, __builtin_popcount(v[i] ^ v[j]));

    cout << ans;
}