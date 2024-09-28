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

int cursor_pos;

bool is_less(int i, int j) {
    cout << "? " << i+1 << ' ' << j+1 << endl;
    int res; cin >> res;
    return res == 1;
}

void add(int i, int j) {
    cout << "+ " << i+1 << ' ' << j+1 << endl;
}

void solve() {
    int n; cin >> n;
    vi p;
    cursor_pos = n;

    for (int i = 0; i < n; i++) {
        if (!i || !is_less(i, p[i-1])) {
            p.pb(i);
            continue;
        }

        // invariant: x[p][lo] <= x[i] < x[p[hi]] 
        int lo = -1, hi = i-1; 
        while (hi-lo > 1) {
            int pos = (lo+hi)/2;
            is_less(i, p[pos]) ? hi = pos : lo = pos;
        }

        p.insert(p.begin()+hi, i);
    }

    while (n > 0) {
        add(p[0], p[n-1]);
        p.erase(p.begin());
        p.pop_back();
        n -= 2;

        if (n > 0) {
            if (!is_less(cursor_pos, p[n-1])) {
                p.pb(cursor_pos);
                n++;
            } else {
                int lo = -1, hi = n-1;
                while (hi-lo > 1) {
                    int pos = (lo+hi)/2;
                    is_less(cursor_pos, p[pos]) ? hi = pos : lo = pos;
                }
                p.insert(p.begin()+hi, cursor_pos);
            }

            cursor_pos++;

        } else {
            cout << "!" << endl;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
