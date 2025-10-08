// ^^
// <{:3
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,tune=native")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long signed long int
using namespace std;
const int maxn = 2e6, mod = 1e9 + 7;
int fac[maxn], inv[maxn];
int n, k;

inline int binpow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

inline void gen()
{
    fac[0] = 1;

    for (int i = 1; i < maxn; ++i)
        fac[i] = (fac[i - 1] * i) % mod;

    inv[maxn - 1] = binpow(fac[maxn - 1], mod - 2);

    for (int i = maxn - 2; i > -1; --i)
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    gen();

    cin >> n >> k;

    int ans = (fac[k + n - 1] * inv[n - 1]) % mod;
    ans *= inv[k];

    cout << ans % mod;
}
