/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxProduct(TreeNode* root) {
        
        int total_sum = 0;
        int mod = 1e9 + 7;
        auto calc_sum = [&](TreeNode* root, auto&& calc_sum){
            if(root == nullptr) return;
            total_sum += root->val;
            calc_sum(root->left, calc_sum);
            calc_sum(root->right, calc_sum);

        };
        calc_sum(root, calc_sum);

        long long max_ans = -1e9;
        auto dfs = [&](TreeNode* root, auto&& dfs) {
            if(root == nullptr) return 0ll;
            // intialise the nodes with their values.

            long long left = dfs(root->left, dfs);
            long long right = dfs(root->right, dfs);

            // going from bottom to up
            long long cur_sum = root->val + left + right;

            max_ans = max(max_ans, 1ll * cur_sum * (total_sum - cur_sum));

            return cur_sum;
        };
        dfs(root, dfs);
        return max_ans % mod;
    }
};