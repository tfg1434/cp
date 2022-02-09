/*
ID: toronto4
TASK: milk3
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr int max_cap = 20;

struct State {
    int value[3];
};
int capacity[3];
int dp[max_cap+1][max_cap+1][max_cap+1];
set<int> ans;

//    void pourTo(Bucket& other){
//        other.value = min(other.capacity, other.value + value);
//        value = max(0, value - other.capacity);
//    }
State pour(State s, int from, int to){
    int amt = s.value[from];
    if(s.value[to]+amt > capacity[to])
        amt = capacity[to] - s.value[to];

    s.value[from] -= amt;
    s.value[to] += amt;
    
    return s;
}

void solve(State s) {
    if (dp[s.value[0]][s.value[1]][s.value[2]]) return;
    dp[s.value[0]][s.value[1]][s.value[2]] = 1;
    
    //a is empty
    if (s.value[0] == 0) ans.insert(s.value[2]);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            solve(pour(s, i, j));
        }
    }
}

int main() {
    freopen("milk3.in", "r", stdin);
    freopen("milk3.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> capacity[0] >> capacity[1] >> capacity[2];
    solve(State {{0, 0, capacity[2]}});

    string sep;// = "";
    for (auto i: ans) {
        cout << sep << i;
        sep = " ";
    }
    
    cout << '\n';
    
    return 0;
}
