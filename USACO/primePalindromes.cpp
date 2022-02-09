/*
ID: toronto4
TASK: pprime
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n < 2) return false;
    if (n <= 3) return true;
    if (n%2 == 0 || n%3 ==0) return false;
    for (int i = 5; i*i <= n; i++)
        if (n %i ==0) return false;
    return true;
}

set<int> ans;

void genPalin(int size) {
    bool isOdd = size % 2;
    int half = isOdd ? (size - 1) / 2 : size / 2;
    int low = pow(10, half - 1), high = pow(10, half) - 1;
    int num;

    for (int n = low; n <= high; n++) {

        string a = to_string(n);
        string b(a);
        reverse(b.begin(), b.end());

        if (!isOdd) {
            a += b;
            num = stoi(a);
            if (isPrime(num))
                ans.insert(num);
        } else {
            for (int i = 0; i < 10; i++) {
                string s = a + to_string(i) + b;
                num = stoi(s);
                if (isPrime(num))
                    ans.insert(num);
            }
        }
    }
}

int main() {
    freopen("pprime.in", "r", stdin);
    freopen("pprime.out", "w", stdout);

    int a, b;
    cin >> a >> b;
    
    ans.insert(5); 
    ans.insert(7);

    for (int i = 1; i < 9; i++)
        genPalin(i);

    for (auto n : ans) {
        if (n > b)
            break;
        if (n >= a)
            cout << n << '\n';
    }

    return 0;
}

//#define ll long long
//
//int main() {
//    freopen("pprime.in", "r", stdin);
//    freopen("pprime.out", "w", stdout);
//    ios::sync_with_stdio(0);
//    cin.tie(0);
//
//    int A, B;
//    cin >> A >> B;
//    int* isPrime = new int[B];
//
//    for (int i = 2; i*i < B; ++i) {
//        if (!isPrime[i]) continue;
//        for (int j = i*i; j < B; j += i)
//            isPrime[j] = false;
//
//    }
//
//    for (int i = A; i < B; ++i) {
//        if (!isPrime[i]) continue;
//
//        int digit;
//        int rev = 0;
//        int n = i;
//
//        do {
//            digit = n % 10;
//            rev = (rev * 10) + digit;
//            n = n / 10;
//        } while (n != 0);
//
//        if (i == rev) cout << i << '\n';
//    }
//
//    delete[] isPrime;
//    return 0;
//}

