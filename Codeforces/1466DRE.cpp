#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(a) (ll)((a).size())
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<vector<ll>> adj(n+1, vector<ll>());
        vector<ll> w(n+1);
        ll sum = 0;
        for (ll i = 1; i <= n; i++) cin >> w[i], sum += w[i];
        for (ll i = 0; i < n-1; i++) {
            ll u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<ll> a;
        for (ll i = 1; i <= n; i++) {
            ll j = 2;
            while (len(adj[i]) >= j) {
                a.push_back(w[i]);
                j++;
            }
            // if (len(adj[i]) >= 2) {
                // a.push_back(w[i]);
            // }
        }
        sort(all(a), greater<ll>());
        // cout << a << endl;
        vector<ll> pre(n+1);
        partial_sum(all(a), pre.begin()+1);

        ll ans = sum;
        for (ll i = 0; i < n-1; i++) {
            cout << ans+pre[i] << ' ';
        }
        cout << endl;
    }    
    
    return 0;
}
