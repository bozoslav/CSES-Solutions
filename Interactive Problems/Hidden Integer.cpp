#include <bits/stdc++.h>
using namespace std;

inline bool ask(int x)
{
    cout << "? " << x << endl;
    string s;
    cin >> s;
    return (s == "YES" ? 1 : 0);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int lo = 1, hi = 1e9;
    while (lo < hi)
    {
        int mid = lo + (hi - lo) / 2;
        if (ask(mid))
            lo = mid + 1;
        else
            hi = mid;
    }

    cout << "! " << lo << endl;

    return 0;
}
