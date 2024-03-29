#include <bits/stdc++.h>
using namespace std;
using pl = pair<long long, long long>;
using str = string;
using db = long double;
#define ll long long
using pd = pair<db, db>;

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpl = V<pl>;
using vpd = V<pd>;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define bk back()
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
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vl a(n+1), pro(n+1), pre(n+1);
        pro[0] = 1;
        vl nz;
        bool one = true;
        f1(i, n+1) {
            cin >> a[i];
            one &= a[i] == 1;
            pro[i] = min((ll)1e9, pro[i-1] * a[i]);
            pre[i] = pre[i-1] + a[i];
            if (a[i] != 1) nz.pb(i);
        }
        if (one) {
            cout << 1 << ' ' << 1 << endl;
            continue;
        }

        if (pro.bk > 1e6) {
            auto l = a.begin()+1; while (*l == 1) l++;
            auto r = a.end()-1; while (*r == 1) r--;
            cout << l-a.begin() << ' ' << r-a.begin() << endl;
        } else {
            ll best = 0, ansLo, ansHi;
            f0(i, nz.size()) rep(j, i, nz.size()-1) {
                ll lo = nz[i], hi = nz[j];
                ll res = pro[hi] / pro[lo-1];
                res += pre[lo-1];
                res += pre[n] - pre[hi];

                if (res > best) {
                    ansLo = lo, ansHi = hi;
                    best = res;
                }
            }
            cout << ansLo << ' ' << ansHi << endl;
        }
    } 
    
    return 0;
}
