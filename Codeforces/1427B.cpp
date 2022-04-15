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

        // ll ans = 0;
        ll wins = 0, loss = 0, cStreak = 0;
        vector<ll> streaks;
        for (ll i = 0; i < n; i++) {
            if (s[i] == 'L') {
                loss++;
                if (i == 0 || s[i-1] == 'W') streaks.push_back(0);
                streaks.back()++;

            } else if (s[i] == 'W') {
                wins++;
                if (i == 0 || s[i-1] == 'L') cStreak++;
            }
        }
        //corner cases
        if (k >= loss) {
            cout << 2*n-1 << '\n';
            continue;
        }
        if (wins == 0) {
            if (k == 0) cout << 0 << '\n';
            else cout << 2*k - 1 << '\n';
            continue;
        }

        //filling these in doesn't help
        if (s[0] == 'L') streaks[0] = INFF;
        if (s[n-1] == 'L') streaks.back() = INFF;
        sort(all(streaks));
        wins += k;
        for (auto x : streaks) {
            if (x > k) break;
            k -= x;
            cStreak--;
        }

        cout << 2 * wins - cStreak << '\n';
    }    
    
    return 0;
}

