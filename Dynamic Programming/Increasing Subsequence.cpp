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

inline int lis(vector<int> &v)
{
    vector<int> l;
    for (int i = 0; i < (int)v.size(); ++i)
    {
        auto pos = lower_bound(ALL(l), v[i]);
        if (pos == l.end())
        {
            l.push_back(v[i]);
            continue;
        }
        l[pos - l.begin()] = v[i];
    }
    return l.size();
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    cout << lis(v);

    return 0;
}