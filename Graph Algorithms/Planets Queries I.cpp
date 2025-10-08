// ^^
// <{:3
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5, l = 30;
int up[maxn][30];
int n, q;

inline int jump(int a, int d)
{
    for (int i = l - 1; i >= 0; --i)
        if (d & (1 << i))
            a = up[a][i];
    return a;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n >> q;

    for (int i = 1; i <= n; ++i)
        cin >> up[i][0];

    for (int d = 1; d < l; ++d)
        for (int i = 1; i <= n; ++i)
            up[i][d] = up[up[i][d - 1]][d - 1];

    while (q-- > 0)
    {
        int x, d;
        cin >> x >> d;
        cout << jump(x, d) << "\n";
    }
}