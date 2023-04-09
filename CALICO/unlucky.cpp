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
const int K = 10;
ll n, d;

struct V {
    ll next[K];
    bool leaf = false;

    V() {
        fill(begin(next), end(next), -1);
    }
};

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        cin >> n >> d;
        vector<string> l(n); for (auto& x : l) cin >> x;
        vector<V> trie(1);
        for (auto s : l) {
            ll v = 0;
            for (char ch : s) {
                ll c = ch - '0';
                if (trie[v].next[c] == -1) {
                    trie[v].next[c] = trie.size();
                    trie.emplace_back();
                    // trie[trie.size()-1].par = v;
                }
                v = trie[v].next[c];
            }
            trie[v].leaf = true;
            // trie[trie[v].par].twig = true;
        }

        vector<string> dp(d+1);
        dp[0] = "";
        vector<ll> v;
        v.pb(0);
        for (ll i = 1; i <= d; i++) {
            // gg(v);
            ll ban = 0;
            for (auto node : v) {
                // if (trie[node].twig == false) continue;
                for (ll k = 0; k < K; k++) {
                    if (trie[node].next[k] != -1 && trie[trie[node].next[k]].leaf) {
                        ban |= (1 << k);
                    }
                }
            }
            // gg(bitset<10>(ban));
            assert((ban & 3) == 0);

            ll j;
            for (j = K-1; j >= 0; j--) {
                if ((ban & (1 << j)) == 0) {
                    dp[i] = dp[i-1] + (char)(j+'0');
                    break;
                }
            }

            vector<ll> b;
            for (auto node : v) {
                if (trie[node].next[j] == -1) {
                    continue;
                }
                if (!trie[trie[node].next[j]].leaf) {
                    b.pb(trie[node].next[j]);
                    // gg("yo");
                }
            }
            b.pb(0);
            v = b;
        }

        cout << dp[d] << endl;
    } 
    
    return 0;
}
