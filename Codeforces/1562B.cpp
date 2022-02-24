#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;
bool isPrime[100];
int n;
string s;


void solve() {
    for (auto c : s) {
        if (c == '1' || c == '4' || c == '6' || c == '8' || c == '9') {
            cout << 1 << '\n';
            cout << c << '\n';
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (!isPrime[(s[i]-'0')*10 + s[j]-'0']) {
                cout << 2 << '\n';
                cout << s[i] << s[j] << '\n';
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < 100; i++) {
        isPrime[i] = true;
        for (int j = 2; j * j <= i; j++)
            if (i % j == 0) isPrime[i] = false;
    }
    
    cin >> T;
    while (T--) {
        cin >> n >> s;
        solve(); 
    }    
    
    return 0;
}

