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
        string a, b; cin >> a >> b;

        vector<ll> board;//1=top, 0=both,-1=bottom 
        ll last = -2;
        for (ll i = 0; i < n; i++) {
            ll x;
            if (a[i] == b[i]) x = 0;
            else x = a[i] == '*' ? 1 : -1;
            
            if (last == x) continue;
            last = x;
            board.push_back(x);
        }

        ll star = count(all(a), '*') + count(all(b), '*');

        ll resU = 0, resD = 0;
        bool isUp = true;
        for (ll i = 0; i < board.size(); i++) {
            if (board[i] == 0) continue;
            if (isUp && board[i] == 1 || !isUp && board[i] == -1) continue;
            resU++;
        }
        isUp = false;
        for (ll i = 0; i < board.size(); i++) {
            if (board[i] == 0) continue;
            if (isUp && board[i] == 1 || !isUp && board[i] == -1) continue;
            resD++;
        }

        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            if (a[i] == '.' && b[i] == '.') ans++;
        }
        ans += star;
        ans += min(resU, resD);
        cout << ans-1 << endl;
    }    
    
    return 0;
}

