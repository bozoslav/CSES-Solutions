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
set<int> col[maxn];
int v[maxn];

void f(int curr, int p)
{
    for (int x : edges[curr])
    {
        if (x != p)
        {
            f(x, curr);
            if (col[curr].size() < col[x].size())
                swap(col[curr], col[x]);

            for (int y : col[x])
            {
                col[curr].insert(y);
            }
        }
    }
    v[curr] = col[curr].size();
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        col[i].insert(a);
    }

    for (int i = 1; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    f(1, 0);

    for (int i = 1; i <= n; ++i)
        cout << v[i] << " ";
}