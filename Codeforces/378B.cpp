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
    vector<int> a(n), b(n), c(n, 0), d(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    //k = n/2 case
    for (int i = 0; i < n/2; i++) {
        c[i] = d[i] = 1;
    }
    //k = 0 case
    int i = 0, j = 0, k = n; 
    while (k--) {
        if (a[i] <= b[j]) {
            c[i] = 1;
            i++;
        } else {
            d[j]= 1;
            j++;
        }
    }

    for (auto x : c) cout << x;
    cout << endl;
    for (auto x : d) cout << x;
    
    return 0;
}

