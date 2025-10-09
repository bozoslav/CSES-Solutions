#include <bits/stdc++.h>
const int maxn = 1001, inf = 1e9;
using namespace std;
int ans[maxn][maxn];
int n;

int di[] = {2, 2, 1, 1, -1, -1, -2, -2};
int dj[] = {1, -1, 2, -2, 2, -2, -1, 1};

int main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans[i][j] = inf;

    queue<pair<int, int>> q;
    q.emplace(0, 0);
    ans[0][0] = 0;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        int dep = ans[x][y];

        for (int i = 0; i < 8; ++i)
        {
            int sx = x + di[i];
            int sy = y + dj[i];

            if (sx >= 0 && sy >= 0 && sx < n && sy < n && ans[sx][sy] == inf)
            {
                ans[sx][sy] = dep + 1;
                q.emplace(sx, sy);
            }
        }
    }

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}