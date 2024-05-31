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
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 

int n;
vi a;

void solve() {
    cin >> n;    
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vi where;
    for (int i = 0; i < n; i++) if (a[i] != -1) where.pb(i);
    if (!where.size()) {
        for (int i = 0; i < n; i++) cout << i%2+1 << " \n"[i==n-1];
        return;
    }

    for (int I = 0; I < where.size()-1; I++) {
        int i = where[I], j = i+1;
        while (j < n && a[j] == -1) j++;

        if (abs(bits(a[i])-bits(a[j]))%2 != (j-i)%2) {
            cout << "-1\n";
            return;
        }
        while (i+1 < j && bits(a[i]) > bits(a[j])) a[i+1] = a[i]/2, i++;
        while (j-1 > i && bits(a[i]) < bits(a[j])) a[j-1] = a[j]/2, j--;
        while (j-i > 1) {
            if (a[i] == 1) {
                a[i+1] = a[j-1] = 2;
            } else {
                a[i+1] = a[i]/2;
                a[j-1] = a[j]/2;
            }
            i++;
            j--;
        }
    }
    for (int i = where.back()+1; i < n; i++) a[i] = a[i-1] == 1 ? 2 : a[i-1]/2;
    for (int i = where.front()-1; i >= 0; i--) a[i] = a[i+1] == 1 ? 2 : a[i+1]/2;
    for (int i = 0; i < n-1; i++) {
        if (a[i] != a[i+1]/2 && a[i+1] != a[i]/2) {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}

