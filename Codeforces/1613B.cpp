#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int C;
    cin >> C;
    for (int c = 0; c < C; ++c) {
        int n;
        cin >> n;

        vector <int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        
        auto elem = std::min_element(a.begin(), a.end());
        int index = elem - a.begin();
        int y = *elem;
        int target = n/2;
        int count = 0;

        for (int i = 0; i < n; ++i) {
            int x = a[i];
            
            if (x == y) continue;
            
            ++count;
            cout << x << " " << y << '\n';
            
            if (count == target) break;
        }
    }

    return 0;
}
