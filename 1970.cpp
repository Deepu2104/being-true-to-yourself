class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        
        auto good = [&](int mid){
            vector<vector<int>> matrix(row, vector<int>(col));
            // intially every cell is 0 (land)
            for(int i = 0; i <= mid; i++){
                int x = cells[i][0] - 1, y = cells[i][1] - 1; // 1 based indexes are given
                matrix[x][y] = 1; // make them water
            }
            
            vector<vector<int>> seen(row, vector<int>(col));
            // apply bfs to see if we can reach bottom
            // multi source bfs
            queue<pair<int,int>> q;
            vector<pair<int,int>> moves = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
            for(int i = 0; i < col; i++) {
                if(matrix[0][i] == 0){ // if only they were land
                    q.push({0, i});
                    seen[0][i] = 1;
                }
            }

            auto valid = [&](int i, int j)->bool{
                if(i >= 0 and i < row and j >= 0 and j < col and !seen[i][j] and 
                matrix[i][j] == 0){
                    return true;
                }
                return false;
            };

            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                // if reached bottom layer, we can return true
                if(x == row - 1) return true;
                q.pop();

                for(auto m : moves){
                    int i = x + m.first;
                    int j = y + m.second;
                    if(valid(i, j)){
                        q.push({i, j});
                        seen[i][j] = 1;
                    }
                }
            }

            return false;

        };

        int low = 0, high = cells.size() - 1, ans = -1, mid;

        while(low <= high){
            mid = low + (high - low) / 2; // why we do this, to prevent the integer overflow

            if(good(mid)){ // maximum prefix it's safe to go bottom
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }

        return ans + 1; // since ans is the maximum safe index
    }
};