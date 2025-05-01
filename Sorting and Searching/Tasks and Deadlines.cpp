#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<int, int>> tasks(n);
    for (auto &[a, d] : tasks)
        cin >> a >> d;

    sort(tasks.begin(), tasks.end());

    ll res = 0, tr = 0;

    for (auto [x, y] : tasks)
    {
        tr += x;
        res += y - tr;
    }

    cout << res;
}
