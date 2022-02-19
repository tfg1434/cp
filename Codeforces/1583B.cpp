#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;
constexpr int max_n = 1e5+1;
int arr[max_n];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;

        memset(arr, 0, sizeof arr);
        for (int i = 1; i <= m; i++) {
            int a, b, c; cin >> a >> b >> c;
            arr[b] = 1;
        }
        int num;
        for (num = 1; num <= max_n; num++) 
            if (!arr[num]) break;
       
        for (int i = 1; i <= n; i++) {
            if (i == num) continue;

            cout << i << ' ' << num << '\n';
        }

    }    
    
    return 0;
}

