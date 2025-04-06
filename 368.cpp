368. Largest Divisible Subset

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        
        int n = arr.size();
        sort(arr.begin(), arr.end());
        vector<vector<int>> dp(n + 5, vector<int>(n + 5, -1));

        auto dfs = [&](int cur ,int prev, auto&& dfs){
            if(cur >= n) return 0;
            if(dp[cur][prev] != -1) return dp[cur][prev];

            int ans = 0;
            ans = max(ans, dfs(cur + 1, prev, dfs));
            if(prev == n){
                ans = max(ans, 1 + dfs(cur + 1, cur, dfs));
            }else{
                if(arr[cur] % arr[prev] == 0) ans = max(ans, 1 + dfs(cur + 1, cur, dfs));
            }
            return dp[cur][prev] = ans;
        };

        int ans_max = dfs(0, n, dfs);

        vector<int> answer;

        function<void(int, int, int)> track_dp = [&](int cur, int prev, int remaining) {
            if(cur == n || remaining == 0) return;

            if(prev == -1 || arr[cur] % arr[prev] == 0) {
                int take = 1 + dfs(cur + 1, cur, dfs);
                if(take == remaining) {
                    answer.push_back(arr[cur]);
                    track_dp(cur + 1, cur, remaining - 1);
                    return;
                }
            }

            // Else skip current element
            track_dp(cur + 1, prev, remaining);
        };

        track_dp(0, -1, ans_max);
        return answer;
    }
};
