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
        ll n; cin >> n;
        string s; cin >> s;

        if (s[0] == '0' || s[n-1] == '0') {
            cout << "NO" << '\n';
            continue;
        }
        if (count(all(s), '0') % 2 == 1 || count(all(s), '1') % 2 == 1) {
            cout << "NO" << '\n';
            continue;
        }

        string a = string(n, '*');
        string b = a;
        a[0] = b[0] = '('; a[n-1] = b[n-1] = ')';
        bool last0open = false, last1open = true;
        for (ll i = 1; i < n-1; i++) {
            if (s[i] == '0') {
                if (last0open) a[i] = '(', b[i] = ')';
                else a[i] = ')', b[i] = '(';
                last0open = !last0open;
            } else {
                if (last1open) a[i] = b[i] = '(';
                else a[i] = b[i] = ')';
                last1open = !last1open;
            }
        }
        
        cout << "YES\n" << a << '\n' << b << '\n';
    }    
    
    return 0;
}

