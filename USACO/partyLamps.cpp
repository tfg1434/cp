/*
ID: toronto4
TASK: lamps 
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr int max_lamp = 6;
// right six bits
constexpr int lamp_mask = (1 << max_lamp) - 1;
int N, C;
int lamps[1 << max_lamp];
int on;
int given;

int flip[4] = {
        lamp_mask,
        lamp_mask & 0b10101010,
        lamp_mask & 0b01010101,
        lamp_mask & ((1 << (max_lamp - 1)) | (1 << (max_lamp - 4))),
};

void solve(int state, int i, int n) {
    if (n == 0) {
        if ((state & given) == on)
            lamps[state] = 1;
        
        return;
    }

    for ( ; i < 4; ++i )
        solve(state ^ flip[i], i, n - 1);
}

void print(int lights) {
    char s[100+1];

    for (int i = 0; i < N; ++i) 
       s[i] = (lights & (1 << (max_lamp - 1 - i % max_lamp))) ? '1' : '0'; 
    
    s[N] = '\0';
    cout << s << '\n';
}

int main() {
    freopen("lamps.in", "r", stdin);
    freopen("lamps.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> C;

    while (true) {
        int a; 
        cin >> a;
        if (a == -1) break;
        a = max_lamp - 1 - (a - 1) % max_lamp;
        
        on |= 1 << a;
        given |= 1 << a;
    }
    
    while (true) {
        int a; 
        cin >> a;
        if (a == -1) break;
        a = max_lamp - 1 - (a - 1) % max_lamp;

        //shift the one bit to the correct position
        assert((on & (1 << a)) == 0);
        given |= 1 << a;
    }
    
    if (C > 4) {
        if (C % 2 == 0) C = 4;
        else C = 3;
    }

    for ( ; C >= 0; C -= 2) 
        solve(lamp_mask, 0, C);
    
    bool impossible = true;
    for (int i = 0; i < (1 << max_lamp); ++i) {
        if (lamps[i]) {
            impossible = false;
            print(i);
        }
    }
    
    if (impossible) cout << "IMPOSSIBLE" << '\n';
    
    return 0;
}
