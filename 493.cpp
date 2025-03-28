using ll = long long;
class Solution {

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
public:
    int reversePairs(vector<int>& nums) {
        ll n = nums.size();
        SegmentTree tree(n + 5);
        
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        map<ll,ll> compressed;
        ll index = 0;
        for(auto el : sorted) compressed[el] = index++;

        ll answer = 0;
        for(ll i = 0; i < n; i++){

            ll index_value = compressed[nums[i]];
            auto it = lower_bound(sorted.begin(), sorted.end(), 2ll * nums[i] + 1) - sorted.begin();
            if(it < n){
                // the 2 * nums[i] + 1 exists, and add all the elements greater that 2 * nums[i] to the answer
                ll next_index = compressed[sorted[it]];
                answer += tree.query(next_index, n);
            }
            // increase the frequency of nums[i];
            ll old_value = tree.query(index_value, index_value);
            tree.update(index_value, old_value + 1);
        }
        return answer;
    }
};