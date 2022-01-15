/*
ID: toronto4
TASK: ariprog
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N, M;
constexpr int max_m = 251;
int bs[2*max_m*max_m];
vector<pair<int, int>> ans;

bool check(int start, int diff){
    for (int i = 0; i < N; i++){
        //start + i * diff
        if (!bs[start + i * diff]) return false;
    }
    
    return true;
}

int main() {
    freopen("ariprog.in", "r", stdin);
    freopen("ariprog.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N >> M;

    for (int p = 0; p <= M; ++p) {
        for (int q = 0; q <= M; ++q) {
            bs[p*p+q*q]=1;
        }
    }
    
    int m2 = 2*M*M;
    for (int start = 0; start <= m2; ++start) {
        for (int d = 1; d <= (m2-start)/(N-1); ++d) {
            if (check(start, d)) {
                ans.push_back({start, d});
            }
        }
    }
    sort(ans.begin(), ans.end(), [](const pair<int, int>& a, const pair<int, int>& b){
        return a.second < b.second;
    });

    for (auto x:ans) {
        cout << x.first << " " << x.second << '\n';
    }
    if (ans.empty()) cout << "NONE" << '\n';
    

    return 0;
}
