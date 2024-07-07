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

#include <bits/stdc++.h>

using i64 = long long;

int parity(const std::vector<int> &a) {
    const int n = a.size();
    std::vector<bool> vis(n);
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (vis[i]) {
            continue;
        }
        for (int j = i; !vis[j]; j = a[j]) {
            vis[j] = true;
        }
        p ^= 1;
    }
    return p;
}

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
        b[i]--;
    }
    auto va = a, vb = b;
    std::sort(va.begin(), va.end());
    std::sort(vb.begin(), vb.end());
    if (va != vb) {
        std::cout << "NO\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        a[i] = std::lower_bound(va.begin(), va.end(), a[i]) - va.begin();
    }
    for (int i = 0; i < n; i++) {
        b[i] = std::lower_bound(vb.begin(), vb.end(), b[i]) - vb.begin();
    }
    if (parity(a) != parity(b)) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
    }
}

// const int MAX = 2e5;
// int fa[MAX+1]

// void solve() {
    // int n; cin >> n;
    // vi fa(n+1), fb(n+1);
    // vi a(n), b(n);
    // for (int i = 0; i < n; i++) {
        // cin >> a[i];
        // fa[a[i]]++;
    // }
    // for (int i = 0; i < n; i++) {
        // cin >> b[i];
        // fb[a[i]]++;
    // }
    // if (fa != fb) {
        // cout << "NO\n";
        // return;
    // }
    // for (int i = 0; i <= n; i++) if (fa[i] >= 2) {
        // cout << "YES\n";
        // return;
    // }

    // vi where(n+1);
    // for (int i = 0; i < n; i++) {
        // where[a[i]] = i;
    // }

    // int min_swaps = 0;
    // V<bool> vis(n);
    // for (int i = 0; i < n; i++) if (!vis[i]) {
        // int siz = 1;
        // int j = i;
        // vis[j] = true;
        // while (!vis[where[b[j]]]) {
            // siz++;
            // j = where[b[j]];
            // vis[j] = true;
        // }
        // min_swaps += siz-1;
    // }

    // cout << (min_swaps%2 == 0 ? "YES" : "NO") << '\n';
// }

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}


