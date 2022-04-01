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
    
    ll a, b; cin >> a >> b;
    ll gcdd = gcd(a, b);
    ll masha = a / gcdd, dasha = b / gcdd;
    if (a > b) masha --;
    else if (a < b) dasha --;
    //|a-b| <= 1
    if (masha == dasha) cout << "Equal\n";
    else if (dasha > masha) cout << "Dasha\n";
    else cout << "Masha\n";
    
    return 0;
}

