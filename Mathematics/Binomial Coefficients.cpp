#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,tune=native")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define int long long
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
using namespace std;
int bin[maxn], inv[maxn];

inline int binpow(int a, int b)
{
    a %= mod;
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

inline void gen()
{
    bin[0] = 1;
    for (int i = 1; i < maxn; ++i)
        bin[i] = (bin[i - 1] * i) % mod;

    inv[maxn - 1] = binpow(bin[maxn - 1], mod - 2);
    for (int i = maxn - 2; i > -1; --i)
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
}

int f(int n, int k) { return bin[n] * inv[k] % mod * inv[n - k] % mod; }

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    gen();

    int n;
    cin >> n;

    while (n-- > 0)
    {
        int a, b;
        cin >> a >> b;
        cout << f(a, b) << "\n";
    }
}