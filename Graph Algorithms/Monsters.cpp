#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
const int mod = 1e9 + 7;

const int maxn = 1005;
char g[maxn][maxn];
int d[maxn][maxn];

// c[i][j] = -1 onda do njega ne mozemo stici ni mi ni cudovista
// c[i][j] = 0 ako smo mi prije stigli do (i, j)
// c[i][j] = 1 ako su cudovista prije stigla do (i, j)
int c[maxn][maxn];
pair<int, int> p[maxn][maxn];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    memset(d, -1, sizeof d);
    memset(c, -1, sizeof c);
    queue<tuple<int, int, int>> q;
    int start_i = 0;
    int start_j = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];

            if (g[i][j] == 'A')
            {
                start_i = i;
                start_j = j;
            }
            else if (g[i][j] == 'M')
            {
                d[i][j] = 0;
                c[i][j] = 1;
                q.emplace(i, j, 1);
            }
        }
    }

    d[start_i][start_j] = 0;
    c[start_i][start_j] = 0;
    q.emplace(start_i, start_j, 0);

    const int di[] = {-1, 0, 0, 1};
    const int dj[] = {0, -1, 1, 0};

    int sol_i = -1;
    int sol_j = -1;
    while (!q.empty())
    {
        auto [i, j, k] = q.front();
        q.pop();

        if (i == n - 1 || j == m - 1 || i == 0 || j == 0)
        {
            if (!k)
            {
                sol_i = i;
                sol_j = j;
            }
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int ni = i + di[dir];
            int nj = j + dj[dir];
            if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                continue;
            if (g[ni][nj] != '.')
                continue;
            if (d[ni][nj] != -1)
                continue;

            d[ni][nj] = d[i][j] + 1;
            c[ni][nj] = c[i][j];
            p[ni][nj] = {i, j};
            q.emplace(ni, nj, c[ni][nj]);
        }
    }

    if (sol_i == -1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        cout << d[sol_i][sol_j] << "\n";

        int i = sol_i;
        int j = sol_j;

        string path = "";

        while (i != start_i || j != start_j)
        {
            auto [ni, nj] = p[i][j];

            if (j == nj + 1)
                path += 'R';
            if (j == nj - 1)
                path += 'L';
            if (i == ni + 1)
                path += 'D';
            if (i == ni - 1)
                path += 'U';
            i = ni;
            j = nj;
        }

        reverse(all(path));
        cout << path;
    }
}
