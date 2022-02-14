#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T;
constexpr int max_n = 2000;
int arr[max_n+1][max_n+1];
int s[max_n+1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[0][i];
        for (int i = 0; i < n; i++) {
            memset(s, 0, sizeof s);
            for (int j = 0; j < n; j++) s[arr[i][j]]++;
            for (int j = 0; j < n; j++) arr[i+1][j] = s[arr[i][j]];
        }
        
        int q; cin >> q;
        while (q--) {
            int x, k; cin >> x >> k;
            cout << arr[min(n, k)][x-1] << '\n';
        }
    }    
    
    return 0;
}

