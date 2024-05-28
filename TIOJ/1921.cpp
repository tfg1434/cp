// gave up writing it because i don't understand what's happening
// i am very afraid of becoming a grey coder who can implement treap
// better than a red coder :cry:

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 2e18;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

int f(const array<int, 2>& line, int x) { return line[0]*x + line[1]; }

const int max_d = 1e9+1;
struct node {
    array<int, 2> line;
    int l, r;
    node() {
        l = r = -1;
        line = {0, (int)-1e9-1};
    }
} t[3'000'000];
int tree_sz = 1;
void extend(int v) {
    if (t[v].l == -1) {
        t[v].l = tree_sz++;
        t[v].r = tree_sz++;
        t[t[v].l] = node();
        t[t[v].r] = node();
    }
}
void add_line(int v, int l, int r, array<int, 2> nl) {
    int m = (l+r)/2;
    bool lef = f(nl, l) > f(t[v].line, l);
    bool mid = f(nl, m) > f(t[v].line, m);
    if (mid) swap(t[v].line, nl);
    if (l == r-1) return;
    extend(v);
    if (lef != mid) add_line(t[v].l, l, m, nl);
    else add_line(t[v].r, m, r, nl);
}
int point_max(int v, int l, int r, int i) {
    int cand = f(t[v].line, i);
    if (l == r-1) return cand;
    int m = (l+r)/2;
    extend(v);
    if (i < m) return max(cand, point_max(t[v].l, l, m, i));
    return max(cand, point_max(t[v].r, m, r, i));
}
void add_line(array<int, 2> nl) { add_line(0, 0, max_d, nl); }
int point_max(int i) { return point_max(0, 0, max_d, i); }

int n, c, d;
struct ATM {
    int d, r, p, g;
    bool operator <(const ATM& o) const {
        return d < o.d;
    }
    friend ostream& operator<<(ostream& out, const ATM& o) {
        out << o.d << ' ' << o.r << ' ' << o.p << ' ' << o.g;
        return out;
    }
    friend istream& operator>>(istream& in, ATM& o) {
        in >> o.d >> o.p >> o.r >> o.g;
        return in;
    }
};
V<ATM> atms;

void solve() {
    cin >> n >> c >> d;    

    atms.resize(n);
    for (int i = 0; i < n; i++) cin >> atms[i];
    sort(all(atms));
    add_line({0, c});
    ps(point_max(0));
    vi a(n), b(n), dp(n);
    t[0] = node();
    for (int i = 0; i < n; i++) {
        dp[i] = point_max(atms[i].d) - atms[i].p;
        a[i] = atms[i].g;
        b[i] = dp[i]+atms[i].r-atms[i].g*(atms[i].d+1);
        add_line({a[i], b[i]});
    }

    cout << point_max(d+1) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
