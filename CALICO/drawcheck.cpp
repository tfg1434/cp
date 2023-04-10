#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
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
ll x, vis[505];

void draw() {
    cout << "draw" << endl;
    // cout << x << endl;
    for (ll i = 0; i < 17; i++) {
        ll y; cin >> y;
        if (!vis[y]) {
            vis[y]++;
            x++;
        }
    }
}

bool check(ll card) {
    x++;
    vis[card]++;
    cout << "check " << card << endl;
    string s; cin >> s;
    return (s == "ABSENT");
}

int main() {
    // cin.tie(0) -> ios::sync_with_stdio(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    
    int T; cin >> T; while (T--) {
        x = 0;
        memset(vis, 0, sizeof vis);
        while (x < 440) {
            draw();
        }

        vector<ll> a;
        for (ll i = 1; i <= 500; i++) {
            if (!vis[i]) {
                a.pb(i);
            }
        }

        shuffle(all(a), rng);
        for (auto card : a) {
            if (check(card)) break;
        }
    } 
    string _;
    getline(cin, _);

    string s; cin >> s;
    // if (s == "WRONG_ANSWER") exit(3);
    
    return 0;
}
