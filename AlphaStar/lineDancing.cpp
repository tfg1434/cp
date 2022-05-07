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
    
    ll n; while (cin >> n) {
        deque<ll> dq;
        ll idx = 1;
        for (ll i = 0; i < n; i++) {
            char op1, op2; cin >> op1 >> op2;
            ll k; if (op1 == 'D') cin >> k;

            if (op1 == 'A') {
                if (op2 == 'L') dq.push_front(idx);
                else dq.push_back(idx);
                idx++;
            } else {
                if (op2 == 'L') {
                    for (ll j = 0; j < k; j++) dq.pop_front();
                } else {
                    for (ll j = 0; j < k; j++) dq.pop_back();
                }
            }

            // for (auto x : dq) cout << x << ' ';
            // cout << '\n';
        }

        for (auto x: dq) cout <<x << '\n';
    }        
    
    return 0;
}

