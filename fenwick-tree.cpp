
#include "bits/stdc++.h"
#include <random>
using namespace std; 
using ll = long long;
//macros
#define fi first
#define se second
#define ld long double
#define all(arr) arr.begin(), arr.end()
#define pb push_back
 
struct FenwickTree {
    vector<ll> bit;  // binary indexed tree
    ll n;
 
    FenwickTree(ll N) {
        n = N;
        bit.assign(N, 0);
    }
 
    ll sum(ll r) {
        ll ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }
    ll query(ll l, ll r){
        return sum(r) - sum(l - 1);
    }
    void update(ll idx, ll val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += val;
    }
    void range_update(ll l, ll r, ll val){
        update(l, +val);
        update(r + 1, -val);
    }
};

int main(){
    ll n; cin >> n;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) cin >> arr[i];

    FenwickTree tree(n + 5);

    for(ll i = 0; i < n; i++) tree.update(i, arr[i]);
        
    cout << tree.query(0, 2) << endl;


    // bonus : to make 2D fenwick tree use

    //ll k; cin >> k;
    //vector<FenwickTree > tree(k + 1, FenwickTree(n + 5));

}
 
 

































