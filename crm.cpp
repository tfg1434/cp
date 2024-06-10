#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

using vi = vector<int>;



array<int, 2> crm(vi a, vi m) {
    if (a.size() != m.size()) return {-1, -1};
    int n = a.size();
    for (int i = 0; i+1 < n; i++) {
        int g = gcd(m[i], m[i+1]);
        if ((a[i]-a[i+1])%g) return {-1, -1};
        int p, q;
        ext_gcd(m[i]/g, m[i+1]/g, p, q);

        a[i+1] = a[i]*m[i+1]/g*q + a[i+1]*m[i]/g*p;
        m[i+1] = lcm(m[i], m[i+1]);
        a[i+1] %= m[i+1];
    }
    return {a.back(), m.back()};
}

signed main() {
    vi a = {1, 3, 8};
    vi b = {7, 5, 35};
    ps(crm(a, b));
    return 0;
}
