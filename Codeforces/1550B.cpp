#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


int countSubstring(const std::string& str, const std::string& sub)
{
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
     offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n, a, b; cin >> n >> a >> b;
        string s; cin >> s;

        if (b >= 0) {
            cout << n * a + n * b << '\n';
            continue;
        }

        int ops = max(countSubstring(s, "01"), countSubstring(s, "10")) + 1;

        cout << a * n + b * ops << '\n';
    }    
    
    return 0;
}

