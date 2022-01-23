/*
ID: toronto4
TASK: subset
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

//https://jvonk.github.io/usaco/2018/10/12/subset.html
int N;
int buckets[637][51];

int main() {
    freopen("subset.in", "r", stdin);
    freopen("subset.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
   
    if (N%4==1 || N%4==2) {
        cout << 0 << endl;
        exit(0);
    }
    
    //(c/2)(first number + last number)
    int sum = N*(N+1)/4;
    buckets[0][0] = 1;

    for (int i = 1; i < N; ++i) {
        for (int j = 0; j <= sum; ++j)
            buckets[j][i] = buckets[j][i - 1];

        for (int j = 0; j <= sum - i; ++j)
            buckets[j + i][i] += buckets[j][i - 1];
    }
    
    cout << buckets[sum][N - 1] << endl;
        
    return 0;
}
