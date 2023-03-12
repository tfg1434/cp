#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(a) (ll)((a).size())
#define IN(A, B, C) assert(B <= A && A <= C)
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
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);


constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr ll N = 1e5+5;
struct BIT {
    int a[N],t[N];
    int lowbit(int x){return x&(-x);}
    void cg(int x,int c){while(x<N)t[x]+=c,x+=lowbit(x);}
    int ask(int x){int r=0;while(x)r+=t[x],x-=lowbit(x);return r;}
    int ask(int l,int r){return ask(r)-ask(l-1);}
    void upd(int x){if(!a[x])cg(x,1);a[x]++;}
    void del(int x){if(a[x]==1)cg(x,-1);a[x]--;}
};
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    void add(int idx, int val) {
    for (++idx; idx < n; idx += idx & -idx)
        bit[idx] += val;
    }

    void range_add(int l, int r, int val) {
        add(l, val);
        add(r + 1, -val);
    }

    int point_query(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }
};

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<ll> a(n+1);
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
        }
        FenwickTree f(N);

        for (ll i = 1; i <= n; i++) {
            f.range_add(i, min(n,a[i]+i-1), 1);
            // gg(min(n,a[i]+i-1));
        }

        for (ll i = 1; i <= n; i++) {
            cout << f.point_query(i) << ' ';
        }
        cout << endl;
    }

    
    return 0;
}
