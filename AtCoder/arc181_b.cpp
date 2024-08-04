// a dumb approach that needs lazy segtree and hashing
// which i couldn't write during the contest

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

vi par;
int find(int u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
}

void range_set(int v=0, int l=0, int r=T, int ) {

}

void solve() {
    string s, ta, tb; cin >> s >> ta >> tb;
    int S = s.size(), TA = ta.size(), TB = tb.size();
    int x = count(all(ta), '0'), y = TA-x;
    int X = count(all(tb), '0'), Y = TB-X;
    if (y == Y) {
        if (x == X) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return;
    }
    int T = S*(x-X);
    if (T%(Y-y)) {
        cout << "No\n";
        return;
    }
    T /= (Y-y);
    string t(T, '.');

    auto range_set = [&](auto&& rec, int u=0, int l=0, int r=t, int Lt, int Rt, int Ls, int Rs) {
        if (Lt <= l && r <= Rt) {
            if (t[v] != hash_s(Ls+l-Lt, Ls+l-Lt + , ))
            int off = l-Ls;

        }
    };
     
    bool possible = true;
    auto assign = [&](int i, char c) {
        ps(i, '=', c);
        if (t[i] != '.' && t[i] != c) {
            possible = false;
            return;
        }
        t[i] = c;
    };

    auto copy_info = [&](string src, string dest) {
        int SRC = src.size(), DEST = dest.size();
        int src_pos = 0, dest_pos = 0, dest_ind = 0;
        for (char c : src) {
            if (c == '0') {
                while (dest_ind < DEST && (dest[dest_ind] == '0' || dest_pos+T <= src_pos)) {
                    dest_pos += dest[dest_ind] == '0' ? S : T;
                    dest_ind++;
                }
                if (dest_pos == DEST) break;

                if (dest_pos <= src_pos) {
                    int start_t_pos = src_pos-dest_pos;
                    range_set(start_t_pos, 0, min(T-start_t_pos, S));

                    if (dest_pos+T < src_pos+S) {
                        dest_ind++;
                        while (dest_ind < DEST && dest[dest_ind] == '0') {
                            dest_pos += dest[dest_ind] == '0' ? S : T;
                            dest_ind++;
                        }
                        if (dest_ind == DEST) break;
                    }
                }

                ps(dest_ind, dest_pos);
                if (dest_pos < src_pos+S) {
                    while (true) {
                        int start_s_pos = dest_pos-src_pos;
                        range_set(0, start_s_pos, min(T, S-start_s_pos));

                        if (dest_pos+T < src_pos+S) {
                            dest_ind++;
                            while (dest_ind < DEST && dest[dest_ind] == '0') {
                                dest_pos += dest[dest_ind] == '0' ? S : T;
                                dest_ind++;
                            }
                            if (dest_ind == DEST) break;
                        } else {
                            break;
                        }
                    }
                    if (dest_ind == DEST) break;
                }
            }
            src_pos += c == '0' ? S : T;
        }
    };
    copy_info(ta, tb);
    copy_info(tb, ta);

    cout << (possible ? "Yes" : "No") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
