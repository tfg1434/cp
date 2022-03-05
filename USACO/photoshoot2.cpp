#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(n), b(n);
    
    auto posB = [&](int x) {
        for (int i = 0; i < n; i++) {
            if (b[i] == x) return i;
        }

        return -1;
    };

    vector<int> need(n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (posB(a[i]) > posB(a[j])) {
                need[i] = 1;
            }
        }
    }

    cout << accumulate(all(need), 0) << '\n';
    
    return 0;
}

