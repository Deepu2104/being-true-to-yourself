int dp[1005][1005];
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        // dp[i][j] -> maximum sum if taken first i and first j elements from the strings
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                if(i == 0 or j == 0){
                    // we are not taking any character, then we cannot make them equal
                    dp[i][j] = 0;
                }else{
                    if(s1[i - 1] == s2[ j - 1]){
                        dp[i][j] = (int)s1[i - 1] + (int)s2[j - 1] + dp[i - 1][j - 1];
                    }
                    dp[i][j] = max(dp[i][j], dp[i - 1][j]);
                    dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                }
            }
        }
        int total_sum = 0;
        for(int i = 0; i < n; i++) total_sum += (int)s1[i];
        for(int i = 0; i < m; i++) total_sum += (int)s2[i];
        int common_sum = dp[n][m];

        // vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= m; j++){
                dp[i][j] = 0;
            }
        }// reset for every testcase

        return total_sum - common_sum;

    }
};