#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("popcnt")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2")
// #pragma GCC target("avx2")

#include <bits/stdc++.h>

long long FLOOR(long long n, long long div) { return n >= 0 ? n / div : (n - div + 1) / div; }
long long CEIL(long long n, long long div) { return n >= 0 ? (n + div - 1) / div : n / div; }
#define UNIQUER(a) (a).resize(unique((a).begin(), (a).end()) - (a).begin())
#define UNIQUE(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define prec cout << fixed << setprecision(10)
#define ALLR(a) (a).rbegin(), (a).rend()
#define ALL(a) (a).begin(), (a).end()
// 0x3f3f3f3f ^
using namespace std;
using ll = long long;
const int MAXN = 1e5 + 5;
int sz[MAXN], p[MAXN], e[MAXN];
int comp = 0, mx = 1;

int f(int i)
{
    if (i == p[i])
        return i;
    return p[i] = f(p[i]);
}

inline void ma(int i)
{
    p[i] = i;
    sz[i] = 1;
}

inline void u(int a, int b)
{
    a = f(a);
    b = f(b);

    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);

        comp -= ((((sz[a] - 1) == e[a]) + ((sz[b] - 1) == e[b])));

        e[b] += e[a] + 1;
        sz[b] += sz[a];

        sz[a] = 0;
        e[a] = 0;

        if ((sz[b] - 1) == e[b])
        {
            ++comp;
            mx = max(mx, sz[b]);
        }
        p[a] = b;
    }
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int n, m;
    cin >> n >> m;

    comp = n;
    for (int i = 1; i <= n; ++i)
        ma(i);

    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        u(a, b);
        cout << comp << " " << mx << "\n";
        /*
        cout << "out" << i + 1 << ":\n";
        for (int i = 1; i <= n; ++i)
            cout << sz[i] << " " << e[i] << "\n";
        for (int i = 1; i <= n; ++i)
            cout << p[i] << " ";
        cout << "\n";
        */
    }

    return 0;
}