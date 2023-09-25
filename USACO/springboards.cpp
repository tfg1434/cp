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
map<ll, ll> mp;
void ins(int y, int v) {
	auto it = prev(mp.upper_bound(y));
	if (it->s <= v) return;
	it ++;
	while (it != end(mp) && it->s > v) mp.erase(it++);
	mp[y] = v;
}

// Thinking
// It was good to go from 1d to 2d
// You need PU + RQ think of how to use a segment tree
// https://usaco.guide/adv/springboards?lang=cpp
//
// Point Updates (subtraction by f)
// Range queries (Looking in suffix that is at least f)
//
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    if (fopen("boards.in", "r")) {
        freopen("boards.in", "r", stdin);
        freopen("boards.out", "w", stdout);
    }
    
    ll n, p; cin >> n >> p;
    V<pair<pl, pl>> ev; 
    f0(i, p) {
        pl a, b;
        cin >> a.f >> a.s >> b.f >> b.s;
        ev.pb({ a, { i, -1 } });
        ev.pb({ b, { i, 1 } });
    }
    sort(all(ev));

    mp[0] = 0;
    vl ans(p);
    // auto ins = [&](ll a, ll b) -> void {
        // auto it = mp.lower_bound(a);
        // if (it != mp.end() && it->s >= b) return;
        // it = mp.insert(it, { a, b });
        // it->s = b;
        // while (it != mp.begin() && prev(it)->s <= b) mp.erase(prev(it));
    // };
    for (auto [p1, p2] : ev) {
        if (p2.s == 1) {
            ins(p1.s, ans[p2.f] - p1.f - p1.s);
        } else {
            ans[p2.f] = p1.f + p1.s + prev(mp.upper_bound(p1.s))->s;
        }
    }

    cout << mp.rbegin()->s+2*n << endl;
    
    return 0;
}
