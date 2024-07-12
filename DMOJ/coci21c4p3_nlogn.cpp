// i spent wayyyy too long debugging this
// omg it doesn't WA? no way :O to TLE :((

#include <bits/stdc++.h>
using namespace std;
#define int int64_t

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

int gauss(int n) { return n*(n+1)/2; }

const int N = 2e5, MAX = 4e5+1;

struct Info {
    int sum, wsum, cnt, buf;
    Info() : sum(0), wsum(0), cnt(0), buf(0) {}
    Info(int sum, int wsum, int cnt) : sum(sum), wsum(wsum), cnt(cnt), buf(0) {}
    friend ostream& operator<<(ostream& out, const Info& rhs) {
        return out << rhs.sum << ' ' << rhs.wsum << ' ' << rhs.cnt << ' ' << rhs.buf;
    }
};
V<Info> t;
V<bool> touched;
Info merge(const Info& a, const Info& b) {
    return Info(a.sum+b.sum, a.wsum+a.sum*b.cnt + b.wsum, a.cnt+b.cnt);
}
void pull(int v) {
    t[v] = merge(t[2*v+1], t[2*v+2]);
}
void push(int v) {
    touched[v] = true;
    if (t[v].buf) {
        if (2*v+2 < t.size()) {
            touched[2*v+1] = touched[2*v+2] = true;
            t[2*v+1].buf += t[v].buf;
            t[2*v+2].buf += t[v].buf;
        }
        t[v].sum += t[v].cnt*t[v].buf;
        t[v].wsum += gauss(t[v].cnt)*t[v].buf;
        t[v].buf = 0;
    }
}
void range_add(int L, int R, int v=0, int l=0, int r=MAX) {
    push(v);
    if (r <= L || R <= l) return;
    if (L <= l && r <= R) {
        t[v].buf = 1;
        push(v);
        return;
    }
    int m = (l+r)/2;
    range_add(L, R, 2*v+1, l, m);
    range_add(L, R, 2*v+2, m, r);
    pull(v);
}
Info range_query(int L, int R, int v=0, int l=0, int r=MAX) {
    push(v);
    if (r <= L || R <= l) return Info();
    if (L <= l && r <= R) {
        return t[v];
    }
    int m = (l+r)/2;
    return merge(range_query(L, R, 2*v+1, l, m), range_query(L, R, 2*v+2, m, r));
}
void build(int v=0, int l=0, int r=MAX) {
    if (l == r-1) {
        t[v] = Info(0, 0, 1);
        return;
    }
    int m = (l+r)/2;
    build(2*v+1, l, m);
    build(2*v+2, m, r);
    pull(v);
}
void init_tree() {
    int siz = 1;
    while (siz < 2*MAX) siz *= 2;
    t.resize(siz);
    touched.resize(siz);
    build();
}
void reset(int v) {
    touched[v] = false;
    t[v].sum = t[v].wsum = t[v].buf = 0;
    if (2*v+2 < t.size()) {
        if (touched[2*v+1]) reset(2*v+1);
        if (touched[2*v+2]) reset(2*v+2);
    }
}

void solve() {
    init_tree();

    int n; cin >> n;    
    vi a(n), values;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        values.pb(a[i]);
    }
    sort(all(values));
    values.erase(unique(all(values)), values.end());
    int mx = values.size();
    vi freq(mx);
    for (int& x : a) {
        x = lwb(values, x);
        freq[x]++;
    }

    int ans = 0;
    for (int v = 0; v < mx; v++) {
        vi data;
        for (int i = 0; i < n; i++) {
            if (a[i] == v) {
                if (!data.size() || data.back() < 0) {
                    data.pb(1);
                } else {
                    data.back()++;
                }
            } else {
                if (!data.size() || data.back() > 0) {
                    data.pb(-1);
                } else {
                    data.back()--;
                }
            }
        }
        // ps(data);
        int s = n;
        range_add(s, s+1);

        for (int op : data) {
            s += op;
            if (op > 0){
                ans += op*range_query(0, s-op).sum;
                ans += range_query(s-op, s).wsum;
                ans += op*(op-1)/2;
                range_add(s-op+1, s+1);

            } else {
                // ps("range sum", 0-n, s-n);
                ans += -op*range_query(0, s-1).sum;
                // ps("range wsum", s-1-n, s-op-1-n);
                ans += range_query(s-1, s-op-1).wsum;
                range_add(s, s-op); 
            }
            // ps(op, ans);
            // for (int j = 0; j < 2*n+1; j++) ps("seen", j-n, range_query(j, j+1).sum);
        }
        // ps(ans);

        reset(0);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
