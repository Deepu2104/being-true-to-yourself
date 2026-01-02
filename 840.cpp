class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        auto check = [&](int i, int j){
            
            if(i + 2 >= n or j + 2 >= m) return false;
            vector<int> count(10), sum(25);
            int diag_primary = 0, diag_secondary = 0;
            diag_primary = grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2];
            diag_secondary = grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j];

            for(int a = i; a <= i + 2; a++){
                int cur_row = 0;
                for(int b = j; b <= j + 2; b++){
                    if(grid[a][b] < 1 or grid[a][b] > 9 or count[grid[a][b]] > 0) return false;
                    cur_row += grid[a][b];
                    count[grid[a][b]]++;
                }
                sum[cur_row]++;
            }

            int col_sum = -1;
            for(int b = j; b <= j + 2; b++){
                int cur_col = 0;
                for(int a = i; a <= i + 2; a++){
                    cur_col += grid[a][b];
                }
                sum[cur_col]++;
            }
            sum[diag_primary]++, sum[diag_secondary]++;
            if(sum[diag_secondary] != 8) return false;
            return true;
        };

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){

                if(check(i, j)) ans++;
            }
        }
        return ans;
    }
};