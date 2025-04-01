2140. Solving Questions With Brainpower

class Solution {
public:
    using ll = long long;
    long long mostPoints(vector<vector<int>>& q) {
        
        int n = q.size();
        vector<ll> dp(n + 5, -1);
        
        auto dfs = [&](int cur, auto&& dfs){
            if(cur >= n) return 0ll;
            if(dp[cur] != -1) return dp[cur];
            
            ll ans = 0;
            
            // if i decide to solve this question
            ans = max(ans, q[cur][0] + dfs(cur + q[cur][1] + 1, dfs));
            
            // if i skip
            ans = max(ans, dfs(cur + 1, dfs));
            return dp[cur] = ans;
        };
        
        ll ans = dfs(0, dfs);
        return ans;
    }
};