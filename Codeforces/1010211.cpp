#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int l = 1, r = 1e6;
    while (l != r) {
        int mid = (l + r + 1) / 2;
        cout << mid << endl;
        
        string response;
        cin >> response;
        if (response == "<")
            r = mid - 1;
        else if (response == ">=")
            l = mid;
    }
    
    cout << "! " << l << endl;
    
    return 0;
}
