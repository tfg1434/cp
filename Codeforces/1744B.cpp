#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(a) (ll)((a).size())
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
         ll n, q; cin >> n >> q;
         vector<ll> a(n);
         for (auto& x : a) cin >> x;
         ll odd = 0, even = 0;
         ll co = 0;
         ll ans = 0;
         for (ll i = 0; i < n; i++) {
             // if (a[i] % 2 == 0) even += a[i];
             // else odd += a[i], co++;
             if (a[i] % 2==1) co++;
             ans += a[i];
         }

         for (ll i = 0; i < q; i++) {
             ll t, x; cin >> t >> x;
             if (x%2==0) {
                 if (t == 1) ans += co *x;
                 else ans += (n-co)*x;
                 // cout << "A" << n-co << endl;
             } else {
                 //all become even
                 if (t == 1) {
                     ans += x * co;
                     co = 0;
                 } else {
                     ans += x*(n-co);
                     co = n;
                 }
             }
             cout << ans << endl;
         }
    }    
    
    return 0;
}

