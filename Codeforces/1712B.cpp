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

        if (n == 1) {
            cout << "1\n";
            continue;
        }
        if (n == 2) {
            cout << "2 1\n";
            continue;
        }

        vector<ll> p(n);
        p[0] = 1;
        for (ll i = n-1; i >= 1; i -= 2) {
            p[i] = i;
            p[i-1] = i+1;
        }

        for (ll i = 0; i < n; i++) {
            cout << p[i] << ' ';
        }
        cout << '\n';
    }    
    
    return 0;
}

