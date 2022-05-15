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
        ll n, m; cin >> n >> m;
        string s; cin >> s;

        int bx = 0, by = 0;
        int min_bx = 0, max_bx = 0, min_by = 0, max_by = 0;
        for (char c: s) {
            if      (c == 'L') min_by = min(min_by, --by);
            else if (c == 'R') max_by = max(max_by, ++by);
            else if (c == 'U') min_bx = min(min_bx, --bx);
            else               max_bx = max(max_bx, ++bx);

            if (max_bx - min_bx >= n) {
                if (bx == min_bx) min_bx++;
                break;
            }
            if (max_by - min_by >= m) {
                if (by == min_by) min_by++;
                break;
            }
        }

        cout << 1 - min_bx << ' ' << 1 - min_by << '\n'; 
    }    
    
    return 0;
}

