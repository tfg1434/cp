#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll int 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
// constexpr ll INFF = 1e18;
ll perm[502], used[502], n, l, r, s;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        memset(perm, 0, sizeof (perm));
        memset(used, 0, sizeof (used));
        cin >> n >> l >> r >> s;

        ll pos = n, rem = r-l+1;
        bool ok = true;
        for (ll i = l; i <= r; i++) {
            while (pos > 0 && s-pos < 1ll*(rem-1)*rem/2) pos--;
            //s too small
            if (pos == 0) ok = false;
            perm[i] = pos;
            s -= pos;
            used[pos] = true;
            rem--, pos--;
        }

        //fill in rest of perm
        pos = 1;
        for (ll i = 1; i <= n; i++) {
            if (perm[i] == 0) {
                while (used[pos]) pos++;
                perm[i] = pos;
                used[pos] = true;
            }
        }

        //too big. impossible s
        if (s != 0) ok = false;
        if (!ok) cout << -1 << '\n';
        else {
            for (ll i = 1; i <= n; i++) cout << perm[i] << ' ';
            cout << '\n';
        }
    }    
    
    return 0;
}

