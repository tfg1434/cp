/*
ID: toronto4
TASK: combo
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int floorMod(int a, int n) {

    // Type casting is necessary
    // as (int) / (int) will give
    // int result, i.e. -3 / 2
    // will give -1 and not -1.5
    int q = (int)floor((double)a / n);

    // Return the resultant remainder
    return a - n * q;
}

int main() {
    freopen("combo.in", "r", stdin);
    freopen("combo.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    int farm[3];
    int master[3];
    cin >> N;
    cin >> farm[0] >> farm[1] >> farm[2];
    cin >> master[0] >> master[1] >> master[2];

    auto isClose = [=](int a, int b){
        return abs(a-b)<=2 || abs(a-b)>=N-2;
    };
    
    auto canOpen = [=](int f1, int f2, int f3, int m1, int m2, int m3){
        return isClose(f1, m1) && isClose(f2, m2) && isClose(f3, m3);
    };
    
    int ans = 0;
    for (int i=1; i<=N; i++){
        for (int j = 1; j <= N; ++j) {
            for (int k = 1; k <= N; ++k) {
                if (canOpen(i, j, k, farm[0], farm[1], farm[2]) ||
                    canOpen(i, j, k, master[0], master[1], master[2])){
                    
                    ++ans;
                }
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}

