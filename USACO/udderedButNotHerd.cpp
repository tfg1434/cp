#include <bits/stdc++.h>
using namespace std;

#define ll long long

string cowphabet;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> cowphabet;
    string hummed;
    cin >> hummed;
    
    int prev = INT_MAX;
    int ans = 0;
    for (char c : hummed) {
        int idx = cowphabet.find(c);
        
        if (idx > prev) {
            prev = idx; 
        } else {
            ans++;
            prev = idx; 
        }
    }
    
    cout << ans << endl;

    return 0;
}
