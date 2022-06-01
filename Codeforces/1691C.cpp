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
        ll n, k; cin >> n >> k;
        string s; cin >> s;

        int ans = 0;
        for(int i = 0; i + 1 < n; i++) {
            ans += stol(s.substr(i, 2));
        }
        int cnt = count(begin(s), end(s), '1');
        if(cnt == 0) {
            cout << ans << "\n";
        } else {
            int L = 0;
            int R = 0;
            while(s[L] != '1') {
                L++;
            }
            while(s[n - R - 1] != '1') {
                R++;
            }
            if(L && R && L + R <= k && cnt > 1) {
                cout << ans - 11 << "\n";
            } else if(R && R <= k) {
                cout << ans - 10 + !(L || cnt > 1) << "\n"; // x10 -> x01
            } else if(L && L <= k && (R || cnt > 1)) {
                cout << ans - 1 << "\n"; // 01x -> 10x
            } else {
                cout << ans << "\n";
            }
        }}    
    
    return 0;
}

