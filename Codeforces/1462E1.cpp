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
int n;


void solve() {
    cin >> n;
    vector<ll> freq(n+1);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    ll ans = 0;
    //(x, x+1, x+2)
    for (int i = 2; i < n; i++) 
        ans += freq[i-1] * freq[i] * freq[i+1];
    //(x, x, x+1)
    for (int i = 1; i < n; i++)
        ans += freq[i]*(freq[i]-1)/2*freq[i+1];
    //(x, x+1, x+1)
    for (int i = 2; i <= n; i++)
        ans += freq[i-1]*freq[i]*(freq[i]-1)/2;
    //(x, x+2, x+2)
    for (int i = 2; i < n; i++)
        ans += freq[i-1]*freq[i+1]*(freq[i+1]-1)/2;
    //(x, x, x+2)
    for (int i = 2; i < n; i++)
        ans += freq[i+1]*freq[i-1]*(freq[i-1]-1)/2;
    //(x, x, x)
    for (int i = 1; i <= n; i++)
        ans += freq[i]*(freq[i]-1)*(freq[i]-2)/6;

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        solve();         
    }    
    
    return 0;
}

