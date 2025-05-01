#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void f(ll i)
{
    cout << i << " ";

    if (i == 1)
        return;

    if (i & 1)
        f((i * 3) + 1);
    else
        f(i / 2);

    return;
}

signed main()
{
    ll n;
    cin >> n;
    f(n);
}