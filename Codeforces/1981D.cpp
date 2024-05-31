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
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 

constexpr int MAX_SIEVE = 1e6;
vi primes;
void sieve() {
    vector<bool> isPrime(MAX_SIEVE+1, true);
    for (int i = 2; i*i <= MAX_SIEVE; i++) {
        if (isPrime[i])         
            for (int j = i*i; j <= MAX_SIEVE; j += i)
                isPrime[j] = false;
    }
    primes.pb(1);
    for (int i = 2; i <= MAX_SIEVE; i++) if (isPrime[i])
        primes.pb(i);
}

void solve() {
    int n; cin >> n;
    if (n == 2) {
        cout << "1 1\n";
        return;
    }
    int cnt = 0;
    while (cnt*cnt < n-1) cnt++;

    vi a(n);
    V<V<bool>> used(cnt, V<bool>(cnt));
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < cnt; j++) if (!used[a[i-1]][j]) {
            used[a[i-1]][j] = true;
            used[j][a[i-1]] = true;
            a[i] = j;
            break;
        }
    }

    for (int i = 0; i < n; i++) a[i] = primes[a[i]];
    for (int i = 0; i < n; i++) cout << a[i] << " \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    sieve();
    int t; cin >> t; while (t--) solve();
    return 0;
}

