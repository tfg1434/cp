#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define f first
#define s second
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#ifdef I_AM_NOOB
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);
#else
#define gg(...) 777771449
#endif

constexpr ll INFF = 1e18;
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;

struct Node {
    string type;
    bool leaf = true;
};

string tp1(string t) {
    if (t == ">") return ">+";
    return t;
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n; while (cin >> n) {
        vector<vector<ll>> adj(n+1);
        vector<Node> info(n+1);
        for (ll i = 0; i < n-1; i++) {
            ll u, p; cin >> u >> p;
            adj[p].pb(u);
            string ti; cin >> ti;
            if (ti == "Tong") ti = "=";
            if (ti == "Duan") ti = "<";
            if (ti == "Chang") ti = ">";
            info[u].type = ti;
            info[p].leaf = false;
        }

        // for (ll i = 1; i <= n; i++) {
            // if (adj[i].size() == 0) {
                // info[i].twig = false;
                // continue;
            // }
            // for (auto v : adj[i]) {
                // if (!info[v].leaf) {
                    // info[i].twig = false;
                    // break;
                // }
            // }
        // }
        // for (ll i = 1; i <= n; i++) {
            // if (info[i].twig) info[i].leaf = false;
        // } 

        bool ok = true;
        vector<pll> ans;
        vector<ll> o(n+1); for (ll i = 1; i <= n; i++) o[i] = i;
        y_combinator([&](auto rec, ll u) -> void {
            for (auto v : adj[u]) {
                rec(v);
            }
            if (!ok) return;

            bool isTwig = true;
            if (!adj[u].size()) isTwig = false;
            for (auto v : adj[u]) {
                if (!info[v].leaf) isTwig = false;
            }
            if (isTwig) {
                gg(ans, u, info[u].leaf);
                vector<string> t;
                vector<ll> vs;
                for (auto v : adj[u]) {
                    if (info[v].type != "-") {
                        t.push_back(info[v].type);
                        vs.pb(v);
                    }
                }
                gg(t);
                sort(all(t));
                if (t.size() > 2) {
                    ok = false;
                    return;
                }

                info[u].leaf = true;
                adj[u].clear();
                if (t.size() == 1) {
                    if (t[0] == ">" && info[u].type == "<") {
                        info[u].type = ">+";
                        ans.eb(u, o[vs[0]]);
                    } else if (info[u].type == "-" && (t[0] == ">" || t[0] == ">+")) {
                        info[u].type = ">+";
                        o[u] = o[vs[0]];
                    } else {
                        ok = false;
                        return;
                    }
                } else if (t.size() == 2) {
                    if (t[0] == "<" && t[1] == ">+") {
                        ans.eb(o[vs[0]], o[vs[1]]);
                    } else if (t[0] == t[1] && t[1] == "=" ) {
                        ans.eb(o[vs[0]], o[vs[1]]);
                    } else {
                        ok = false;
                        return;
                    }
                }    
            }
        })(1);

        if (!ok) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for (auto [u,v]: ans) {
                cout << u << ' ' << v << endl;
            }
        }
    }
    
    return 0;
}
