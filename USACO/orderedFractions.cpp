/*
ID: toronto4
TASK: frac1
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N;

struct Frac {
    double num, den;
    
    double dec() const {
        return num / den;
    }
};

int gcd(int a, int b){
    if (b == 0) return a;
    
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    
    cin >> N;
    Frac temp;
    vector<Frac> ans;
    
    for (int n = 1; n <= N; ++n) {
        for (int d = N; d > 0; --d) {
            if (n == 1) {
                temp.num = n;
                temp.den = d;
                ans.push_back(temp);
                
            } else {
                if (n / d < 1 && gcd(n, d) == 1) {
                    temp.num = n;
                    temp.den = d;
                    ans.push_back(temp);
                }
            }
        }
    }

    sort(ans.begin(), ans.end(), [](const Frac &a, const Frac &b) {
        double n1, d1, n2, d2;
        
        n1 = a.num;
        d1 = a.den;
        n2 = b.num;
        d2 = b.den;
        
        return d1 / n1 > d2 / n2;
    });
    
    cout << "0/1" << '\n';

    for (Frac frac:ans) {
        cout << frac.num << "/" << frac.den << '\n';
    }
    
    return 0;
}
