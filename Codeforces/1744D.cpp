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
        ll n; cin >> n;
        vector<ll> a(n);
        for(auto& x : a) cin >> x;

        ll curr = 0;
        for (ll i = 0; i < n; i++) {
            ll x = a[i];
            while (x%2 == 0) {
                x /=2;
                curr++;
            }
        }
        ll getable = 0;
        vector<ll> pow(n+1);
        for (ll i = 1; i <= n; i++) {
            if (i % 2 == 1) continue;
            ll x = i;
            while (x%2==0) {
                x/=2;
                getable++;
                pow[x] += 1;
            }
        }

        ll ans = 0;
        ll A = 0;
        sort(all(pow));
        // cout << curr << endl;
        if (n-curr > getable) cout << -1 << endl;
        else {
            while (A < n-curr) {
                A += pow[pow.size()-1];
                pow.pop_back();
                ans++;
            }
            cout << ans << endl;
        }
    }    
    
    return 0;
}

