#include <bits/stdc++.h>
using namespace std;

#define ll long long

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
    sort(h.begin(), h.end());
    vector<int> original = h;
    
    int dy = (h[N-1] - h[0] - 17) / 2;
    
    //auto minMax = minmax_element(h.begin(), h.end());

    
    
    return 0;
}
