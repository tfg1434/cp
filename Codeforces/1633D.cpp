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

    int MAXVAL = 1e3 + 1;
    vector<int> d(MAXVAL, MAXVAL);
    d[1] = 0;
    for (int i = 1; i < MAXVAL; i++) {
        for (int x = 1; x <= i; x++) {
            int y = i + i / x;
            if (y < MAXVAL) d[y] = min(d[y], d[i] + 1);
        }
    }
    
    int T; cin >> T; while (T--) {
        int n, k; cin >> n >> k;
        vector<int> b(n), c(n);
        for (auto& x : b) cin >> x;
        for (auto& x : c) cin >> x;
        int sum = 0;
        for (auto x : b) sum += d[x];
        k = min(k, sum);
        
        vector<int> dp(k+1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = k - d[b[i]]; j >= 0; j--) {
                dp[j + d[b[i]]] = max(dp[j + d[b[i]]], dp[j] + c[i]);
            }
        }

        //bc we clamped k, we use the max value
        cout << *max_element(all(dp)) << '\n';
    }    
    
    return 0;
}

