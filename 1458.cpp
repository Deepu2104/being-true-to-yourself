using ll = long long;

ll dp[505][505];

class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        int m = nums2.size();
        ll INF = 1e12;
        // while writing iterative dp first and the foremost thing for all the
        // problems is to fill the intial columns, that is the base condition for recursion
        // in iterative terms, the starting known answer that is fixed .

        // so in order to fill the intial states, we should know what dp[i][j]
        // is representing , dp[i][j] -> maximum answer of first i elements in nums1
        // and first j elements in nums2
        // so if we pick 0 elements in any array, then answer is not possible,
        // so make it some number which is never give us the maximum answer, i.e 
        // minimum possible value -1e18

        for(int j = 0; j <= m; j++){
            dp[0][j] = -INF;
        }

        for(int i = 0; i <= n; i++){
            dp[i][0] = -INF;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                // for each cell, (state), we have 4 choices
                // 1 -> start fresh from this point. choose i and j 
                dp[i][j] = 1ll * nums1[i - 1] * nums2[j - 1]; 
                // 2 -> take i and j and also the maximum answer till
                // i - 1 and j - 1 elements
                dp[i][j] = max(dp[i][j], (1ll * nums1[i - 1] * nums2[j - 1]) 
                + dp[i - 1][j - 1]);

                // below 2 options is what i call, is carry forward the answer
                // just we choose nothing and say give max answer from it's previous states
                dp[i][j] = max(dp[i][j], 1ll * dp[i - 1][j]);
                dp[i][j] = max(dp[i][j], 1ll * dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }   
};