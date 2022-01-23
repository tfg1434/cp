#include <bits/stdc++.h>
using namespace std;
using Numeral = int;

#define ll long long

constexpr Numeral I = -1;
constexpr Numeral L = -2;    
constexpr Numeral M = -3;
constexpr Numeral V = -4;     
constexpr Numeral C = -5;
constexpr Numeral X = -6;     
constexpr Numeral D = -7;

int roman[7] = { 1, 5, 10, 50, 100, 500, 1000 };
int toNumeral[1001];
map<int, vector<Numeral>> dp;

vector<Numeral> next(int x) {
    if (x == 0) return {};
    if (dp.count(x)) return dp[x];
    
    int idx = 0;
    vector<Numeral> ans;
    
    while (idx < sizeof roman / sizeof roman[0] && roman[idx+1] <= x)
        idx++;
    
    ans.push_back(roman[idx]);
    for (int n:next(x - roman[idx])) {
        ans.push_back(n);
    }
    
    dp[x] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    toNumeral[1] = I, toNumeral[5] = V, toNumeral[10] = X, toNumeral[50] = L, 
        toNumeral[100] = C, toNumeral[500] = D,toNumeral[1000] = M;

    auto a = next(268);
    
    return 0;
}
