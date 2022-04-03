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
    
    double n;
    while (cin >> n && n ) {
        double a = floor(pow(n, 1/3.0)+1e-6);
        double dx = (-a*a*a+n)/(3*a*a);

        cout << fixed << setprecision(4) << a+dx << endl;
    }
    
    return 0;
}

