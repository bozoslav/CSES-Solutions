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
vector<vector<int>> edges, redges;
vector<int> ord, comp;
bool vis[MAXN];
int n, m;

void dfs1(int i)
{
    vis[i] = 1;
    for (int x : edges[i])
        if (!vis[x])
            dfs1(x);
    ord.push_back(i);
}

void dfs2(int i)
{
    vis[i] = 1;
    comp.push_back(i);
    for (int x : redges[i])
        if (!vis[x])
            dfs2(x);
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    cin >> n >> m;

    edges.assign(n + 1, {});
    redges.assign(n + 1, {});
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        redges[b].push_back(a);
    }

    for (int i = 1; i <= n; ++i)
        if (!vis[i])
            dfs1(i);

    reverse(ALL(ord));
    memset(vis, 0, sizeof vis);

    int p = -1;
    for (int x : ord)
    {
        if (!vis[x])
        {
            dfs2(x);
            if (comp.size() == n)
            {
                cout << "YES";
                return 0;
            }
            else
            {
                if (p == -1)
                    p = comp[0];
                else
                {
                    cout << "NO\n"
                         << comp[0] << " " << p;
                    return 0;
                }
            }
            comp.clear();
        }
    }

    return 0;
}