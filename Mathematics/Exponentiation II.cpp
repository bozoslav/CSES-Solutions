// ^^
// <{:3
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod = 1e9 + 7;

int binpow(int a, int b, int m)
{
    a %= m;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int q;
    cin >> q;

    while (q-- > 0)
    {
        int a, b, c;
        cin >> a >> b >> c;
        int pot = binpow(b, c, mod - 1);
        cout << binpow(a, pot, mod) << "\n";
    }
}