174. Dungeon Game

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        auto bfs = [&](int mid){
            
            if(mid + dungeon[0][0] <= 0) return false;
            int INF = 1e9;
            priority_queue<array<int,3>> q; // max heap
            // maximum weight sum, i, j
            vector<pair<int,int>> moves {{0, 1}, {1, 0}};
            vector<vector<int>> dis(n + 5, vector<int>(m + 5, -INF));
            dis[0][0] = mid + dungeon[0][0];
            q.push({dis[0][0], 0, 0});

            while(!q.empty()){
                int weight = q.top()[0];
                int i = q.top()[1];
                int j = q.top()[2];
                q.pop();
                if(i == n - 1 and j == m - 1) return true;
                for(auto mov : moves){
                    int x = i + mov.first;
                    int y = j + mov.second;
                    if(x >= 0 and x < n and y >= 0 and y < m and dis[x][y] < weight + dungeon[x][y]
                    and weight + dungeon[x][y] > 0){
                        dis[x][y] = weight + dungeon[x][y];
                        q.push({dis[x][y], x, y});
                    }
                }
            }
            return false;
        };

        int low = 1, high = (1000 * n * m) + 5, ans = -1, mid;
        while(low <= high){
            mid = low + (high - low) / 2;
            if(bfs(mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};