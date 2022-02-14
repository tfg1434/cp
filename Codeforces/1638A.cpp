#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& i : a) cin >> i;

        int start = -1, end = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] != i+1) {
                start = i; 
                end = find(a.begin(), a.end(), i+1) - a.begin();
                // cout << "DEBUG: " << start << " " << end << endl;
                break;
            }
        }

        if (start != -1) reverse(a.begin() + start, a.begin() + end + 1);
        for (auto i : a) cout << i << ' ';
        cout << endl;
    }
            
    return 0;
}

