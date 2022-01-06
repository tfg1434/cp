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
        //https://codeforces.com/problemset/problem/1613/B
        
        unordered_set<int> sett;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            int in;
            cin >> in;
            
            sett.insert(in);
            a[i] = in;
        }

        int count = floor(n / 2);
        int found = 0;

        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a.size(); ++j) {
                int x = a[i];
                int y = a[j];
                
                if (i == j) continue;
                if (x == y) continue;
                if (sett.count(x % y)) continue;
                
                found++;
                cout << x << " " << y << '\n';
                
                if (found == count)
                    goto done;
            }
        }
        
        done: ;
    }

    return 0;
}
