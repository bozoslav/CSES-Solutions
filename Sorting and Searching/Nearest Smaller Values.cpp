#include <bits/stdc++.h>

using namespace std;
const int MAX = 1e9 + 7;

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    stack<pair<int, int>> a;
    vector<int> v(n);

    for (auto &x : v)
        cin >> x;

    for (int i = 0; i < n; ++i)
    {
        while (a.size() > 0 && a.top().first >= v[i])
            a.pop();
        if (a.size() > 0)
            cout << a.top().second << " ";
        else
            cout << "0 ";
        a.push({v[i], i + 1});
    }
}
