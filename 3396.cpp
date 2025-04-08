3396. Minimum Number of Operations to Make Elements in Array Distinct

class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;
        int index = -1;

        for(int i = n - 1; i >= 0; i--){
            if(st.count(nums[i])) {
                index = i;
                break;
            }
            st.insert(nums[i]);
        }
        int elements = index + 1;
        // so we need to remove at least elements count to get distinct remaining array
        
        auto ceil = [&](int a, int b){
            return (a + b - 1) / b;
        };

        int answer = ceil(elements, 3);
        return answer;
    }
};