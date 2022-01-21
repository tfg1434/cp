/*
ID: toronto4
TASK: holstein
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int V, G;
vector<int> required;
vector<vector<int>> feed;
vector<vector<int>> ans { };
vector<int> curr { };

bool isOk(const vector<int>& v) {
    vector<int> vitamins(V, 0);
    for (int scoopIdx : v) {
        for (int vitIdx = 0; vitIdx < V; ++vitIdx) {
            vitamins[vitIdx] += feed[scoopIdx][vitIdx];
        }
    }
    for (int i = 0; i < vitamins.size(); ++i) {
        if (vitamins[i] < required[i]) {
            return false;
        }
    }
    
    return true;
}

void solve() {
//    bool ok = true;
//    vector<int> vitamins(V, 0);
//    for (int scoopIdx = 0; scoopIdx < curr.size(); scoopIdx++) {
//        for (int vitIdx = 0; vitIdx < V; ++vitIdx) {
//            vitamins[vitIdx] += feed[curr[scoopIdx]][vitIdx];
//        }
//    }
//    for (int i = 0; i < vitamins.size(); ++i) {
//        if (vitamins[i] < required[i]) {
//            ok = false;
//            break;
//        }
//    }
//    if (ok) {
    ans.push_back(curr);
//        return;
//    }
    
    for (int i = 0; i < feed.size(); ++i) {
        if (std::count(curr.begin(), curr.end(), i) > 0) continue;
        
        curr.push_back(i);
        solve();
        curr.pop_back();
    }
    
    
}

int main() {
//    freopen("holstein.in", "r", stdin);
//    freopen("holstein.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> V;
    required = vector<int>(V);
    for (int i = 0; i < V; i++) cin >> required[i];
    cin >> G;
    feed = vector<vector<int>>(G);
    for (int g = 0; g < G; ++g) {
        feed[g] = vector<int>(V);
        
        for (int v = 0; v < V; ++v)
            cin >> feed[g][v];
    }
        
    solve();

//    sort(ans.begin(), ans.end(), [](const vector<int>& a, const vector<int>& b) {
//        return a.size() < b.size();
//    });
//    unsigned ll siz = ans[0].size();
//    vector<int> sol;
//    int minCost = INT_MAX;
//    for (const vector<int>& a:ans) {
//        if (a.size() != siz) continue;
//        int cost = 0;
//        for (int c:a) cost += c;
//        
//        if (cost < minCost) {
//            sol = a;
//            minCost = cost;
//        }
//    }
    vector<int>::size_type minSize = INT_MAX;
    vector<vector<int>> sol;
    for (const vector<int>& a:ans) {
        if (!isOk(a)) continue;
        
        sol.push_back(a);
        minSize = min(minSize, a.size());
    }
    
    cout << minSize;
    
    int minCost = INT_MAX;
    vector<int> a;
    for (auto s:sol) {
        if (s.size() != minSize) continue;
        
        int cost = 0;
        for (int c:s) cost += c;
        
        if (cost < minCost) {
            a = s;
            minCost = cost;
        }
    }
    
    for (int i : a) {
        cout << " " << i+1;
    }
    cout << endl;
    
    return 0;
}
