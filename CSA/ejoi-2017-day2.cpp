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

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n,k; while (cin >> n >> k) {
        vector<ll> a(n);
        for (auto&x:a)cin >> x; 
        for (ll i = 0; i < k; i++) {
            ll p; cin >> p;
            vector<ll> freq(n+1);
            auto mx = max_element(a.begin(), a.begin()+p-1);
            ll score = *mx;
            ll b = -1;
            ll mxx = 0; //0 means nothing left
            for (ll j = 0; j < p; j++) {
                if (j == mx - a.begin()) continue;
                freq[a[j]]++;
                mxx = max(mxx, a[j]);
            }
            for (ll j = p; j < n; j++) {
                if (a[j] >= mxx) {
                    score += a[j] * b;
                    b *= -1;
                } else {
                    score += mxx * b;
                    b *= -1;
                    if (--freq[mxx] == 0) {
                        while (mxx > 0 && freq[--mxx] == 0) {}
                    }
                }
            }
            while (freq[mxx] > 0) {
                score += mxx * b;
                b *= -1;
                if (--freq[mxx] == 0) {
                    while (mxx > 0 && freq[--mxx] == 0) {}
                }
            }

            cout << score << endl;
        }
    } 
    
    return 0;
}
