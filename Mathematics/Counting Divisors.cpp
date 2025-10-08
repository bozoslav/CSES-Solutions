// ^^
// <{:3
#include <bits/stdc++.h>
// #define int long long
using namespace std;

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int q;
    cin >> q;

    while (q-- > 0)
    {
        int x;
        cin >> x;

        int ans = 0;
        for (int i = 1; i * i <= x; ++i)
        {
            if (x % i == 0)
            {
                if (i * i != x)
                    ans += 2;
                else
                    ++ans;
            }
        }

        cout << ans << "\n";
    }
}