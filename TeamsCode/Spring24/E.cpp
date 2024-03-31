#include<bits/stdc++.h>
using namespace std;
pair<long long, long long> backEdge = make_pair(-1e9, -1e9);
vector<bool> visited;
vector<vector<long long> > adj;
vector<vector<long long> > dp;
vector<vector<long long> > adj2;
vector<long long> cost;
void dfs(long long u, long long p){
    if(visited[u]){
        if(backEdge == make_pair((long long)-1e9, (long long)-1e9) ){
            backEdge.first = u;
            backEdge.second = p;
        }
        return;
    }
    visited[u] = true;
    if(p != 0){
        adj2[u].push_back(p);
        adj2[p].push_back(u);
    }
    for(long long v : adj[u]){
        if(v != p){
            dfs(v, u);
        }
    }
}
void dfs2(long long u, long long p){
    for(long long v : adj2[u]){
        if(v != p){
            dfs2(v, u);
            if(dp[u][0] != -1e9){
                dp[u][0] += max(dp[v][1], dp[v][0]);
            }
            if(dp[u][1] != -1e9){
                dp[u][1] += dp[v][0];
            }
        }
    }
    if(dp[u][1] != -1e9){
        dp[u][1] += cost[u];
    }
}
int main(){
    long long n;
    cin >> n;
    cost.resize(1 + n);
    adj.resize(1 + n);
    adj2.resize(1 + n);
    visited.resize(1 + n);
    dp.assign(1 + n, vector<long long>(2, 0));
    for(long long i = 1; i <= n; i++){
        cin >> cost[i];
        long long x;
        cin >> x;
        if(i != x){
            adj[x].push_back(i);
            adj[i].push_back(x);
        }
    }
    dfs(1, 0);
    long long ans = -1e9;
    dp[backEdge.first][1] = -1e9;
    dp[backEdge.second][1] = -1e9;
    dfs2(1, 0);
    ans = max(dp[1][0], dp[1][1]);
    dp.assign(1 + n, vector<long long>(2, 0));
    dp[backEdge.first][0] = -1e9;
    dp[backEdge.second][1] = -1e9;
    dfs2(1, 0);
    ans = max(ans, max(dp[1][0], dp[1][1]));
    dp.assign(1 + n, vector<long long>(2, 0));
    dp[backEdge.first][1] = -1e9;
    dp[backEdge.second][0] = -1e9;
    dfs2(1, 0);
    ans = max(ans, max(dp[1][0], dp[1][1]));
    cout << ans << "\n";
}
