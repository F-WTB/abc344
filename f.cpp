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
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
inline bool chmax(T &a, T b)
{
    if (b > a)
    {
        a = b;
        return 1;
    }
    return 0;
}
int N, P[80][80], R[80][80], D[80][80];

struct st
{
    ll n = 1e18;
    int r = 0;
    st() {}
    st(ll n, int r) : n(n), r(r) {}
};
bool operator>(st a, st b)
{
    return a.n < b.n || a.n == b.n && a.r > b.r;
}

map<int, st> dp[80][80];

int main()
{
    dp[0][0][0] = st(0, 0);
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

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            for (auto [k, p] : dp[i][j])
            {
                const int m = max(k, P[i][j]);
                auto [n, r] = p;
                int t;
                if (j + 1 < N)
                {
                    t = max(0, (R[i][j] - r + m - 1) / m);
                    chmax(dp[i][j + 1][m], st(n + t, r + (ll)m * t - R[i][j]));
                }
                if (i + 1 < N)
                {
                    t = max(0, (D[i][j] - r + m - 1) / m);
                    chmax(dp[i + 1][j][m], st(n + t, r + (ll)m * t - D[i][j]));
                }
            }
    ll ans = 1e18;
    for (auto [k, p] : dp[N - 1][N - 1])
        chmin(ans, p.n);
    cout << ans + N * 2 - 2 << '\n';
}
