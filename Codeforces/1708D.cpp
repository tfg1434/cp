#include <bits/stdc++.h>
// #pragma GCC target ("avx2")
// #pragma GCC optimization ("O3")
// #pragma GCC optimization ("unroll-loops")
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
        ll n; cin >> n;
        vector<ll> a[n];
        for (ll i = 0; i < n; i++) {
            ll x; cin >> x; a[0].push_back(x);
        }

        ll i;
        for (i = 0; i < n-1; i++) {
            sort(all(a[i]));
            for (ll j = 0; j < len(a[i])-1; j++) {
                if (j == 0 && len(a[i]) < n-i) a[i+1].push_back(a[i][0]); 
                if (a[i][j+1] - a[i][j] > 0) a[i+1].push_back(a[i][j+1] - a[i][j]);
            }
            if (len(a[i+1]) <= 1) {
                i++; break;
            }
        }

        if (len(a[i]) > 0) cout << a[i][0] << endl;
        else cout << 0 << endl;
    }    
    
    return 0;
}

