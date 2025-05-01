#include <bits/stdc++.h>
using namespace std;

struct bozo
{
    int sz = 0;
    multiset<int> s, b;

    inline void balance()
    {
        int lf = (sz / 2) + (sz & 1);
        while (s.size() < lf)
        {
            s.insert(*b.begin());
            b.erase(b.begin());
        }
        while (s.size() > lf)
        {
            b.insert(*s.rbegin());
            auto it = s.end();
            --it;
            s.erase(it);
        }
        return;
    }

    inline void ins(int x)
    {
        if (b.size())
        {
            if (x <= *b.begin())
                s.insert(x);
            else
                b.insert(x);
        }
        else
        {
            if (s.size())
            {
                if (x > *s.rbegin())
                    b.insert(x);
                else
                    s.insert(x);
            }
            else
                s.insert(x);
        }
        ++sz;
        balance();
        return;
    }

    inline int get()
    {
        if (!(sz & 1) || !b.size())
            return (*s.rbegin());
        return min(*s.rbegin(), *b.begin());
    }

    inline void er(int x)
    {
        auto pos = s.find(x);
        if (pos != s.end())
            s.erase(pos);
        else
        {
            pos = b.find(x);
            b.erase(pos);
        }
        --sz;
        balance();
        return;
    }

    inline void db()
    {
        for (int i : s)
            cout << i << " ";
        cout << " ";
        for (int i : b)
            cout << i << " ";
        cout << "\n";
    }
};

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    bozo s;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;

    for (int i = 0; i < k; ++i)
        s.ins(v[i]);
    int l = 0, r = k - 1;
    while (1)
    {
        cout << s.get() << " ";

        if (r + 1 == n)
            break;

        ++r;
        s.ins(v[r]);
        s.er(v[l]);
        ++l;
    }
}