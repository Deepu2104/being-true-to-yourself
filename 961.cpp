class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        // without using any extra space

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == j) continue;
                if(nums[i] == nums[j]){
                    return nums[i];
                }
            }
        }
        return -1;
    }
};