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
        string s; cin >> s;
        ll n = s.size();
        ll sumMid = 0;
        for (ll i = 1; i < n-1; i++) sumMid += s[i] - 96;
        ll l = s[0] - 96, r = s[n-1] - 96;

        if (n%2 == 0) {
            cout << "Alice " << l+sumMid+r << '\n';
            continue;
        } 
        if (n == 1) {
            cout << "Bob " << l << '\n';
            continue;
        }

        cout << "Alice " << sumMid+max(l, r)-min(l, r) << '\n';
    }    
    
    return 0;
}

