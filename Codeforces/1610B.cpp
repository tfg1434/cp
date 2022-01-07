#include <bits/stdc++.h>
using namespace std;

#define ll long long

//void check(int x) {
//    m = 0;
//
//    for (int i = 1; i <= n; ++i) {
//        if (a[i] != x)
//            b[++m] = a[i];
//    }
//
//    for (int i = 1; i <= m; ++i) {
//        if (b[i] != b[m+1-i])
//            return;
//    }
//    
//    ans = true;
//}
bool check(int* a, int start, int end, int rem){
    bool res = true;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int C;
    cin >> C;
    for (int c = 0; c < C; ++c) {
        int n;
        cin >> n;
        vector<int> a(n);

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool ans = true;
        bool first = false, second = false;
        int start = 0;
        int end = n-1;
        
        while (start <= end){
            if (a[start] != a[end]){
                
            }
        }
        
    }

    return 0;
}
