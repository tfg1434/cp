/*
ID: toronto4
TASK: numtri
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int max_r = 1000;
int tri[max_r][max_r];
int ans;
int dp[max_r][max_r] {-1};
//struct Node {
//    Node* parent;
//    Node* left;
//    Node* right;
//};

int solve(int state, int i, int j, int height) {
    if (dp[i][j] != -1) return dp[i][j];
    
    if (i >= height) return 0;
    
    state += tri[i][j];
    
    int left = solve(state, i+1, j, height);
    int right = solve(state, i+1, j+1, height);
    
    return dp[i][j] = tri[i][j] + max(left, right);
}

int main() {
    freopen("numtri.in", "r", stdin);
    freopen("numtri.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    memset(dp, -1, sizeof dp);
    int R;
    cin >> R;

    for (int i = 0; i < R; ++i) {
        for (int j = 0; j <= i; ++j) {
            cin >> tri[i][j];
        }
    }
    
    cout << solve(0, 0, 0, R) << endl;

    return 0;
}

