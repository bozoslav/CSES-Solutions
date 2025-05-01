#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    int sum = 0, mx = -1;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        sum += x;
        mx = max(mx, x);
    }

    cout << max(sum, 2 * mx);
}