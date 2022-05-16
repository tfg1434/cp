#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, k; while (cin >> n >> k) {
        vector<ll> A, B, C;
        ll ca = 0, cb = 0;

        for (ll i = 0; i < n; i++) {
            ll t, a, b; cin >> t >> a >> b;
            
            if (a == 1 && b == 1) {
                ca++; cb++;
                C.push_back(t);
            } else if (a == 1) {
                ca++;
                A.push_back(t);
            } else if (b == 1) {
                cb++;
                B.push_back(t);
            }
        }

        if (ca < k || cb < k) {
            cout << -1 << endl;
            continue;
        }

        sort(all(A));
        sort(all(B));
        for (ll i = 0; i < min(A.size(), B.size()); i++) {
            C.push_back(A[i] + B[i]);
        }
        sort(all(C));

        ll ans = 0;
        for (ll i = 0; i < k; i++) {
            ans += C[i];
        }

        cout << ans << endl;
    }
    
    return 0;
}

