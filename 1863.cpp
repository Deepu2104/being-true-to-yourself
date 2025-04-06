1863. Sum of All Subset XOR Totals

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for(int i = 0; i < (1 << n); i++){
            vector<int> subset;
            for(int j = 0; j < n; j++){
                int mask = i & (1 << j);
                if(mask){
                    subset.push_back(nums[j]);
                }
            }
            int xorr = 0;
            for(auto i : subset){
                xorr ^= i;
            }
            sum += xorr;
        }
        return sum;
    }
};
