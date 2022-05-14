#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

struct Query {
    ll i, x;
};
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr ll N = 2e5 + 5;
ll BIT[N];
ll n, q;


void upd(ll idx, ll y) {
    for ( ; idx <= n; idx += idx&-idx )
        BIT[idx] += y;
}

//sum of first x items
ll query(ll x) {
    ll sum = 0;
    for ( ; x > 0; x -= x&-x )
        sum += BIT[x];

    return sum;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    while (cin >> n >> q) {
        vector<ll> a(n);
        ll sum = 0;
        for (auto& x: a) {
            cin >> x;
            sum += x;
        }

        for (ll qq = 0; qq < q; qq++) {
            ll t; cin >> t;
            if (t == 1) {
                ll i, x; cin >> i >> x;
                i--;
                sum += x - a[i];
                a[i] = x;

            } else {
                ll x; cin >> x;
                a = vector(n, x);
                sum = x * n;
            }

            cout << sum << endl;
        }

        // vector<ll> a(n+1);
        // for (ll i = 1; i <= n; i++) {
            // cin >> a[i];
            // upd(i, a[i]);
        // }

        // for (ll qq = 0; qq < q; qq++) {
            // ll t; cin >> t;
            // if (t == 1) {
                // ll i, x; cin >> i >> x;
                // upd(i, x);
            // } else {
                // ll x; cin >> x;
                // for (ll i = 1; i <= n; i++) upd(i, x);
            // }

            // cout << query(n) << endl;
        // }

    }
    
    return 0;
}

