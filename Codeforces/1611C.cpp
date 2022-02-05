#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& item : a) cin >> item;
        
        int me = *max_element(a.begin(), a.end());
        if ( !(a[0] == me || a[a.size() - 1] == me) ) {
            cout << -1 << endl;
            continue;
        }
        
        vector<int> ans;
        for (int l = 0; l < n / 2; ++l) {
            int r = n - l - 1;
            ans.insert(ans.begin(), a[l]); ans.push_back(a[r]);
        }
        if (n % 2 != 0) ans.push_back(a[n / 2]);

        for (const int item : ans) cout << item << " ";
        cout << endl;
    }

    return 0;
}
