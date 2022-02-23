#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;

bool isPossible(int d1, int v1, int d2, int v2) {
    return v2 - v1 <= d2 - d1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        int d1, v1; cin >> d1 >> v1;
        int d3, v3; cin >> d3 >> v3;
        int d2; cin >> d2;

        for (int v2 = v1; v2 <= v3; v2++) {
            if (isPossible(d2, v2, d3, v3) && isPossible(d1, v1, d2, v1)) {
                cout << v2 << '\n';
                break;
            }
        } 
    }    
    
    return 0;
}

