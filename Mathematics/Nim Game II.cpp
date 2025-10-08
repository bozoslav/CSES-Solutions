// ^
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
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

        int ans = 0;
        for (int &x : v)
        {
            x %= (3 + 1); // k+1
            ans ^= x;
        }

        if (!ans)
            cout << "second\n";
        else
            cout << "first\n";
    }
}
