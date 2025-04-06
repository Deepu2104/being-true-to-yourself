2873. Maximum Value of an Ordered Triplet I


using ll = long long;
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        
        vector<ll> suff_max(n), pref_max(n);
        suff_max[n - 1] = nums[n - 1];
        pref_max[0] = nums[0];
        for(int i = n - 2; i >= 0; i--) suff_max[i] = max(suff_max[i + 1], 1ll * nums[i]);
        for(int i = 1; i < n; i++) pref_max[i] = max(pref_max[i - 1], 1ll * nums[i]);

        ll answer = 0;
        for(int i = 1; i < n - 1; i++){
            ll max_in_prefix = pref_max[i - 1];
            ll max_in_suffix = suff_max[i + 1];
            
            answer = max(answer,  (max_in_prefix - 1ll * nums[i]) * max_in_suffix);
        }

        return answer;
    }
};
