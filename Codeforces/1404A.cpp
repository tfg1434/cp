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
    
    int T; cin >> T; while (T--) {
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        ll zeros = 0, ones = 0;
        bool ans = true;
        for (ll i = 0; i < k; i++) {
            ll tmp = -1;
            for (ll j = i; j < n; j += k) {
                if (s[j] == '?') continue;

                if (tmp != -1 && s[j] - '0' != tmp) {
                    ans = false;
                    break;
                }
                tmp = s[j] - '0';
            }

            if (tmp != -1) {
                (tmp == 0 ? zeros : ones)++;
            }
        }

        if (max(zeros, ones) > k / 2) ans = false;
        if (ans) cout << "YES\n";
        else cout << "NO\n";
    }    
    
    return 0;
}

