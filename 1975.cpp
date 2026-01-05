class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // we can make all even numbers positive by propagating the
        // negative sign , but odd one leaves out, in order to maximize
        // the submission, we will the make the least element in the matrix
        // odd one out, can we do this better?
        
        long mn = 1e6, sum = 0, cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cnt += ((matrix[i][j] < 0) ? 1 : 0);
                mn = min(mn, (long)abs(matrix[i][j]));
                sum += (long)abs(matrix[i][j]);
            }
        }
        return (cnt % 2) ? (sum - 2 * mn) : (sum); 
    }
};