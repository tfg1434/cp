#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    unsigned t; cin>>t;
    while (t--) {
        unsigned n,m; cin>>n>>m;

        vector<unsigned> a(n);
        for (unsigned& x: a) cin>>x;
        sort(a.begin(), a.end());
        unsigned max_a=a[n-1];

        vector<vector<unsigned>> m_divs(max_a+1, vector<unsigned>());
        for (unsigned i=2; i<=m; i++) {
            for (unsigned j=i; j<=max_a; j+=i) m_divs[j].push_back(i);
        }

        vector<vector<unsigned>> setvec(m+1);
        for (unsigned i=0; i<n; i++) {
            for (unsigned j: m_divs[a[i]]) setvec[j].push_back(i);
        }

        unsigned max_elem=a[0];

        vector<bool> is_iter(n, false);
        vector<vector<unsigned>::iterator> iters(m+1);
        bool bad=false;
        for (unsigned i=2; i<=m; i++) {
            iters[i]=setvec[i].begin();
            if (iters[i]==setvec[i].end()) {cout<<"-1\n"; bad=true; break;}
            is_iter[*iters[i]]=true;
            max_elem=max(max_elem, a[*iters[i]]);
        }

        if (bad) continue;

        unsigned min_diff=max_elem-a[0];

        for (unsigned min_i=0; min_i<n-1; min_i++) {
            if (is_iter[min_i]) {
                bool end=false;
                for (unsigned j: m_divs[a[min_i]]) {
                    iters[j]++;
                    if (iters[j]==setvec[j].end()) {end=true; break;}

                    is_iter[*iters[j]]=true;
                    max_elem=max(max_elem, a[*iters[j]]);
                }

                if (end) break;
            }

            min_diff=min(min_diff, max_elem-a[min_i+1]);
        }

        cout<<min_diff<<"\n";
    }
}
