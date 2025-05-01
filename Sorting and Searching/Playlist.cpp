#include <bits/stdc++.h>

long long FLOOR(long long n, long long div) { return n >= 0 ? n / div : (n - div + 1) / div; }
long long CEIL(long long n, long long div) { return n >= 0 ? (n + div - 1) / div : n / div; }
#define UNIQUER(a) (a).resize(unique((a).begin(), (a).end()) - (a).begin())
#define UNIQUE(a) (a).erase(unique((a).begin(), (a).end()), (a).end())
#define prec cout << fixed << setprecision(10)
#define ALLR(a) (a).rbegin(), (a).rend()
#define ALL(a) (a).begin(), (a).end()
// 0x3f3f3f3f
using namespace std;
using ll = long long;
const int MAXN = 2e5 + 1;
int v[MAXN];

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
        cin >> v[i];

    map<int, bool> exist;
    int l = 0, r = 1, mx = 1, tr = 1;
    exist[v[0]] = 1;
    while (r < n) // [l, r]
    {
        while (exist[v[r]])
        {
            exist[v[l]] = 0;
            --tr;
            ++l;
        }
        exist[v[r]] = 1;
        ++tr;
        ++r;
        mx = max(tr, mx);
    }

    cout << mx;

    return 0;
}