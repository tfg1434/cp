#include "secret.h"
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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

const int max_n = 1000;
int range[max_n+1][max_n+1];

void precalc(int l, int r) {
    if (l == r-1) return;
    int m = (l+r)/2;
    for (int i = m-1; i >= l; i--) if (range[i][m] == -1) {
        range[i][m] = Secret(range[i][i+1], range[i+1][m]);
    }
    for (int i = m+1; i <= r; i++) if (range[m][i] == -1) {
        range[m][i] = Secret(range[m][i-1], range[i-1][i]);
    }
    precalc(l, m);
    precalc(m, r);
}

void Init(int N, int A[]) {
    memset(range, -1, sizeof range);
    for (int i = 0; i < N; i++) range[i][i+1] = A[i];
    precalc(0, N);
}

int Query(int L, int R) {
    for (int i = L+1; i <= R; i++) {
        if (range[L][i] != -1 && range[i][R+1] != -1)
            return Secret(range[L][i], range[i][R+1]);
    }
    return range[L][R+1];
}
