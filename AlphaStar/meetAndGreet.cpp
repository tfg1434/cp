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

struct Coord {
    ll cow, t, dir;
};
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<Coord> a;
    ll b, e; cin >> b >> e;

    auto read = [&](ll n, ll cow) {
        ll t = 0; 
        ll res;

        for (ll i = 0; i < n; i++) {
            ll x; cin >> x;
            char c; cin >> c;
            ll dir = (c == 'L' ? -1 : 1);

            if (t == 0) res = dir;
            else a.push_back(Coord{cow, t, dir});

            t += x;
        }
         a.push_back(Coord{cow, t, 0});
        return res;
    };

    ll d1 = read(b, 0); 
    ll d2 = read(e, 1);
    sort(all(a), [](Coord a, Coord b) {
        return a.t < b.t;
    });

    ll t = 0, s1 = 0, s2 = 0, ans = 0;
    for (ll i = 0; i < len(a); i++) {
        ll ns1 = (a[i].t - t) * d1 + s1;
        ll ns2 = (a[i].t - t) * d2 + s2;

        if (s1 != s2 && ((ns1 < ns2) ^ (s1 < s2) || ns1 == ns2)) {
            ans++;
        }

        t = a[i].t;
        s1 = ns1; s2 = ns2;
        if (a[i].cow == 0) d1 = a[i].dir;
        else d2 = a[i].dir;
    }
    cout << ans << endl;
    
    return 0;
}

