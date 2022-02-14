#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long

int T;
constexpr int max_bits = 30;
int arr[max_bits + 1];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        memset(arr, 0, sizeof(arr));
        for (int i = 1; i <= n; i++)  {
            int x; cin >> x;
            for (int j = 0; j < max_bits; j++) {
                if (x & (1 << j)) arr[j]++;
            }
        }

        //find gcd of all elements in arr
        int x = arr[0];
        for (int i = 0; i <= max_bits; i++) x = gcd(x, arr[i]);
        for (int i = 1; i <= n; i++) {
            if (x % i == 0) cout << i << ' ';
        }
        cout << '\n';
    }    
    
    return 0;
}

