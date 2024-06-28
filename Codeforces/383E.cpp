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

// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#define pct __builtin_popcount
constexpr int p2(int x) { return (int)1 << x; }
constexpr int msk2(int x) { return p2(x)-1; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 

constexpr int alpha(int a, int b, int c) {
    return 25*25*(a+1) + 25*(b+1) + (c+1);
}
int ww[alpha(24, 24, 24)+1];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s; sort(all(s)); s.erase(unique(all(s)), end(s));
        for (int j = 0; j < s.size(); j++) ww[alpha(-1, -1, s[j]-'a')]++;
        for (int j = 0; j < s.size(); j++) for (int k = j+1; k < s.size(); k++) {
            ww[alpha(-1, s[j]-'a', s[k]-'a')]++;
        }
        if (s.size() == 3) ww[alpha(s[0]-'a', s[1]-'a', s[2]-'a')]++;
    }

    vi ans(p2(24));
    auto work = [&](vi& A, int coef) {
        for (int i = 0; i < 24; i++) {
            for (int msk = msk2(24); msk >= 0; msk--) {
                if (msk & (1 << i)) A[msk] += A[msk^(1 << i)];
            }
        }
        for (int i = 0; i < p2(24); i++) ans[i] += coef*A[i];
    };

    {
        vi A(p2(24));
        for (int i = 0; i < 24; i++) A[p2(i)] = ww[alpha(-1, -1, i)];
        work(A, 1);
    }
    {
        vi A(p2(24));
        for (int i = 0; i < 24; i++) for (int j = i+1; j < 24; j++) A[p2(i)|p2(j)] = ww[alpha(-1, i, j)];
        work(A, -1);
    }
    {
        vi A(p2(24));
        for (int i = 0; i < 24; i++) for (int j = i+1; j < 24; j++) for (int k = j+1; k < 24; k++) {
            A[p2(i)|p2(j)|p2(k)] = ww[alpha(i, j, k)];
        }
        work(A, 1);
    }

    long long x = 0;
    for (int i = 0; i < p2(24); i++) x ^= 1L*ans[i]*ans[i];
    cout << x << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
