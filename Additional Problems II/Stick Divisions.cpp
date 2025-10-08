// ^^
// <{:3
#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int x, n;
    cin >> x >> n;

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        q.push(a + b);
        ans += a + b;
    }

    cout << ans;
}