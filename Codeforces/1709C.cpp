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
        string s; cin >> s;
        ll n = len(s);

        ll d = 0, q = 0;
        for (char c : s) {
            if (c == '(') d++;
            else if (c == ')') d--;
            else q++;

            //d==1 and q == 0  or  d==0 and q == 1  or  d+q = 1
            if (1-d == q) {
                q = 0;
                d = 1;
            }
        }

        if (d == q) cout << "YES\n";
        else cout << "NO\n";
    }    
    
    return 0;
}

