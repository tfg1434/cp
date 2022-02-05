#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T, N;

struct Building {
    int times, idx;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        vector<Building> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i].times;
            a[i].idx = i;
        }
        vector<Building> b = a;
        sort(b.begin(), b.end(), [](Building a, Building b) {
            return a.times > b.times;
        });
        vector<int> ans(N);
        int curr = 1;
        int time = 0;
        for (int i = 0; i < N; i++) {
            ans[b[i].idx] = curr; 
            
            time += 2 * abs(ans[b[i].idx]) * b[i].times;
            
            if (curr > 0) curr = -curr;
            else curr = -curr + 1;
        }
        
//        for (int i = 0; i < N; i++) {
//            time += 2 * a[i].times * abs(ans[i]);
//        }
        
        cout << time << '\n';
        cout << 0;
        for (int item:ans) {
            cout << " " << item;
        } 
        cout << endl;
    }

    return 0;
}
