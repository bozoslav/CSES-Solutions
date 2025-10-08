// ^^
// <{:3
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,tune=native")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #define int long signed long int
using namespace std;

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0)
    {
        int n;
        cin >> n;

        vector<int> v(n);
        for (auto &x : v)
            cin >> x;

        int x = 0;
        for (int y : v)
            x ^= y;

        cout << (x ? "first" : "second") << "\n";
    }
}
