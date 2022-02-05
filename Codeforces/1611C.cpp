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
        
        if ( !(a[0] == n || a[a.size() - 1] == n) ) {
            cout << -1 << endl;
            continue;
        }
        
        std::reverse(a.begin(), a.end());
        //allowed to just reverse because you will only take from one side
        //until last element
        for (const int item : a) cout << item << " ";
        cout << endl;
    }

    return 0;
}
