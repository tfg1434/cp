#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    ll a; cin >> a;
    vector<string> v = { "", "", "2", "3", "322", "5", "53", "7", "7222", "7332", };
    string ans = "";
    while (a != 0) {
        ans += v[a % 10];
        a /= 10;
    }
    sort(rall(ans));
    cout << ans << '\n';
    
    return 0;
}

