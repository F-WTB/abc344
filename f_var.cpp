#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using pr = pair<int, int>;
using mint = modint998244353;
ostream &operator<<(ostream &os, const mint &x)
{
    os << x.val();
    return os;
}
struct fast
{
    fast()
    {
        cin.tie(0);
        ios::sync_with_stdio(0);
    }
} fast;
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
int N, P[80][80], R[80][80], D[80][80];
void input()
{
    cin >> N;

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> P[i][j];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N - 1; ++j)
            cin >> R[i][j];
    for (int i = 0; i < N - 1; ++i)
        for (int j = 0; j < N; ++j)
            cin >> D[i][j];
}

ll c[80][80][80][80], n[80][80];
int r[80][80];
int main()
{
    input();
    fill(c[0][0][0], c[N][0][0], 1e18);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            c[i][j][i][j] = 0;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (int I = i; I < N; ++I)
                for (int J = j; J < N; ++J)
                {
                    if (J + 1 < N)
                        chmin(c[i][j][I][J + 1], c[i][j][I][J] + R[I][J]);
                    if (I + 1 < N)
                        chmin(c[i][j][I + 1][J], c[i][j][I][J] + D[I][J]);
                }

    fill(n[0], n[N], 1e18);
    n[0][0] = 0;
    for (int I = 0; I < N; ++I)
        for (int J = 0; J < N; ++J)
            for (int i = 0; i <= I; ++i)
                for (int j = 0; j <= J; ++j)
                {
                    ll t = max(0ll, (c[i][j][I][J] - r[i][j] + P[i][j] - 1) / P[i][j]);
                    ll nn = n[i][j] + t;
                    int nr = r[i][j] + P[i][j] * t - c[i][j][I][J];
                    if (nn < n[I][J] || nn == n[I][J] && nr > r[I][J])
                    {
                        n[I][J] = nn;
                        r[I][J] = nr;
                    }
                }
    cout << n[N - 1][N - 1] + N * 2 - 2 << '\n';
}
