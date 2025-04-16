2537. Count the Number of Good Subarrays

using ll = long long;

static auto init = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        
        ll n = nums.size();
        ll l = 0, r = 0;
        unordered_map<ll,ll> freq;
        ll ans = 0, total_count = 0; // to store the number valid pairs

        auto calc_contribution = [&](ll x){
            return (1ll * x * (x - 1)) / 2ll;    
        };

        // for having at least k pairs, we need the total_count to be calc_contribution(k);
        ll required_count = k;

        while(r < n){
            ll old_count = calc_contribution(freq[nums[r]]);
            freq[nums[r]]++;
            ll new_count = calc_contribution(freq[nums[r]]);
            total_count -= old_count, total_count += new_count;

            if(total_count >= required_count) ans += n - r;

            while(l < r and total_count >= required_count){
                
                // let's see if we can reduce the window and still get the answer
                // if yes then all these subarray will also contribute to answer
                old_count = calc_contribution(freq[nums[l]]);
                freq[nums[l]]--;
                if(freq[nums[l]] > 0) new_count = calc_contribution(freq[nums[l]]);
                else new_count = 0;

                total_count -= old_count, total_count += new_count;
                
                if(total_count >= required_count) ans += n - r;
                l++;
            }
            r++;
        }

        return ans;
    }
};

