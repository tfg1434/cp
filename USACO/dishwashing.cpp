#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define vi vector<ll>
#define vb vector<bool>
#define f0(i,a) for(ll i=0;i<(a);i++)
#define f1(i,a) for(ll i=1;i<(a);i++)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
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
    freopen("dishes.in", "r", stdin);
    freopen("dishes.out", "w", stdout);
    
    ll n; while (cin >> n) {
        vi a(n); for (auto&x : a) cin >> x;
        auto check = [&](ll k) -> bool {
            deque<vector<ll>> stacks;
            deque<ll> rem(a.begin(), a.begin()+k);
            sort(all(rem)); 
            f0(i, k) {
                vi temp {a[i]}; 
                auto iter = upper_bound(all(stacks), temp, [&](vi sa, vi sb) -> bool {
                    return sa.back() < sb.back();
                });
                ll pos = iter - stacks.begin();
                if (iter == stacks.end()) {
                    stacks.pb({ a[i] });
                } else {
                    stacks[pos].pb(a[i]);
                    if (pos > 0 && stacks[pos-1].front() > a[i]) return false;
                }

                while (!stacks.empty() && stacks.front().back() == rem.front()) {
                    stacks.front().pop_back();
                    rem.pop_front();
                    if (stacks.front().empty()) stacks.pop_front();
                }
            }
            return rem.empty();
        };

        ll p = 0;
        for (ll b = n; b > 0; b /= 2) {
            while (p+b <= n && check(p+b)) p += b;
        }

        cout << p << endl;
    }
    
    return 0;
}
