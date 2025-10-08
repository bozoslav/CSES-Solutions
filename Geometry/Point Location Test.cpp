// ^^
// <{:3
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,tune=native")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long signed long int
// #define ld long double
using namespace std;

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int t;
    cin >> t;

    while (t-- > 0)
    {
        int x1, y1, x2, y2, x3, y3;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

        int prod = (x2 - x1) * (y3 - y1);
        prod -= (y2 - y1) * (x3 - x1);

        if (prod == 0)
            cout << "TOUCH";
        else if (prod > 0)
            cout << "LEFT";
        else
            cout << "RIGHT";
        cout << "\n";
    }
}
