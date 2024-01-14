#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);; cin.tie(NULL)
long long gcd(long long a, long long b){
    return (b == 0 ? a : gcd(b, a % b));
}
void selfMax(long long& a, long long b){
    a = max(a, b);
}
void selfMin(long long& a, long long b){
    a = min(a, b);
}
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for(auto &x : a) in >> x; return in;};
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.first >> x.second;}

template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.first << ' ' << x.second;}
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for(auto &x : a) out << x << ' '; return out;};
template<typename T> ostream& operator<<(ostream& out, vector<vector<T> >& a) {for(auto &x : a) out << x << '\n'; return out;};
template<typename T1, typename T2> ostream& operator<<(ostream& out, vector<pair<T1, T2> >& a) {for(auto &x : a) out << x << '\n'; return out;};

/*

Use DSU dsu(N);

*/
struct DSU {
    vector<long long> adj2;
    DSU(long long N) { adj2 = vector<long long>(N, -1); }

    // get representive component (uses path compression)
    long long get(long long x) { return adj2[x] < 0 ? x : adj2[x] = get(adj2[x]); }

    bool same_set(long long a, long long b) { return get(a) == get(b); }

    long long size(long long x) { return -adj2[get(x)]; }

    bool unite(long long x, long long y) {  // union by size
        x = get(x), y = get(y);
        if (x == y) return false;
        if (adj2[x] > adj2[y]) swap(x, y);
        adj2[x] += adj2[y]; adj2[y] = x;
        return true;
    }
};
/*

Run with Bit<long long> BIT

*/
template <class T> class BIT {
    private:
        long long size;
        vector<T> bit;
        vector<T> arr;
    public:
        BIT(long long size) : size(size), bit(size + 1), arr(size) {}
        void set(long long ind, long long val) { add(ind, val - arr[ind]); }
        void add(long long ind, long long val) {
            arr[ind] += val;
            ind++;
            for (; ind <= size; ind += ind & -ind) { bit[ind] += val; }
        }
        T pref_sum(long long ind) {
            ind++;
            T total = 0;
            for (; ind > 0; ind -= ind & -ind) { total += bit[ind]; }
            return total;
        }
};
/*

Change Comb for specific Seg tree probs, but run with Seg<long long> Seg;

*/
template<class T> struct Seg {
    const T ID = 1e18; T comb(T a, T b) { return min(a,b); }
    long long n; vector<T> seg;
    void init(long long _n) { n = _n; seg.assign(2*n,ID); }
    void pull(long long p) { seg[p] = comb(seg[2*p],seg[2*p+1]); }
    void upd(long long p, T val) {
        seg[p += n] = val; for (p /= 2; p; p /= 2) pull(p); }
    T query(long long l, long long r) {
        T ra = ID, rb = ID;
        for (l += n, r += n+1; l < r; l /= 2, r /= 2) {
            if (l&1) ra = comb(ra,seg[l++]);
            if (r&1) rb = comb(seg[--r],rb);
        }
        return comb(ra,rb);
    }
};
const long long MOD = 1000003;
long long fact[1000005], inv[1000005];
long long pw(long long b, long long e){
	long long ans = 1;
	while(e){
		if(e & 1){
			ans = (ans * b) % MOD;
        }
		b = (b * b) % MOD;
		e >>= 1;
	}

	return ans;
}
int main(){
    fact[0] = 1;
    for(long long i = 1; i <= MOD; i++){
        fact[i] = fact[i - 1] * i;
        fact[i] %= MOD;
    }
    inv[MOD - 1] = pw(fact[MOD - 1], MOD - 2);
    for(long long i = MOD - 2; i >= 0; i--){
        inv[i] = inv[i + 1] * (i + 1);
        inv[i] %= MOD;
    }
    long long n, q;
    cin >> n >> q;
    vector<pair<long long, long long> > v;
    v.push_back(make_pair(n, 0));
    v.push_back(make_pair(0, 0));
    while(q--){
        long long x, y;
        cin >> x >> y;
        v.push_back(make_pair(x - 1, 0));
        v.push_back(make_pair(y, x - 1));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    set<long long> s;
    long long ans = 1;
    for(long long i = 0; i < v.size() - 1; i++){
        s.insert(v[i].second);
        if(v[i].first != v[i + 1].first){
            auto it = s.lower_bound(v[i].first);
            it--;
            long long n2 = v[i].first - (*it);
            long long k2 = v[i].first - v[i + 1].first;
            n2 %= MOD;
            if(n2 < k2){
                ans = 0;
                continue;
            }
            ans = ans * (fact[n2] * inv[n2 - k2]) % MOD;
            ans %= MOD;
        }
    }
    cout << ans << "\n";
}
