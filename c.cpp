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
int N, M, L, Q, A[100], B[100], C[100], X;
map<int, bool> mp;
int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    cin >> M;
    for (int i = 0; i < M; ++i)
        cin >> B[i];
    cin >> L;
    for (int i = 0; i < L; ++i)
        cin >> C[i];

    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            for (int k = 0; k < L; ++k)
                mp[A[i] + B[j] + C[k]] = 1;

    cin >> Q;
    for (int _ = 0; _ < Q; ++_)
    {
        cin >> X;
        cout << (mp[X] ? "Yes\n" : "No\n");
    }
}
