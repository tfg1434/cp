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

        deque<ll> deq;
        for (ll i = 0; i < n; i++)
            if (s[i] == '1') deq.push_back(i);
        if (deq.size() % 2 || deq.size() == 0) {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;

        auto show = [&](ll i, ll j) {
            cout << (i+n)%n+1 << ' ' << (j+n)%n+1 << endl;
        };

        for (ll i = 0; i < n; i++) {
            if (s[i] == '0')
                show(i, i + 1);
        }

        for (ll i = 1; i < deq.size(); i++) {
            show(deq[0]+1, deq[i]+1);
        }
    }    
    
    return 0;
}

