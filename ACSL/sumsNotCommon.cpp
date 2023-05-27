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
    
    string a, b, c; while (getline(cin, a), getline(cin, b), getline(cin, c)) {
        auto process = [&](set<ll>& st, string s) -> void {
            stringstream ss(s);
            string o; while (ss >> o) {
                stringstream oo(o);
                char w,z,_; 
                ll x, y;
                oo >> w;
                oo >> x;
                oo >> _;
                oo >> y;
                oo >> z;
                for (ll i = x+1; i <= y-1; i++) {
                    st.insert(i);
                }
                if (w == '[') st.insert(x);
                if (z == ']') st.insert(y);
            }
        };

        vector<set<ll>> me(3);
        process(me[0], a); 
        process(me[1], b); 
        if (c != "null") process(me[2], c); 
        gg(me);

        ll ans1 = 0, ans2 = 0;
        for (ll i = -99; i <= 99; i++) {
            ll cnt = 0;
            cnt += me[0].count(i);
            cnt += me[1].count(i);
            if (c != "null") cnt += me[2].count(i);
            if (cnt == 1) gg(i);

            if (cnt == 1) ans1 += i;
            if (cnt == 2) ans2 += i;
        }

        if (c != "null") {
            cout << ans1 << ' ' << ans2 << endl;
        } else {
            cout << ans1 << endl;
        }
    } 
    
    return 0;
}
