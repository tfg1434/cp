#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T, N, M;
int arr[100'000];

int manhattan(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    for (int t = 0; t < T; ++t) {
        memset(arr, -1, sizeof(arr));
        
        cin >> N >> M;
       
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; ++m) {
                int dist = max(n, N - 1 - n) + max(m, M - 1 - m); 
                
                arr[n*M+m] = dist;
            }
        }

        sort(arr, arr + M*N);
        string sep = "";
        for (int i = 0; i < M*N; ++i) {
            if (arr[i] == -1) continue;
            
            cout << sep << arr[i];
            sep = " ";
        }
        
        cout << '\n';
    }

    return 0;
}

