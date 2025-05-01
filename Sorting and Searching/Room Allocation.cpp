#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 5;
int res[MAXN];

inline bool cmp(tuple<int, int, int> xx, tuple<int, int, int> yy)
{
    auto [a, b, c] = xx;
    auto [x, y, z] = yy;

    if (a != x)
        return a < x;
    return b > y;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);
    cin.exceptions(cin.failbit);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        v.emplace_back(a, 1, i); // ulaz
        v.emplace_back(b, 0, i);
    }

    int cnt = 0;
    sort(v.begin(), v.end(), cmp);
    priority_queue<int, vector<int>, greater<int>> q;
    for (auto &[a, x, i] : v)
    {
        if (x)
        {
            if (q.empty())
                q.push(++cnt);
            res[i] = q.top();
            q.pop();
        }
        else
            q.push(res[i]);
    }

    cout << cnt << "\n";
    for (int i = 0; i < n; ++i)
        cout << res[i] << " ";
}