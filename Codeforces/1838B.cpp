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
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        ll idxN, idx1, idx2;
        vector<ll> p(n+1); 
        for (ll i = 1; i <= n; i++) {
            cin >> p[i]; 
            if (p[i] == n) idxN = i;
            if (p[i] == 1) idx1 = i;
            if (p[i] == 2) idx2 = i;
        }
        bool oppSides = (idx2 < idx1 && idxN > idx1) || (idxN < idx1 && idx2 > idx1);

        if (idx1 == 1) {
            cout << 2 << ' ' << idxN << endl;
        } else if (idx1 == n) {
            cout << n-1 << ' ' << idxN << endl;
        } else {
            if ((idx2 == idx1-1 || idx2 == idx1+1) && oppSides) {
                cout << idx1 << ' ' << idxN << endl;
                continue;
            }

            if (idx2 < idx1) {
                cout << idxN << ' ' << idx1-1 << endl;
            } else if (idx2 > idx1) {
                cout << idxN << ' ' << idx1+1 << endl;
            }
        }

        // if both on left, swap
        //if both on right, swap
        //if 

    } 
    
    return 0;
}
