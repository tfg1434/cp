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
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr ll N = 1e5+5;

ll par[N], sz[N];
ll find(ll v) {
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}
void unite(ll a, ll b) {
    a = find(a), b = find(b);
    if (a != b) {
        if (sz[a] > sz[b]) swap(a,b);
        par[b] = a;
        sz[a] += sz[b];
    }
}


int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        string a, b; cin >> a >> b;

        if (a == b) {
            cout << 0 << endl;
            continue;
        }

        ll n = a.size();
        map<char, vector<ll>> mp;
        set<char> as; //set of a's of all to be changed
        map<char, char> chk;
        bool ok = true;

        for (ll i = 0; i < n; i++) {
            if (chk.count(a[i]) && chk[a[i]] != b[i]) {
                ok = false;
                break;
            }
            chk[a[i]] = b[i];

            if (a[i] == b[i]) continue;

            mp[b[i]].push_back(i);
            as.insert(a[i]);
        }

        if (!ok) {
            cout << -1 << endl;
            continue;
        }

        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;

            if (!as.count(b[i])) {
                //i is unique
                set<ll> cnt;
                cnt.insert(a[i]);
                for (ll j = 0; j < mp[b[i]].size(); j++) {
                    ll idx = mp[b[i]][j];
                    if (idx == i) continue;

                    as.erase(a[idx]);
                    cnt.insert(a[idx]);
                    a[idx] = b[i];
                }
                as.erase(a[i]);
                a[i] = b[i];
                ans += cnt.size();
            }
        }

        set<ll> bs;
        for (ll i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            bs.insert(b[i]);
        }
        for (ll i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;

            if (!bs.count(a[i])) {
                //i is round
                set<ll> cnt;
                cnt.insert(a[i]);
                for (ll j = 0; j < mp[b[i]].size(); j++) {
                    ll idx = mp[b[i]][j];
                    if (idx == i) continue;

                    as.erase(a[idx]);
                    bs.erase(b[idx]);
                    cnt.insert(a[idx]);
                    a[idx] = b[i];
                }
                as.erase(a[i]);
                bs.erase(b[i]);
                a[i] = b[i];
                ans += cnt.size();
            }
        }
        set<pll> deleted;
        for (ll i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            if (deleted.count({ a[i], b[i] })) continue;
            
            if (!as.count(b[i])) {
                ans++;
                as.erase(a[i]);
                deleted.insert({ a[i], b[i] });
                a[i] = b[i];
            }
        }

        gg(a, b);

        set<ll> st;
        for (ll i = 'A'; i <= 'Z'; i++) {
            par[i] = i;
            sz[i] = 1;
        }
        set<ll> rep;
        for (ll i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            unite(a[i], b[i]);
        }
        for (ll i = 0; i < n; i++) {
            if (a[i] == b[i]) continue;
            rep.insert(find(a[i]));
        }
        gg(sz[65]);
        gg(rep);

        for (auto iter = rep.begin(); iter != rep.end(); iter++) {
            ans += sz[*iter] + 1;
        }

        cout << ans << endl;
    }
    
    return 0;
}
