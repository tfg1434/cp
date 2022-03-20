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
int rev[] = { 0, 1, 5, -1, -1, 2, -1, -1, 8, -1 };


int flip(int x) {
    string s = to_string(x);
    if ((int)s.size() == 1) s = "0" + s;
    string res = "";
    for (int i = 1; i >= 0; i--) {
        if (rev[s[i] - '0'] == -1) return INF;
        res += char(rev[s[i] - '0'] + '0');
    }

    return stoi(res);
}

string pad(int x) {
    string res = to_string(x);
    if (x < 10) res = "0" + res;

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        int H, M; cin >> H >> M;
        string s; cin >> s;
        int hr = (s[0] - '0') * 10 + (s[1] - '0');
        int min = (s[3] - '0') * 10 + (s[4] - '0');
        int hrFirst = hr, minFirst = min;

        while (true) {
            if (min == M) hr++, min = 0;
            if (hr == H) hr = 0;

            //swapped H and M, because hours and minutes are swapped
            if (flip(min) < H && flip(hr) < M) {
                cout << pad(hr) << ":" << pad(min) << endl;
                break;
            }
            min++;
        }
    }    
    
    return 0;
}

