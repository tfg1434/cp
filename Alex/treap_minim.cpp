#include <bits/stdc++.h>
using namespace std;

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

struct Item {
    int x, y, l, r, p;
    Item() {}
    Item(int x, int y) : x(x), y(y), l(-1), r(-1), p(-1) {}
} t[50'000];
int cur_node;

void split(int v, int x, int& l, int& r) {
    if (v == -1) {
        l = r = -1;
        return;
    }
    if (t[v].x < x) {
        split(t[v].r, x, t[v].r, r);
        l = v;
    } else {
        split(t[v].l, x, l, t[v].l);
        r = v;
    }
}
void merge(int& v, int l, int r) {
    if (l == -1) return (void)(v = r);
    if (r == -1) return (void)(v = l);
    if (t[l].y < t[r].y) {
        merge(t[l].r, t[l].r, r);
        v = l;
    } else {
        merge(t[r].l, l, t[r].l);
        v = r;
    }
}

int n;

void connect(bool forward) {
    vi s;
    for (int i = forward ? 0 : n-1; forward ? i < n : i >= 0; forward ? i++ : i--) {
        while (s.size() && t[i].y < t[s.back()].y) {
            s.pop_back();
        }
        if (s.size() && (t[i].p == -1 || t[s.back()].y > t[t[i].p].y)) {
            t[i].p = s.back();
        }
        s.pb(i);
    }
}

void solve() {
    cin >> n;    
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        t[i] = Item(x, y);
    }
    connect(true);
    connect(false);
    int no_par = 0;
    for (int i = 0; i < n; i++) {
        if (t[i].p != -1) {
            if (t[t[i].p].x > t[i].x) {
                t[t[i].p].l = i;
            } else {
                t[t[i].p].r = i;
            }
        } else {
            no_par++;
        }
    }
    if (no_par > 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        int fa = t[i].p;
        int lc = t[i].l;
        int rc = t[i].r;
        cout << fa+1 << ' ' << lc+1 << ' ' << rc+1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
