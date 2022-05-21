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
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll v; cin >> v;
    vector<ll> a(v);
    for (auto& x : a) cin >> x;
    ll g; cin >> g;
    vector<vector<ll>> b(g, vector<ll>(v));
    for (auto& x : b) {
        for (auto& y : x) cin >> y;
    }

    ll cnt = INFF;
    vector<ll> ans;
    for (ll mask = 0; mask < (1 << g); mask++) {

        vector<ll> curr(v, 0);
        for (ll j = 0; j < g; j++) {
            if (mask & (1 << j)) {
                for (ll k = 0; k < v; k++) {
                    curr[k] += b[j][k];
                }
            }
        }

        bool ok = true;
        for (ll i = 0; i < v; i++) {
            if (curr[i] < a[i]) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;


        if (__builtin_popcount(mask) < cnt) {
            ans.clear();
            cnt = __builtin_popcount(mask);
            for (ll i = 0; i < g; i++) {
                if (mask & (1 << i)) ans.push_back(i + 1);
            }
        }
    }

    cout << cnt << ' ';
    for (auto& x : ans) cout << x << ' ';

    //solves if you can reuse the same mixture
    // map<ll, pair<ll, vector<ll>>> mp;
    // map<ll, ll> mp2;
    // for (ll mask = 0; mask < (1 << v); mask++) {
        // pair<ll, vector<ll>> best(0, vector<ll>());

        // ll idx;
        // for (ll i = 0; i < g; i++) {
            // ll sum = 0;
            // vector<ll> items(v);
            // for (ll j = 0; j < v; j++) {
                // if (mask & (1 << i)) {
                    // sum += b[i][j];
                // }
                // items[j] = (mask & (1 << j)) ? b[i][j] : 0;
            // }

            // if (sum > best.first) {
                // best = {sum, items};
                // idx = i+1;
            // }
        // }
        
        // mp[mask] = best;
        // mp2[mask] = idx;
    // }

    // vector<ll> sum(v, 0);

    // auto done = [&]() {
        // for (ll i = 0; i < v; i++) {
            // if (sum[i] < a[i]) {
                // return false;
            // }
        // }
        // return true;
    // };

    // ll cnt = 0;
    // vector<ll> ans;
    // while (!done()) {
        // ll mask = 0;
        // for (ll i = 0; i < v; i++) {
            // if (sum[i] < a[i]) {
                // mask |= (1 << i);
            // }
        // }

        // auto& best = mp[mask];
        // auto idx = mp2[mask];
        // for (ll i = 0; i < v; i++) {
            // if (sum[i] < a[i]) {
                // sum[i] += best.second[i];
            // }
        // }
        // cnt++;
        // ans.push_back(idx);
    // }

    // cout << cnt << ' ';
    // for (auto& x : ans) {
        // cout << x << ' ';
    // }
    // cout << '\n';
    
    return 0;
}

