#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define ll long long 

struct SegmentTree{
    vector<ll> tree;
    ll n;
    SegmentTree(ll N){
        n = N;
        tree.assign(4 * N + 5, 0);
    }
    ll query(ll node, ll tl, ll tr, ll ql, ll qr) {
        if (ql > qr) 
            // this is a invalid range so
            return 0; // for sum,gcd return -> 0, for minimum return -> 1e18, for maximum in a range return -> -1e18
        if (ql == tl && qr == tr) {
            return tree[node];
        }
        ll tm = (tl + tr) / 2;
        ll left = query(node * 2, tl, tm, ql, min(qr, tm));
        ll right = query(node * 2 + 1, tm+1, tr, max(ql, tm+1), qr);

        return left + right; // sum
    }    
    
    void update(ll node, ll tl, ll tr, ll pos, ll new_val) {
        if (tl == tr) {
            tree[node] = new_val;
        } else {
            ll tm = (tl + tr) / 2;
            if (pos <= tm) //  go to the left side
                update(node * 2, tl, tm, pos, new_val);
            else // go to the right side
                update(node * 2 + 1, tm + 1, tr, pos, new_val);

            tree[node] = tree[node * 2] + tree[node * 2 + 1]; // sum
        }
    }

    // do function overloading to make query syntax easier
    ll query(ll l, ll r){ 
        return query(1, 0, n - 1, l, r);
    }

    void update(ll pos, ll new_val){
        update(1, 0, n - 1, pos, new_val);
    }

};


signed main(){
    ll n, q; cin >> n >> q;
    vector<ll> arr(n);

    for(ll i = 0; i < n; i++) cin >> arr[i];

    // usage 
    SegmentTree tree(n + 5);

    for(ll i = 0; i < n; i++) tree.update(i,arr[i]);

    for(ll i = 0; i < q; i++){
        ll l , r; cin >> l >> r; // assuming zero based 
        cout << tree.query(l,r) << endl;
    }

    // Bonus : 2D segment tree

    //ll k; cin >> k;
    // vector<SegmentTree > Tree (k + 1, SegmentTree(n + 5));


}

















