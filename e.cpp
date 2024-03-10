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
int N, A[200000], Q, t, x, y;
map<int, int> p, c;

void reset(const int x)
{
    c[x] = 0;
    p[x] = 0;
}
void link(const int x, const int y)
{
    c[x] = y;
    p[y] = x;
}

void q1(const int x, const int y)
{
    const int z = c[x];
    link(x, y);
    link(y, z);
}
void q2(const int x)
{
    const int y = p[x];
    const int z = c[x];
    reset(x);
    link(y, z);
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> A[i];
    c[0] = A[0];
    p[A[0]] = 0;
    for (int i = 0; i < N - 1; ++i)
    {
        c[A[i]] = A[i + 1];
        p[A[i + 1]] = A[i];
    }

    cin >> Q;
    for (int _ = 0; _ < Q; ++_)
    {
        cin >> t;
        switch (t)
        {
        case 1:
            cin >> x >> y;
            q1(x, y);
            break;
        case 2:
            cin >> x;
            q2(x);
            break;
        }
    }
    vector<int> v;
    int x = c[0];
    while (x != 0)
    {
        v.push_back(x);
        x = c[x];
    }
    const int K = int(v.size());
    for (int i = 0; i < K; ++i)
        cout << v[i] << (i < K - 1 ? '\t' : '\n');
}
