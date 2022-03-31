#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
int arr['z' + 1];


char flipCase(char c) {
    if (c >= 'a' && c <= 'z') return c - 'a' + 'A';
    else if (c >= 'A' && c <= 'Z') return c - 'A' + 'a';
    else return c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    string s, t; cin >> s >> t;
    for (char c : t) arr[c]++;

    int YAY = 0, WHOOPS = 0;
    for (char& c : s) {
        if (arr[c]) {
            arr[c]--;
            c = '\0';
            YAY++;
        } 
    }
    for (char c : s) {
        if (arr[flipCase(c)]) {
            arr[flipCase(c)]--;
            WHOOPS++;
        }
    }

    cout << YAY << ' ' << WHOOPS << '\n';
    
    return 0;
}

