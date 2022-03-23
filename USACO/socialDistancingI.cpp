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


int largestInGap(string s, int& start) {
    int res = 0, curr = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            if (curr != -1 && i - curr > res) {
                res = i - curr;
                start = curr;
            }
        }
        curr = i;
    }

    return res;
}

int smolInGap(string s) {
    int res = INF, curr = -1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '1') {
            if (curr != -1 && i - curr < res) res = i - curr;
            curr = i;
        }
    }

    return res;
}

int tryLargeGap(string s) {
    int l, gap = largestInGap(s, l);
    if (gap >= 2) {
        s[l + gap/2] = '1';
        return smolInGap(s);
    }

    return -1; 
}

int main() {
    // freopen("socdist1.in", "r", stdin);
    // freopen("socdist1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    string s, copy; cin >> s;
    int ans = 0;

    //case 1: two cows in biggest gap
    int l, gap = largestInGap(s, l);
    if (gap >= 3) {
        copy = s;
        copy[l + gap/3] = '1';
        copy[l + gap*2/3] = '1';
        ans = max(ans, smolInGap(copy));
    }
    //case 2: cows at both ends
    if (s[0] == '0' && s[n-1] == '0') {
        copy = s; copy[0] = copy[n-1] = '1';
        ans = max(ans, smolInGap(copy));
    }
    //case 3: one cow at left end
    if (s[0] == '0') {
        copy = s; copy[0] = '1';
        ans = max(ans, tryLargeGap(copy));
    }
    //case 4: one cow at right end
    if (s[n-1] == '0') {
        copy = s; copy[n-1] = '1';
        ans = max(ans, tryLargeGap(copy));
    }
    //case 5: both cows in diff interior gaps
    if (gap >= 2) {
        copy = s; copy[l + gap/2] = '1';
        ans = max(ans, tryLargeGap(copy));
    }

    cout << ans << endl;

    // vector<int> gaps;
    // int gap = 0;
    // for (char c : s) {
        // if (c == '0') gap++;
        // else {
            // gaps.push_back(gap);
            // gap = 0;
        // }
    // }
    // if (gap > 0) gaps.push_back(gap+1);
    // if (s[0] == '0') gaps[0]++;

    // int ans = 0;
    // ans = max({ ans, (gaps.back() - 1) / 2, gaps[gaps.size() - 2] / 2 });
    // ans = max(ans, (gaps.back() - 2) / 3);

    // cout << ans << endl;
    
    return 0;
}

