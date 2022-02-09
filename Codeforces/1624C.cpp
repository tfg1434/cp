#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr int max_n = 50;
int T, N;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;

    while (T--) {
        cin >> N;
        vector<int> a(N);
        vector<bool> used(N+1, false);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
        }
//        sort(a.begin(), a.end(), [] (int a, int b) {
//            return a > b;
//        });

        bool cont = false;
        for (const int& item:a) {
            int temp = item;
            while (temp > N || used[temp]) temp /= 2;
            
            if (temp == 0) {
                cout << "NO" << endl;
                cont = true;
                break;
            }
            
            used[temp] = true;
        }
        if (cont) {
            continue;
        }
            
        cout << "YES" << endl;
    }

    return 0;
}
