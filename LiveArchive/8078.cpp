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
string s;


char flip(char s) {
    if (s == '(') return ')';
    //stupid hack
    return s + 2;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int test = 0;
    int T; cin >> T; while (T-- && ++test) {
        cin >> s;
        //last is always 0
        cout << "Case " << test << ":" << endl;
        stack<char> stak;
        stack<int> ans, track;
        for (int i=s.size()-1,k=0,l=1; i>=0; i--,k=0,l++) {
            if (stak.empty()) {
                stak.push(s[i]);
                track.push(i);
                ans.push(0);
            } else {
                char c = stak.top();
                if (s[i] == '(' && c == ')') stak.pop(), track.pop();
                else if (s[i] == '{' && c == '}') stak.pop(), track.pop();
                else if (s[i] == '[' && c == ']') stak.pop(), track.pop();
                else if (s[i] == '<' && c == '>') stak.pop(), track.pop();
                else {
                    stak.push(s[i]);
                    track.push(i);
                    ans.push(0);
                    k = 1;
                }

                if (k == 0) {
                    if (track.empty()) ans.push(l);
                    else ans.push(track.top() - i);
                }
            }
        }
        while (!ans.empty()) {
            cout << ans.top() << "\n";
            ans.pop();
        }

        // for (int i = 0; i < s.size(); i++) {
            // stack<char> st;
            // int j = i;
            // bool ok = true;
            // while (true) {
                // if (s[j] == '(' || s[j] == '{' || s[j] == '[' || s[j] == '<') {
                    // st.push(s[j]);
                // } else {
                    // if (st.size() == 0) break;
                    // if (s[j] == flip(st.top())) {
                        // st.pop();
                    // } else {
                        // break;
                    // }
                // }
                // j++;
            // }

            // cout << j << endl;
        // }
    }    
    
    return 0;
}

