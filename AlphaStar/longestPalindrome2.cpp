#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

char s[20000], ss[20000];
    int slen, sslen;
    int maxp, maxq, maxl = 0;
     
    int findpal (int p, int q) {
        int i, j;
        while (ss[p] == ss[q] && p >= 0 && q < sslen) {
            i = p;
            j = q;
            p--;
            q++;
        }
        if (j - i + 1 > maxl)
        {
            maxp = i;
            maxq = j;
            maxl = j - i + 1;
        }
    }
     
   int main() {
        char c;
      slen = 0;
        sslen = 0;
         
      while (cin.get(c)) {
            s[slen] = c;
            slen++;
            if (isalpha(c)) {
                ss[sslen] = tolower(c);
                sslen++;
            }
        }
         
        for (int i = 1; i < sslen; i++) {
            //odd palindrome
            findpal (i - 1, i + 1);
            //even palindrome
            findpal (i - 1, i);
        }
         
        string output = "";
        int alpha = -1;
         
        for (int i = 0; i < slen && maxq >= alpha + 1; i++) {
            if (isalpha (s[i]))
                alpha++;
            if (maxp <= alpha && maxq >= alpha)
                output += s[i];
        }
         
        cout << maxl << endl;
        cout << output << endl;
    
      return 0;
    
   }

