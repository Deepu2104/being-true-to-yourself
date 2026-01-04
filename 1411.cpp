
class Solution {
    
    int dp[5001][4][4][4];
    const int mod = 1e9 + 7;

public:
    int numOfWays(int n) {
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= 3; j++){
                for(int k = 0; k <= 3; k++){
                    for(int l = 0; l <= 3; l++){
                        dp[i][j][k][l] = -1;
                    }
                }
            }
        }

        auto dfs = [&](int cur, int a, int b, int c, auto&&dfs){
            
            if(cur >= n) return 1;
            if(dp[cur][a][b][c] != -1) return dp[cur][a][b][c];

            int ans = 0;

            for(int i = 0; i <= 2; i++){
                if(i == a) continue;
                for(int j = 0; j <= 2; j++){
                    if(j == i or j == b) continue;
                    for(int k = 0; k <= 2; k++){
                        if(k == j or k == c) continue;
                        (ans += dfs(cur + 1, i, j, k, dfs)) %= mod;
                    }
                }
            }
            return dp[cur][a][b][c] = ans % mod;
        };

        int ans = dfs(0, 3, 3, 3, dfs);
        return ans;
    }
};