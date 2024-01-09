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


ll getNearest(ll x, ll y, ll target) {
   if (target - x >= y - target)
      return y;
   else
      return x;
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n, m; cin >> n >> m;
        vector<ll> ks(n); for (auto&k:ks) cin >> k;

        auto getNearestElement = [&](ll target) -> ll {
            if (target <= ks[0])
              return ks[0];
            if (target >= ks[n - 1])
              return ks[n - 1];
            ll left = 0, right = n, mid = 0;
            while (left < right) {
              mid = (left + right) / 2;
              if (ks[mid] == target)
                 return ks[mid];
              if (target < ks[mid]) {
                 if (mid > 0 && target > ks[mid - 1])
                    return getNearest(ks[mid - 1], ks[mid], target);
                    right = mid;
              } else {
                 if (mid < n - 1 && target < ks[mid + 1])
                    return getNearest(ks[mid], ks[mid + 1], target);
                 left = mid + 1;
              }
            }
            return ks[mid];
        };

        for (ll i = 0; i < m; i++) {
            ll a, b, c; cin >> a >> b >> c;
            ll bb = getNearestElement(b);
            if ((bb-b)*(bb-b) - 4*a*c >= 0) {
                cout << "NO\n";
            } else {
                cout <<"YES\n";
                cout << bb << endl;
            }
        }
        cout << endl;
    } 
    
    return 0;
}
