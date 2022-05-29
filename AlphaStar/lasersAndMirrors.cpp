#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll int 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(a) (ll)((a).size())
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
// constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, xl, yl, xb, yb; cin >> n >> xl >> yl >> xb >> yb;
    map<ll, vector<ll>> xs, ys;
    queue<array<ll, 3>> q;
    // vector<vector<ll>> adj(n+1, vector<ll>());

    xs[xl].push_back(yl);
    ys[yl].push_back(xl);
    xs[xb].push_back(yb);
    ys[yb].push_back(xb);
    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        xs[x].push_back(y);
        ys[y].push_back(x);
    }

    q.push({ 0, 1, xl  });
    q.push({ 0, 0, yl  });
    set<pll> vis;
    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        
        ll dist = node[0], isX = node[1], coord = node[2];

        if ((isX && coord == xb) || (!isX && coord == yb)) {
            cout << dist << endl;
            return 0;
        }

        vis.insert({ isX, coord });
        if (isX) {
            for (ll y : xs[coord]) {
                if (vis.count({ 0, y })) continue;
                q.push({ dist+1, 0, y });
            }
        } else {
            for (ll x : ys[coord]) {
                if (vis.count({ x, 0 })) continue;
                q.push({ dist+1, 1, x });
            }
        }
    }


    
    return 0;
}

