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
constexpr ll N = 5e4+5;
bool test = true;

struct Dsu {
    vector<ll> par, cycles;
    Dsu(ll n) : par(n), cycles(n) {
        iota(all(par), 0);
    }

    int find(int x) {
        return (par[x] == x) ? x : (par[x] = find(par[x]));
    }

    bool merge(int x, int y) {
        int res1 = find(x), res2 = find(y);
        if (res1 == res2) {
            cycles[res1]++;
        }

        if (res1 == res2)
            return false;
        par[res2] = res1;
        cycles[res1] += cycles[res2];
        return true;
    }
};

int main() {
  cin.tie(0)->ios::sync_with_stdio(0);

  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    Dsu uf(2*n+1);
    for (ll i = 0; i < n; i++) {
      ll p, q;
      cin >> p >> q;
      uf.merge(p, q);
    }
    
    bool ans = true;
    for (ll i = 1; ans && i <= 2*n; i++) {
        ans &= (uf.cycles[i] <= 1);
    }

    cout << (ans ? "possible" : "impossible") << endl;
  }

  return 0;
}
