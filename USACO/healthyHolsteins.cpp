/*
ID: toronto4
TASK: holstein
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int V, G;
int endPos = INT_MAX;
int maxSum = INT_MIN;
vector<int> best;
vector<int> which;
vector<int> required;
vector<vector<int>> feed;
vector<vector<int>> ans { };

int getSum(vector<int>& v){
    int res = 0;
    for (int i : v) res += i;
    
    return res;
}

bool isOk(vector<int>& v){
    return all_of(v.begin(), v.end(), [](int i){ return i <= 0; });
}

void solve(vector<int>& v, int scoop, int pos) {
    if (isOk(v) && endPos >= pos){
        best = which;
        endPos = pos - 1;
        maxSum = getSum(v);
    }
    
    if (pos == G) return;
    
    for (int i = scoop; i < feed.size(); i++) {
        vector<int> curr = v;
        for (int j = 0; j < V; j++)
            curr[j] -= feed[i][j];
        which[pos] = i+1;
        solve(curr, i+1, pos+1);
        which[pos] = 0;
    }
}

int main() {
    freopen("holstein.in", "r", stdin);
    freopen("holstein.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V;
    best.resize(26);
    which.resize(26);
    required.resize(V);
    for (int i = 0; i < V; i++) cin >> required[i];
    cin >> G;
    feed.resize(G);
    for (int g = 0; g < G; ++g) {
        feed[g] = vector<int>(V);
        
        for (int v = 0; v < V; ++v)
            cin >> feed[g][v];
    }
        
    solve(required, 0, 0);

    cout << endPos + 1;
    for (int i = 0; i <= endPos; i++) {
        cout << " " << best[i];
    }
    cout << endl;
    
    return 0;
}
