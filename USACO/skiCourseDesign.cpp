/*
ID: toronto4
TASK: skidesign
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr int max_n = 1000;
constexpr int max_m = 100;

int main() {
    freopen("skidesign.in", "r", stdin);
    freopen("skidesign.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    vector<int> h(N);
    for (int i = 0; i < N; i++)
        cin >> h[i];

    int minCost = 99999999;
    //consider cost of all ranges with max dy =17
    for (int i = 0; i <= 83; ++i) {
        int up = i + 17;
        int cost = 0;
        int x;

        for (int j = 0; j < N; ++j) {
            if (h[j] > up) x = h[j] - up;
            else if (h[j] < i) x = i - h[j];
            else x = 0;
            
            cost += x*x;
        }
        
        minCost = min(minCost, cost);
    }
    
    cout << minCost << endl;
    
    return 0;
}
