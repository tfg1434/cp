#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bitset>
using namespace std;
#define endl '\n'
#define ll long long
#define pi pair<int, int>
#define f first
#define s second

const int mxn = 100001, w = 60;
int n;
ll a[mxn], f[mxn], dpl[mxn], dpr[mxn];

ll kek(int x, int y){
	return a[y] ^ a[x - 1];
}

// find msb of xor(x..y)
ll moo(int x, int y){
	ll z = kek(x, y);
	return z ? (1ll << __lg(z)) : (1ll << w);
}

void answer(){
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		a[i] ^= a[i - 1];
		
		dpl[i] = dpr[i] = 0;
	}
	
    // you can reach l..r iff msb(a(l..r)) \in dpl[l]
	dpl[1] = dpr[n] = moo(1, n);
	for(int i = n - 1; i >= 1; i--)
	for(int j = i; j <= n; j++){
		int x = j - i + 1, y = j;
		ll z = (1ll << w) | kek(x, y); // msb of a(x..y)
		
		bool t = 0;
		if(z & dpl[x]) t = 1;
		if(z & dpr[y]) t = 1;
		
		if(t){
			dpl[x] |= moo(x, y);
			dpr[y] |= moo(x, y);
		}
		
		if(i == 1) f[j] = t;
	}
	
	if(n == 1) f[1] = 1;
	
	for(int i = 1; i <= n; i++) cout << f[i];
	cout << endl;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t = 1;
	cin >> t;
	
	for(int i = 0; i < t; i++) answer();
	
	return 0;
}
