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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, q; cin >> n >> q;
    set<ll> freeRows, freeCols;
    for (ll i = 1; i <= n; i++) {
        freeRows.insert(i);
        freeCols.insert(i);
    }
    vector<ll> row(n+1, 0), col(n+1, 0);

    for (ll i = 0; i < q; i++) {
        ll t; cin >> t;

        //add a rook
        if (t == 1) {
            ll x, y; cin >> x >> y;
            col[x]++; row[y]++;
            if (row[y] == 1) freeRows.erase(y);
            if (col[x] == 1) freeCols.erase(x);

        //remove a rook
        } else if (t == 2) {
            ll x, y; cin >> x >> y;
            col[x]--; row[y]--;
            if (col[x] == 0) freeCols.insert(x);
            if (row[y] == 0) freeRows.insert(y);

        //query
        } else if (t == 3) {
            ll x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;

            if (x2 >= *freeCols.lower_bound(x1) && y2 >= *freeRows.lower_bound(y1)) {
                cout << "No" << endl;
            } else {
                cout << "Yes" << endl;
            }
        }
    }
    
    return 0;
}

