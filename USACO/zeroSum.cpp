/*
ID: toronto4
TASK: zerosum 
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N;
vector<string> ans;

int eval(string expr) {
    char op = '+';
    string sn;
    int res = 0;
    
    for (char c:expr) {
        if (isspace(c)) continue;
        
        if (!isdigit(c)) {
            int n = stoi(sn);
            if (op == '+') res += n;
            else if (op == '-') res -= n;
            
            op = c;
            sn = "";
            
        } else sn += c;
    } 
    
    if (!sn.empty()) {
        int n = stoi(sn);
        if (op == '+') res += n;
        else if (op == '-') res -= n;
    }
    
    return res;
}

void solve(int depth, const string& expr) {
    if (depth > N) {
        if (eval(expr) == 0) ans.push_back(expr);
        return;
    }

    solve(depth+1, expr + '+' + to_string(depth));
    solve(depth+1, expr + '-' + to_string(depth));
    solve(depth+1, expr + ' ' + to_string(depth));
}

int main() {
    freopen("zerosum.in", "r", stdin);
    freopen("zerosum.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    solve(2, "1");
    sort(ans.begin(), ans.end());

    for (string expr:ans) 
        cout << expr << endl;
    
    return 0;
}

