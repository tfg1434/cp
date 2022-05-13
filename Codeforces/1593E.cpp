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

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
// constexpr ll N = 4e5 + 5;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n, k; cin >> n >> k;
        vector<vector<ll>> adj(n+1, vector<ll>());
        vector<ll> deg(n+1, 0);
        vector<ll> dist(n+1, 0);

        for (ll i = 0; i < n-1; i++) {
            ll u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        if (n == 0) {
            cout << 0 << endl;
            continue;
        }

        if (n == 1) {
            cout << (k == 0 ? 1 : 0) << endl; 
            continue;
        }

        auto bfs = [&]() {
            queue<int> q;
            for (ll i = 1; i <= n; i++) {
                deg[i] = adj[i].size();
                if (deg[i] == 1) {
                    q.push(i);
                    dist[i] = 1;
                }
            }

            while (!q.empty()) {
                ll u = q.front();
                q.pop();

                for (auto v : adj[u]) {
                    deg[v]--;
                    if (deg[v] == 1) {
                        q.push(v);
                        dist[v] = dist[u]+1;
                    }
                }
            }
        };

        bfs();
        ll ans = 0;
        for (ll i = 1; i <= n; i++) {
            if (dist[i] > k) ans++;
        }

        cout << ans << endl;
    }    
    
    return 0;
}

