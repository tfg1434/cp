#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;
pair<int, int> b[200005];
int i, j;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int num[200005] = {0}, sum[200005] = {0};
        int n, k;
        cin >> n >> k;
        for (i = 0, j = 0; i < n; i++) {
            int x;
            cin >> x;
            if (num[x] < k) {
                num[x]++;
                b[j++] = make_pair(x, i);
            }
        }
        sort(b, b + j);
        //make the painted divisible by k
        j -= j % k;
        for (i = 0; i < j; i++)
            sum[b[i].second] = i % k + 1;
        for (i = 0; i < n; i++)
            cout << sum[i] << " ";
        cout << endl;
    }

    return 0;
}

