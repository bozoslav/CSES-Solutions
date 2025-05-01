#include <iostream>
#include <vector>
#include <map>
#define int long long
using namespace std;

signed main()
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    int l = 0, r = 0;
    int dist = 0;
    int res = 0;

    map<int, int> cnt;

    while (r < n)
    {
        dist += (cnt.find(v[r]) == cnt.end() || cnt[v[r]] == 0);
        ++cnt[v[r]];

        while (dist > k)
        {
            --cnt[v[l]];
            if (cnt[v[l]] == 0)
                --dist;
            ++l;
        }

        res += r - l + 1;
        ++r;
    }

    cout << res;
}
