// ^^
// <{:3
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,popcnt,tune=native")
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
// #pragma GCC optimize("O3")
#include <bits/stdc++.h>
// #define int long signed long int
using namespace std;
const int maxn = 2e5 + 5;
vector<int> edges[maxn];
int sz[maxn];
int n;

void dfs(int i, int p)
{
    sz[i] = 1;
    for (int j : edges[i])
    {
        if (j == p)
            continue;
        dfs(j, i);
        sz[i] += sz[j];
    }
}

int f(int i, int p)
{
    for (int j : edges[i])
    {
        if (j == p)
            continue;
        if (sz[j] * 2 > n)
            return f(j, i);
    }
    return i;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    dfs(1, 0);
    cout << f(1, 0);
}