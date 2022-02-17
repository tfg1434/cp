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
        for (auto& i : a) cin >> i;

        //check if all elements are same
        if (all_of(all(a), [&](int x){return x == a[0];})) {
            cout << -1 << endl;
            continue;
        }

        int mi = *min_element(all(a));
        vector<int> b(n);
        sort(all(a));
        for (int i = 0; i < n; i++) {
            b[i] = a[i] - mi;
        }

        int gcdd = 0;
        for (auto i : b) {
            gcdd = gcd(gcdd, i);
        }
        
        cout << gcdd << '\n';
    }    
    
    return 0;
}

