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
string T;
int N, A[100];
string S[100][10];

int dp[101][101];

int main()
{
    cin >> T >> N;
    fill(dp[0], dp[N + 1], 1e9);
    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
        for (int j = 0; j < A[i]; ++j)
            cin >> S[i][j];
    }

    dp[0][0] = 0;
    for (int i = 0; i < N; ++i)
        for (int k = 0; k < T.size() + 1; ++k)
        {
            chmin(dp[i + 1][k], dp[i][k]);
            for (int j = 0; j < A[i]; ++j)
                if (T.substr(k, S[i][j].size()) == S[i][j])
                    chmin(dp[i + 1][k + S[i][j].size()], dp[i][k] + 1);
        }

    cout << (dp[N][T.size()] < 1e9 ? dp[N][T.size()] : -1) << '\n';
}
