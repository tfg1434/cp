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

constexpr ll SZ = 1e5 + 5;
ll par[SZ], sze[SZ];
void makeSet(ll v) {
    par[v] = v;
    sze[v] = 1;
}
ll findSet(ll v) {
    if (v == par[v]) return v;
    return par[v] = findSet(par[v]);
}
void unionSets(ll a, ll b) {
    a = findSet(a);
    b = findSet(b);

    if (a != b) {
        if (sze[a] < sze[b]) swap(a, b);
        par[b] = a;
        sze[a] += sze[b];
    }
}

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<ll> a(n+1), b(n+1), d(n+1);
        for (ll i = 1; i <= n; i++) cin >> a[i];
        for (ll i = 1; i <= n; i++) cin >> b[i];
        for (ll i = 1; i <= n; i++) cin >> d[i];

        for (ll i = 1; i <= n; i++) {
            makeSet(i);
        }
        for (ll i = 1; i <= n; i++) {
            unionSets(a[i], b[i]);
            //corner case: a[i] == b[i]
            if (a[i] == b[i]) d[i] = a[i];
        }

        set<ll> st;
        for (ll i = 1; i <= n; i++) {
            st.insert(findSet(i));
        }
        //erase deez
        for (ll i = 1; i <= n; i++) {
            if (d[i] != 0) {
                st.erase(findSet(d[i]));
            }
        }

        cout << binpow(2, st.size()) << '\n';
    }    
    
    return 0;
}

