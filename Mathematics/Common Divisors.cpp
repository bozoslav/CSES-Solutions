// ^^
// <{:3
#include <bits/stdc++.h>
// #define int long long
using namespace std;
const int maxn = 1e6 + 6;
int cnt[maxn];

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    for (int i : v)
    {
        for (int j = 1; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                if (j * j != i)
                {
                    ++cnt[j];
                    ++cnt[i / j];
                }
                else
                    ++cnt[j];
            }
        }
    }

    int nv = 0;
    for (int i = maxn - 1; i > 0; --i)
    {
        if (cnt[i] > 1)
        {
            nv = i;
            break;
        }
    }

    cout << nv;
}
