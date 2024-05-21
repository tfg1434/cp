#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

const int max_n = 2e5;
vi divs[max_n+1];

void solve() {
    int n; cin >> n;    
    string s; cin >> s;
    for (auto len : divs[n]) {
        { 
            bool OK = true, used = false;
            for (int i = 0; i < n; i += len) {
                bool ok = true;
                for (int j = 0; j < len; j++) {
                    if (s[i+j] != s[j]) {
                        if (!used) {
                            used = true;
                        } else {
                            ok = false;
                            break;
                        }
                    }
                }

                if (!ok) {
                    OK = false;
                    break;
                }
            }

            if (OK) {
                cout << len << '\n';
                break;
            } 
        }
        { 
            bool OK = true, used = false;
            for (int i = n-1; i >= 0; i -= len) {
                bool ok = true;
                for (int j = 0; j < len; j++) {
                    if (s[i-j] != s[n-1-j]) {
                        if (!used) {
                            used = true;
                        } else {
                            ok = false;
                            break;
                        }
                    }
                }

                if (!ok) {
                    OK = false;
                    break;
                }
            }

            if (OK) {
                cout << len << '\n';
                break;
            } 
        }
    }
}

signed main() {
    for (int i = 1; i <= max_n; i++) {
        for (int j = i; j <= max_n; j += i) {
            divs[j].pb(i);
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
