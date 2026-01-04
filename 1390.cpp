class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        auto solve = [&](int x) -> pair<int,int> {
            int cnt = 0, sum = 0;
            for(int i = 1; i * i <= x; i++){
                if(cnt > 4) break;
                if(x % i == 0){
                    int a = i, b = x / i;
                    if(a != b) cnt += 2, sum += a, sum += b;
                    else cnt += 1, sum += a;
                }
            }
            return {cnt, sum};
        };
        int sum = 0;
        for(int i = 0; i < n; i++){
            pair<int,int> p = solve(nums[i]);
            if(p.first == 4) sum += p.second;
        }
        return sum;
    }
};