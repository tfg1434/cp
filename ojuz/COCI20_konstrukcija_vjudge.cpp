    #include <bits/stdc++.h>
    using namespace std;
     
    using ll  = long long;
    using pii = pair<int, int>;
     
    #define fi first
    #define se second
     
    const int maxN  = 1'023;
     
    ll K;
    bool neg = false;
    int N, M;
    vector<pii> edges;
     
    int main() {
        scanf("%lld", &K);
        if (K == 0) {
            printf("3 2\n");
            printf("1 2\n");
            printf("2 3\n");
            exit(0);
        }
     
        edges.push_back({1, 2});
        edges.push_back({1, 3});
        vector<int> lst = {2, 3};
     
        if (K < 0) {
            neg = true;
            K *= -1;
        }
        vector<int> bt;
        while (K > 1) {
            if (K & 1ll) bt.push_back(1);
            bt.push_back(2);
            K >>= 1;
        }
        reverse(bt.begin(), bt.end());
     
        auto convolve = [&](int k) {
            vector<int> nw(k);
            iota(nw.begin(), nw.end(), N+1);
            N += k;
            for (auto i : lst) {
                for (auto j : nw) {
                    edges.push_back({i, j});
                }
            }        
            swap(lst, nw);
        };
     
        N = 3;
        for (auto i : bt) {
            if (i == 1) {
                // add 1
                N++;
                edges.push_back({1, N});
                lst.push_back(N);
            } else {
                // multiply by 2
                convolve(3);
                convolve(2);
            }
        }
     
        if (neg) convolve(2);
     
        N++;
        for (auto i : lst) edges.push_back({i, N});
     
        M = edges.size();
     
        printf("%d %d\n", N, M);
        for (auto [u, v] : edges) {
            printf("%d %d\n", u, v);
        }
    }
