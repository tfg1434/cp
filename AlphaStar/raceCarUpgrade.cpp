#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
using pdd = pair<double, double>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

struct Part {
    double f, m, idx;
};
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    double F, M;
    ll N;
    while (cin >> F >> M >> N) {
        vector<Part> a(N);
        for (ll i = 0; i < N; i++) {
            cin >> a[i].f >> a[i].m;
            a[i].idx = i+1;
        }

        sort(all(a), [](Part a, Part b) {
            return a.f / a.m > b.f / b.m;
        });

        vector<ll> ans;
        for (ll i = 0; i < N; i++) {
            if ((F + a[i].f) / (M + a[i].m) > F / M) {
                F += a[i].f; M += a[i].m;
                ans.push_back(a[i].idx);
            }
        }

        if (ans.size() == 0) cout << "NONE\n";
        else {
            sort(all(ans));
            // cout << ans.size() << '\n';
            for (auto x : ans) cout << x << '\n';
        }
    }        
    
    return 0;
}

