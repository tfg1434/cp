#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        int sum = 0;
        for (auto x : a) sum += x;

        for (int i = n; i >= 1; i--) {
            if (sum % i != 0) continue;

            int target = sum / i;
            int curr = 0;
            bool ok = true;
            for (int i = 0; i < n; i++) {
                curr += a[i];
                if (curr > target) {
                    ok = false;
                    break;
                } else if (curr == target) {
                    curr = 0;
                }
            }
            
            //you know there's always a solution
            //we iterated backwards!
            if (ok) {
                cout << n-i << '\n';
                break;
            }        
        }
    }    
    
    return 0;
}

