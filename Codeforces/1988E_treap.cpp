// spent a long long time on it (15:15 in CT in the plane)
// i didn't realise that you can just directly maintain this value
// in each treap node.
// 
// Lemma. We only visit each node twice
// See the video. It relies on the fact that there is a unique node v for
// which u is in the right chain of v's left child; you can find it by
// going up the parent and seeing where it turns right the first time
//
// - always write treap w/o fast erase first, then add it later
// - the nodes which come before u are those which are in u's left
//   subtree, or the subtrees of ancestors of u (but not ancestors)
// - trust your gut on treap at this point
// - reviewed when to pull (mainly) and push; you need to pull both in
//   fast erase and fast insert even though split and merge already do
// the reason is because ... but i can't justify it
//  

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

const int N = 5e5, LOG = 19;
struct Node {
    int y, l, r, siz, sms;
    Node() {}
    Node(int y) : y(y), l(-1), r(-1), siz(1), sms(y) {}
} t[N+LOG*N];
int tree_siz;

int siz(int v) {
    return v == -1 ? 0 : t[v].siz;
}
int sms(int v) {
    return v == -1 ? 0 : t[v].sms;
}

void pull(int v) {
    if (v != -1) {
        t[v].siz = 1+siz(t[v].l)+siz(t[v].r);
        t[v].sms = sms(t[v].l)+sms(t[v].r) + (siz(t[v].l)+1)*(siz(t[v].r)+1)*t[v].y;
    }
}


    // void merge(int& v, int l, int r) { 
        // if (l == -1) return void(v=r);
        // if (r == -1) return void(v=l);
        // if (t[l].y < t[r].y) {
            // merge(t[l].r, t[l].r, r);
            // v = l;
        // } else {
            // merge(t[r].l, l, t[r].l);
            // v = r;
        // }
        // pull(v);
    // }
    // void split(int v, int X, int& l, int& r) {
        // if (v == -1) return void(l=r=-1);
        // if (siz(t[v].l) < X) {
            // split(t[v].r, X-siz(t[v].l)-1, t[v].r, r);
            // l = v;
        // } else {
            // split(t[v].l, X, l, t[v].l);
            // r = v;
        // }
        // pull(v);
    // }
void split(int v, int x, int& l, int& r) {
    if (v == -1) {
        return void(l=r=-1);
    }
    if (siz(t[v].l) < x) {
        split(t[v].r, x-siz(t[v].l)-1, t[v].r, r); // * had +1 instead of -1
        l = v;
    } else {
        split(t[v].l, x, l, t[v].l);
        r = v;
    }
    pull(v);
}

void merge(int& v, int l, int r) {
    if (l == -1) return void(v=r);
    if (r == -1) return void(v=l);
    if (t[l].y < t[r].y) {
        merge(t[l].r, t[l].r, r);
        v = l;
    } else {
        merge(t[r].l, l, t[r].l);
        v = r;
    }
    pull(v);
}

void fast_erase(int& v, int x) {
    // int A, B, C;
    // split(v, x, A, B);
    // split(B, 1, B, C);
    // merge(v, A, C);
    if (siz(t[v].l) == x) {
        merge(v, t[v].l, t[v].r);
        return;
    }
    if (siz(t[v].l) < x) {
        fast_erase(t[v].r, x-siz(t[v].l)-1);
    } else {
        fast_erase(t[v].l, x);
    }
    pull(v); // forgot!
}

// void insert (pitem & t, pitem it) {
    // if (!t)
        // t = it;
    // else if (it->prior < t->prior)
        // split (t, it->key, it->l, it->r),  t = it;
    // else
        // insert (t->key >= it->key ? t->r : t->l, it);
// }

void fast_insert(int& v, int x, int y) {
    if (v == -1) {
        v = tree_siz++;
        t[v] = Node(y);
        return;
    }
    // int A, B;
    // split(v, x, A, B);
    // int u = tree_siz++;
    // t[u] = Node(y);
    // merge(A, A, u);
    // merge(v, A, B);
    // return;
    if (y < t[v].y) {
        int u = tree_siz++;
        t[u] = Node(y);
        split(v, x, t[u].l, t[u].r);
        v = u;
        pull(v);
    } else {
        // if (t[v].l != -1) pull(t[v].l);      i think it's not needed
        // if (t[v].r != -1) pull(t[v].r);
        if (siz(t[v].l) < x) {
            fast_insert(t[v].r, x-siz(t[v].l)-1, y);
        } else {
            fast_insert(t[v].l, x, y);
        }
        pull(v);
    }
}

void print(int v) {
    if (v == -1) return;
    print(t[v].l);
    cout << t[v].y << ' ';
    print(t[v].r);
}

void solve() {
    int n; cin >> n;
    vi p(n);
    int root = -1;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        fast_insert(root, i, p[i]);
    }

    // 3 1 0 4 2
    vi ans(n);
    for (int i = 0; i < n; i++) {
        // print(root); ps();
        // ps("erase", i);

        fast_erase(root, i);

        // print(root); ps();

        ans[i] = sms(root);

        // ps("replace", i);
        fast_insert(root, i, p[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i==n-1];
    }

    while (tree_siz > 0) {
        tree_siz--;
        // t[tree_siz] = Node(); // necessary?
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

