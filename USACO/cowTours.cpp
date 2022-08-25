/*
ID: toronto4
LANG: C++
TASK: cowtour
*/
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
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

constexpr int MOD = 1e9 + 7;
constexpr double INF = (1e40);
constexpr ll INFF = 1e18;
constexpr ll MAXN = 155;
double dist[MAXN][MAXN];
double diam[MAXN];
double fielddiam[MAXN];
ll field[MAXN];


double ptdist(pll a, pll b) {
    return sqrt((double)(b.first-a.first)*(b.first-a.first)+(double)(b.second-a.second)*(b.second-a.second));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("cowtour.in", "r", stdin);
    freopen("cowtour.out", "w", stdout);
    
    ll n; cin >> n;
    vector<pll> pt(n);
    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        pt[i] = {x, y};
    }
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            char c; cin >> c;
            if (i == j) dist[i][j] = 0;
            else if (c == '0') dist[i][j] = INF;
            else dist[i][j] = ptdist(pt[i], pt[j]);
        }
        cin.clear();
    }

    //floyd warshall
    for (ll k = 0; k < n; k++) {
        for (ll i = 0; i < n ; i++) {
            for (ll j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) 
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    //find components
    ll ncomp = 0;
    for (ll i = 0; i < n; i++) field[i] = -1;
    for (ll i = 0; i < n; i++) {
        if (field[i] == -1) {
            y_combinator([&](auto rec, ll f, ll m) -> void {
                if (field[f] != -1) {
                    assert(field[f] == m);
                    return;
                }

                field[f] = m;
                for (ll j = 0; j < n; j++) {
                    if (dist[f][j] < INF/2) rec(j, m);
                }
            })(i, ncomp++);
            // cout << ncomp << endl;
        }
    }

    //find diam from each point
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j <  n; j++) {
            if (diam[i] < dist[i][j] && dist[i][j] < INF / 2)
                diam[i] = dist[i][j];
        }
        if (diam[i] > fielddiam[field[i]])
            fielddiam[field[i]] = diam[i];
    }

    // for (ll i = 0; i < n; i++) cout << field[i] << ' ';
    double ans = INF;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < n; j++) {
            if (field[i] == field[j]) continue;

            double d = diam[i] + diam[j] + ptdist(pt[i], pt[j]);
            if (d < fielddiam[field[i]]) d = fielddiam[field[i]];
            if (d < fielddiam[field[j]]) d = fielddiam[field[j]];
            if (d < ans) ans = d;
        }
    }

    // cout << ans << endl;
    cout << fixed << setprecision(6) << ans << endl;
    
    
    return 0;
}

