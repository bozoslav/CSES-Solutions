// ^^
// <{:3
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 2e5 + 5;
int contains[maxn], contained[maxn];
vector<int> nums;

struct segtree
{
    vector<ll> tree;
    segtree(int n) : tree(2 * n)
    {
        for (int i = 0; i < tree.size(); ++i)
            tree[i] = 0;
    }
    void upd(int i)
    {
        i += tree.size() / 2;
        ++tree[i];
        while (i >>= 1)
            tree[i] = tree[i << 1] + tree[i << 1 | 1];
        return;
    }
    ll query(int i, int j)
    {
        i += tree.size() / 2;
        j += tree.size() / 2;
        ll mx = 0;
        while (i <= j)
        {
            if (i & 1)
                mx += tree[i++];
            if (!(j & 1))
                mx += tree[j--];
            i >>= 1;
            j >>= 1;
        }
        return mx;
    }
    void clr()
    {
        for (int i = 0; i < tree.size(); ++i)
            tree[i] = 0;
    }
    ll operator[](int i) { return tree[i + tree.size() / 2]; }
};

inline bool cmp(tuple<int, int, int> aa, tuple<int, int, int> bb)
{
    auto [a, b, c] = aa;
    auto [x, y, z] = bb;
    if (a == x)
        return b > y;
    return a < x;
}

inline int f(int x)
{
    return (lower_bound(nums.begin(), nums.end(), x) - nums.begin());
}

inline void init()
{
    sort(nums.begin(), nums.end());
    nums.resize(unique(nums.begin(), nums.end()) - nums.begin());
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        nums.push_back(x);
        nums.push_back(y);
        v.emplace_back(x, y, i);
    }

    init();
    for (auto &[x, y, idx] : v)
    {
        x = f(x);
        y = f(y);
    }
    sort(v.begin(), v.end(), cmp);

    segtree s(nums.size());

    for (int i = 0; i < n; ++i)
    {
        auto [x, y, idx] = v[i];

        contained[idx] = s.query(y, nums.size() - 1);

        s.upd(y);
    }

    s.clr();
    reverse(v.begin(), v.end());

    for (int i = 0; i < n; ++i)
    {
        auto [x, y, idx] = v[i];

        contains[idx] = s.query(x, y);

        s.upd(y);
    }

    for (int i = 0; i < n; ++i)
        cout << contains[i] << " ";
    cout << "\n";
    for (int i = 0; i < n; ++i)
        cout << contained[i] << " ";
}
