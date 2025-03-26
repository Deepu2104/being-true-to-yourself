2033. Minimum Operations to Make a Uni-Value Grid


class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        
        int n = grid.size();
        int m = grid[0].size();
        vector<int> elements;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                elements.push_back(grid[i][j]);
            }
        }
        sort(elements.begin(), elements.end());
        int mid = (n * m) / 2;
        int median = elements[mid]; 
        int answer = 0;
        for(int i = 0; i < n * m; i++){
            int gap = abs(elements[i] - median);
            if(gap % x) return -1;
            answer += gap / x;
        }
        return answer;
    }
};

