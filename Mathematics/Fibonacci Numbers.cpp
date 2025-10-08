// ^^
// <{:3
#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;

int add(int a, int b) { return (a += b) < mod ? a : a - mod; }
int sub(int a, int b) { return (a -= b) >= 0 ? a : a + mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }
int pwr(int a, int p)
{
    if (p == 0)
        return 1;
    if (p & 1)
        return mul(a, pwr(a, p - 1));
    return pwr(mul(a, a), p / 2);
}
int inv(int a) { return pwr(a, mod - 2); }

struct Matrix
{
    vector<vi> A;
    int dim;
    Matrix() {}
    Matrix(int n) : dim(n) { A.assign(n, vi(n)); }
    vi &operator[](int n) { return A[n]; }
};

Matrix operator*(Matrix A, Matrix B)
{
    int n = A.dim;
    Matrix C(n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                C[i][j] = add(C[i][j], mul(A[i][k], B[k][j]));

    return C;
}

Matrix operator^(Matrix A, ll k)
{
    int n = A.dim;
    Matrix R(n);
    for (int i = 0; i < n; ++i)
        R[i][i] = 1;

    while (k > 0)
    {
        if (k % 2)
            R = R * A;

        A = A * A;
        k /= 2;
    }
    return R;
}

signed main()
{
    cin.tie(NULL)->sync_with_stdio(false);

    int n;
    cin >> n;

    if (!n)
    {
        cout << n;
        return 0;
    }

    Matrix mat(3);
    mat[0][0] = 1;
    mat[0][1] = 1;
    mat[1][0] = 1;
    mat[2][1] = 1;

    mat = mat ^ (n - 2);

    vector<int> fib = {1, 1, 2}, res(3);

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            res[i] = (res[i] + ((mat[i][j] * fib[j]) % mod)) % mod;

    cout << res[0];
}