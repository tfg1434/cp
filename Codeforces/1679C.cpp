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
constexpr ll N = 1e5+5;
ll xToY[N];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, q; cin >> n >> q;
    vector<pll> xs; //{x, idx}
    ll idx = 0;

    for (ll i = 0; i < q; i++) {
        ll t; cin >> t;
        if (t == 1) {
            ll x, y; cin >> x >> y;
            xs.push_back({x, y});
            idx++;
            push_heap(all(xs));
        } else if (t == 2) {
            bool broke = false;
            while (!broke) {
                ll x, y; cin >> x >> y;
                auto xx = lower_bound(all(xs), x);
                if (xx->second == y) {
                    xs.erase(xx);
                    broke = true;
                }
            }
        } else if (t == 3) {
            ll x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
            bool found = false;
            while (!found) {
                auto xx = lower_bound(all(xs) , x1);
                if (xx - xs.begin() > x2) break;
                else found = true;
            }

            cout << (found ? "Yes" : "No") << endl;
        }
    }
    
    return 0;
}

