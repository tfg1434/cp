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

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
int n, m;
string str;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        		cin>>n>>m;
		n++;
		m++;
		int mat[n][m];
		for(int i=1;i<n;i++)
		{
			cin>>str;
			for(int j=1;j<m;j++)
			{
				if(str[j-1]=='1')
					mat[i][j]=1;
				else
					mat[i][j]=0;
			}
		}
		vector<int>res;
		int cnt=0;
		for(int i=1;i<m-2;i++)
		{
			for(int j=1;j<n;j++)
			{
				if(j==n-1 && mat[j][i]==1)
				{
					mat[j][i]=0;
					mat[j][i+1]^=1;
					mat[j-1][i+1]^=1;
					res.push_back(j);
					res.push_back(i);
					res.push_back(j);
					res.push_back(i+1);
					res.push_back(j-1);
					res.push_back(i+1);
					cnt++;
				}
				else if(mat[j][i]==1)
				{
					mat[j][i]=0;
					mat[j][i+1]^=1;
					mat[j+1][i+1]^=1;
					res.push_back(j);
					res.push_back(i);
					res.push_back(j);
					res.push_back(i+1);
					res.push_back(j+1);
					res.push_back(i+1);
					cnt++;
				}
			}
		}
		for(int i=1;i<n-2;i++)
		{
			if(mat[i][m-2]==1)
			{
				mat[i][m-2]=0;
				mat[i+1][m-2]^=1;
				mat[i+1][m-1]^=1;
				res.push_back(i);
				res.push_back(m-2);
				res.push_back(i+1);
				res.push_back(m-2);
				res.push_back(i+1);
				res.push_back(m-1);
				cnt++;
			}
			if(mat[i][m-1]==1)
			{
				mat[i][m-1]=0;
				mat[i+1][m-1]^=1;
				mat[i+1][m-2]^=1; 
				res.push_back(i);
				res.push_back(m-1);
				res.push_back(i+1);
				res.push_back(m-1);
				res.push_back(i+1);
				res.push_back(m-2);
				cnt++;
			}
		}
		while(1)
		{
			if(mat[n-2][m-2]==0 && mat[n-1][m-2]==0 && mat[n-2][m-1]==0 && mat[n-1][m-1]==0)
			{
				break;
			}
			if(mat[n-2][m-2]==1 && mat[n-1][m-2]==1 && mat[n-2][m-1]==1 && mat[n-1][m-1]==1)
			{
				mat[n-2][m-2]=0;
				mat[n-1][m-2]=0;
				mat[n-2][m-1]=0;
				res.push_back(n-2);
				res.push_back(m-2);
				res.push_back(n-1);
				res.push_back(m-2);
				res.push_back(n-2);
				res.push_back(m-1);
				cnt++;
			}
			if(mat[n-2][m-2]==1 && mat[n-1][m-2]==1 && mat[n-2][m-1]==1 && mat[n-1][m-1]==0)
			{
				mat[n-2][m-2]=0;
				mat[n-1][m-2]=0;
				mat[n-2][m-1]=0;
				res.push_back(n-2);
				res.push_back(m-2);
				res.push_back(n-1);
				res.push_back(m-2);
				res.push_back(n-2);
				res.push_back(m-1);
				cnt++;
			}
			if(mat[n-2][m-2]==0 && mat[n-1][m-2]==1 && mat[n-2][m-1]==1 && mat[n-1][m-1]==1)
			{
				mat[n-1][m-1]=0;
				mat[n-1][m-2]=0;
				mat[n-2][m-1]=0;
				res.push_back(n-1);
				res.push_back(m-1);
				res.push_back(n-1);
				res.push_back(m-2);
				res.push_back(n-2);
				res.push_back(m-1);
				cnt++;
			}
			if(mat[n-2][m-2]==1 && mat[n-1][m-2]==0 && mat[n-2][m-1]==1 && mat[n-1][m-1]==1)
			{
				mat[n-2][m-2]=0;
				mat[n-1][m-1]=0;
				mat[n-2][m-1]=0;
				res.push_back(n-2);
				res.push_back(m-2);
				res.push_back(n-1);
				res.push_back(m-1);
				res.push_back(n-2);
				res.push_back(m-1);
				cnt++;
			}
			if(mat[n-2][m-2]==1 && mat[n-1][m-2]==1 && mat[n-2][m-1]==0 && mat[n-1][m-1]==1)
			{
				mat[n-2][m-2]=0;
				mat[n-1][m-2]=0;
				mat[n-1][m-1]=0;
				res.push_back(n-2);
				res.push_back(m-2);
				res.push_back(n-1);
				res.push_back(m-2);
				res.push_back(n-1);
				res.push_back(m-1);
				cnt++;
			}
			if(mat[n-2][m-2]==0 && mat[n-1][m-2]==0 && mat[n-2][m-1]==1 && mat[n-1][m-1]==1)
			{
				mat[n-1][m-1]=0;
				mat[n-1][m-2]=1;
				mat[n-2][m-2]=1;
				res.push_back(n-1);
				res.push_back(m-1);
				res.push_back(n-1);
				res.push_back(m-2);
				res.push_back(n-2);
				res.push_back(m-2);
				cnt++;
			}
			if(mat[n-2][m-2]==1 && mat[n-1][m-2]==1 && mat[n-2][m-1]==0 && mat[n-1][m-1]==0)
			{
				mat[n-2][m-2]=0;
				mat[n-2][m-1]=1;
				mat[n-1][m-1]=1;
				res.push_back(n-1);
				res.push_back(m-1);
				res.push_back(n-2);
				res.push_back(m-2);
				res.push_back(n-2);
				res.push_back(m-1);
				cnt++;
			}
			if(mat[n-2][m-2]==1 && mat[n-1][m-2]==0 && mat[n-2][m-1]==0 && mat[n-1][m-1]==1)
			{
				mat[n-2][m-2]=0;
				mat[n-2][m-1]=1;
				mat[n-1][m-2]=1;
				res.push_back(n-2);
				res.push_back(m-2);
				res.push_back(n-2);
				res.push_back(m-1);
				res.push_back(n-1);
				res.push_back(m-2);
				cnt++;
			}
			if(mat[n-2][m-2]==0 && mat[n-1][m-2]==1 && mat[n-2][m-1]==0 && mat[n-1][m-1]==1)
			{
				mat[n-2][m-2]=1;
				mat[n-2][m-1]=1;
				mat[n-1][m-1]=0;
				res.push_back(n-2);
				res.push_back(m-2);
				res.push_back(n-2);
				res.push_back(m-1);
				res.push_back(n-1);
				res.push_back(m-1);
				cnt++;
			}
			if(mat[n-2][m-2]==1 && mat[n-1][m-2]==0 && mat[n-2][m-1]==1 && mat[n-1][m-1]==0)
			{
				mat[n-2][m-2]=0;
				mat[n-1][m-2]=1;
				mat[n-1][m-1]=1;
				res.push_back(n-2);
				res.push_back(m-2);
				res.push_back(n-1);
				res.push_back(m-1);
				res.push_back(n-1);
				res.push_back(m-2);
				cnt++;
			}
			if(mat[n-2][m-2]==0 && mat[n-1][m-2]==1 && mat[n-2][m-1]==1 && mat[n-1][m-1]==0)
			{
				mat[n-2][m-2]=1;
				mat[n-2][m-1]=0;
				mat[n-1][m-1]=1;
				res.push_back(n-2);
				res.push_back(m-2);
				res.push_back(n-2);
				res.push_back(m-1);
				res.push_back(n-1);
				res.push_back(m-1);
				cnt++;
			}
			if(mat[n-2][m-2]==0 && mat[n-1][m-2]==0 && mat[n-2][m-1]==0 && mat[n-1][m-1]==1)
			{
				mat[n-2][m-2]=1;
				mat[n-2][m-1]=1;
				mat[n-1][m-1]=0;
				res.push_back(n-2);
				res.push_back(m-2);
				res.push_back(n-2);
				res.push_back(m-1);
				res.push_back(n-1);
				res.push_back(m-1);
				cnt++;
			}
			if(mat[n-2][m-2]==0 && mat[n-1][m-2]==0 && mat[n-2][m-1]==1 && mat[n-1][m-1]==0)
			{
				mat[n-2][m-2]=1;
				mat[n-2][m-1]=0;
				mat[n-1][m-1]=1;
				res.push_back(n-2);
				res.push_back(m-2);
				res.push_back(n-2);
				res.push_back(m-1);
				res.push_back(n-1);
				res.push_back(m-1);
				cnt++;
			}
			if(mat[n-2][m-2]==0 && mat[n-1][m-2]==1 && mat[n-2][m-1]==0 && mat[n-1][m-1]==0)
			{
				mat[n-2][m-2]=1;
				mat[n-1][m-2]=0;
				mat[n-1][m-1]=1;
				res.push_back(n-2);
				res.push_back(m-2);
				res.push_back(n-1);
				res.push_back(m-2);
				res.push_back(n-1);
				res.push_back(m-1);
				cnt++;
			}
			if(mat[n-2][m-2]==1 && mat[n-1][m-2]==0 && mat[n-2][m-1]==0 && mat[n-1][m-1]==0)
			{
				mat[n-2][m-2]=0;
				mat[n-1][m-2]=1;
				mat[n-1][m-1]=1;
				res.push_back(n-2);
				res.push_back(m-2);
				res.push_back(n-1);
				res.push_back(m-2);
				res.push_back(n-1);
				res.push_back(m-1);
				cnt++;
			}
		}
		cout<<cnt<<endl;
		for(int i=0;i<res.size();i+=6)
		{
			for(int j=i;j<i+6;j++)
			{
				cout<<res[j]<<" ";
			}
			cout<<endl;
		}
        // ll n, m; cin >> n >> m;
        // n++; m++;
        // vector<vector<int>> a(n, vector<int>(m));
        // for (ll i = 1; i < n; i++) {
            // string s; cin >> s;
            // for (ll j = 1; j < m; j++) {
                // a[i][j] = s[j-1] == '1'; 
            // }
        // }


        // vector<ll> ans;
        // ll cnt = 0;
        // /[>*****.
        // /[>*****.
        // /[>*****.
        // for (ll i = 1; i < m-2; i++) {
            // for (ll j = 1; j < n; j++) {
                // if (j == n-1 && a[j][i] == 1) {
                    // a[j][i] = 0;
                    // a[j][i+1] ^= 1;
                    // a[j-1][i+1] ^= 1;
                    // ans.push_back(j); ans.push_back(i);
                    // ans.push_back(j); ans.push_back(i+1);
                    // ans.push_back(j-1); ans.push_back(i+1);
                    // cnt++;

                // } else if (a[j][i] == 1) {
                    // a[j][i] = 0;
                    // a[j][i+1] ^= 1;
                    // a[j+1][i+1] ^= 1;
                    // ans.push_back(j); ans.push_back(i);
                    // ans.push_back(j); ans.push_back(i+1);
                    // ans.push_back(j+1); ans.push_back(i+1);
                    // cnt++;
                // }
            // }
        // }
        // /[>******
        // /[>******
        // /[>*****.
        // for (ll i = 1; i < n-2; i++) {
            // if (a[i][m-2] == 1) {
                // a[i][m-2] = 0;
                // a[i+1][m-2] ^= 1;
                // a[i+1][m-1] ^= 1;
                // ans.push_back(i); ans.push_back(m-2);
                // ans.push_back(i+1); ans.push_back(m-2);
                // ans.push_back(i+1); ans.push_back(m-1);
                // cnt++;
            // }
            // if (a[i][m-1] == 1) {
                // a[i][m-1] = 0;
                // a[i+1][m-1] ^= 1;
                // a[i+1][m-2] ^= 1; //itd flip our prev if, so do i+1
                // ans.push_back(i); ans.push_back(m-1);
                // ans.push_back(i+1); ans.push_back(m-1);
                // ans.push_back(i+1); ans.push_back(m-2);
                // cnt++;
            // }
        // }

        // //four squaans form a cycle
        // while (true) {
            // if (a[n-2][m-2] == 0 && a[n-1][m-2] == 0 && a[n-2][m-1] == 0 && a[n-1][m-1] == 0) 
                // break;
            // if (a[n-2][m-2] == 1 && a[n-1][m-2] == 1 && a[n-2][m-1] == 1 && a[n-1][m-1] == 1) {
                // a[n-2][m-2] = 0;
                // a[n-1][m-2] = 0;
                // a[n-2][m-1] = 0;
                // ans.push_back(n-2); ans.push_back(m-2);
                // ans.push_back(n-1); ans.push_back(m-2);
                // ans.push_back(n-1); ans.push_back(m-1);
                // cnt++;
            // }
                        // if(a[n-2][m-2]==1 && a[n-1][m-2]==1 && a[n-2][m-1]==1 && a[n-1][m-1]==0)
			// {
				// a[n-2][m-2]=0;
				// a[n-1][m-2]=0;
				// a[n-2][m-1]=0;
				// ans.push_back(n-2);
				// ans.push_back(m-2);
				// ans.push_back(n-1);
				// ans.push_back(m-2);
				// ans.push_back(n-2);
				// ans.push_back(m-1);
				// cnt++;
			// }
			// if(a[n-2][m-2]==0 && a[n-1][m-2]==1 && a[n-2][m-1]==1 && a[n-1][m-1]==1)
			// {
				// a[n-1][m-1]=0;
				// a[n-1][m-2]=0;
				// a[n-2][m-1]=0;
				// ans.push_back(n-1);
				// ans.push_back(m-1);
				// ans.push_back(n-1);
				// ans.push_back(m-2);
				// ans.push_back(n-2);
				// ans.push_back(m-1);
				// cnt++;
			// }
			// if(a[n-2][m-2]==1 && a[n-1][m-2]==0 && a[n-2][m-1]==1 && a[n-1][m-1]==1)
			// {
				// a[n-2][m-2]=0;
				// a[n-1][m-1]=0;
				// a[n-2][m-1]=0;
				// ans.push_back(n-2);
				// ans.push_back(m-2);
				// ans.push_back(n-1);
				// ans.push_back(m-1);
				// ans.push_back(n-2);
				// ans.push_back(m-1);
				// cnt++;
			// }
			// if(a[n-2][m-2]==1 && a[n-1][m-2]==1 && a[n-2][m-1]==0 && a[n-1][m-1]==1)
			// {
				// a[n-2][m-2]=0;
				// a[n-1][m-2]=0;
				// a[n-1][m-1]=0;
				// ans.push_back(n-2);
				// ans.push_back(m-2);
				// ans.push_back(n-1);
				// ans.push_back(m-2);
				// ans.push_back(n-1);
				// ans.push_back(m-1);
				// cnt++;
			// }
			// if(a[n-2][m-2]==0 && a[n-1][m-2]==0 && a[n-2][m-1]==1 && a[n-1][m-1]==1)
			// {
				// a[n-1][m-1]=0;
				// a[n-1][m-2]=1;
				// a[n-2][m-2]=1;
				// ans.push_back(n-1);
				// ans.push_back(m-1);
				// ans.push_back(n-1);
				// ans.push_back(m-2);
				// ans.push_back(n-2);
				// ans.push_back(m-2);
				// cnt++;
			// }
			// if(a[n-2][m-2]==1 && a[n-1][m-2]==1 && a[n-2][m-1]==0 && a[n-1][m-1]==0)
			// {
				// a[n-2][m-2]=0;
				// a[n-2][m-1]=1;
				// a[n-1][m-1]=1;
				// ans.push_back(n-1);
				// ans.push_back(m-1);
				// ans.push_back(n-2);
				// ans.push_back(m-2);
				// ans.push_back(n-2);
				// ans.push_back(m-1);
				// cnt++;
			// }
			// if(a[n-2][m-2]==1 && a[n-1][m-2]==0 && a[n-2][m-1]==0 && a[n-1][m-1]==1)
			// {
				// a[n-2][m-2]=0;
				// a[n-2][m-1]=1;
				// a[n-1][m-2]=1;
				// ans.push_back(n-2);
				// ans.push_back(m-2);
				// ans.push_back(n-2);
				// ans.push_back(m-1);
				// ans.push_back(n-1);
				// ans.push_back(m-2);
				// cnt++;
			// }
			// if(a[n-2][m-2]==0 && a[n-1][m-2]==1 && a[n-2][m-1]==0 && a[n-1][m-1]==1)
			// {
				// a[n-2][m-2]=1;
				// a[n-2][m-1]=1;
				// a[n-1][m-1]=0;
				// ans.push_back(n-2);
				// ans.push_back(m-2);
				// ans.push_back(n-2);
				// ans.push_back(m-1);
				// ans.push_back(n-1);
				// ans.push_back(m-1);
				// cnt++;
			// }
			// if(a[n-2][m-2]==1 && a[n-1][m-2]==0 && a[n-2][m-1]==1 && a[n-1][m-1]==0)
			// {
				// a[n-2][m-2]=0;
				// a[n-1][m-2]=1;
				// a[n-1][m-1]=1;
				// ans.push_back(n-2);
				// ans.push_back(m-2);
				// ans.push_back(n-1);
				// ans.push_back(m-1);
				// ans.push_back(n-1);
				// ans.push_back(m-2);
				// cnt++;
			// }
			// if(a[n-2][m-2]==0 && a[n-1][m-2]==1 && a[n-2][m-1]==1 && a[n-1][m-1]==0)
			// {
				// a[n-2][m-2]=1;
				// a[n-2][m-1]=0;
				// a[n-1][m-1]=1;
				// ans.push_back(n-2);
				// ans.push_back(m-2);
				// ans.push_back(n-2);
				// ans.push_back(m-1);
				// ans.push_back(n-1);
				// ans.push_back(m-1);
				// cnt++;
			// }
			// if(a[n-2][m-2]==0 && a[n-1][m-2]==0 && a[n-2][m-1]==0 && a[n-1][m-1]==1)
			// {
				// a[n-2][m-2]=1;
				// a[n-2][m-1]=1;
				// a[n-1][m-1]=0;
				// ans.push_back(n-2);
				// ans.push_back(m-2);
				// ans.push_back(n-2);
				// ans.push_back(m-1);
				// ans.push_back(n-1);
				// ans.push_back(m-1);
				// cnt++;
			// }
			// if(a[n-2][m-2]==0 && a[n-1][m-2]==0 && a[n-2][m-1]==1 && a[n-1][m-1]==0)
			// {
				// a[n-2][m-2]=1;
				// a[n-2][m-1]=0;
				// a[n-1][m-1]=1;
				// ans.push_back(n-2);
				// ans.push_back(m-2);
				// ans.push_back(n-2);
				// ans.push_back(m-1);
				// ans.push_back(n-1);
				// ans.push_back(m-1);
				// cnt++;
			// }
			// if(a[n-2][m-2]==0 && a[n-1][m-2]==1 && a[n-2][m-1]==0 && a[n-1][m-1]==0)
			// {
				// a[n-2][m-2]=1;
				// a[n-1][m-2]=0;
				// a[n-1][m-1]=1;
				// ans.push_back(n-2);
				// ans.push_back(m-2);
				// ans.push_back(n-1);
				// ans.push_back(m-2);
				// ans.push_back(n-1);
				// ans.push_back(m-1);
				// cnt++;
			// }
			// if(a[n-2][m-2]==1 && a[n-1][m-2]==0 && a[n-2][m-1]==0 && a[n-1][m-1]==0)
			// {
				// a[n-2][m-2]=0;
				// a[n-1][m-2]=1;
				// a[n-1][m-1]=1;
				// ans.push_back(n-2);
				// ans.push_back(m-2);
				// ans.push_back(n-1);
				// ans.push_back(m-2);
				// ans.push_back(n-1);
				// ans.push_back(m-1);
				// cnt++;
			// }
        // }

        // cout << cnt << endl;
        // for (int i = 0; i < ans.size(); i += 6) {
            // for (int j = i; j < i + 6; j++) {
                // cout << ans[j] << " ";
            // }
            // cout << endl;
        // }
    }    
    
    return 0;
}

