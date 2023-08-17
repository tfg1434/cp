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

// Thinking
// Didn't think of fixing the Js until very late
// Didn't think of three seperate arrays representation

// Implementation
// deq supports fast front/back inserts AND fast random access
// I had to go from stupid implementation fixing in middle (actually implemented it)
// to less stupid w/ deque seperated J, O, I to finally working one with fixing
// first Js
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n, k; while (cin >> n >> k) {
        string s; cin >> s;
        deque<ll> J, O, I;
        f0(i, n) {
            if (s[i] == 'J') J.pb(i);
            if (s[i] == 'O') O.pb(i);
            if (s[i] == 'I') I.pb(i);
        }
        ll ans = INFF;
        for (ll i = k-1; i < J.size(); i++) {
            while (!O.empty() && O.front() < J[i]) O.pop_front();
            if (O.size() < k) continue;
            while (!I.empty() && I.front() < O[k-1]) I.pop_front();
            if (I.size() < k) continue;
            ans = min(ans, I[k-1] - J[i-k+1] + 1 - 3*k);
        }

        cout << (ans == INFF ? -1 : ans) << endl;
    } 
    
    return 0;
}
