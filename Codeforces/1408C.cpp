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
constexpr double eps = 1e-6;
double N, L;
vector<double> a;


bool check (double time) {
    double t = time, l = 0, r = L;
    ll idx = 1; 
    while (idx <= N && l + t * idx > a[idx]) {
        t -= (a[idx]-l) / idx;
        l = a[idx];
        idx++;
    }
    l += t * idx;

    t = time, idx = 1;
    while (idx >= 1 && r-t*idx < a[N-idx+1]) {
        t -= (r-a[N-idx+1]) / idx;
        r = a[N-idx+1];
        idx++;
    }
    r -= t * idx;

    return l >= r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        cin >> N >> L;
        a = vector<double>(N+1);
        for (int i = 1; i <= N; i++) cin >> a[i];

        double l = 0, r = 1e9;
        while (r - l > eps) {
            double m = (l + r) / 2;
            if (check(m)) r = m;
            else l = m;
        }

        cout << fixed << setprecision(6) << l << '\n';
    }    
    
    return 0;
}

