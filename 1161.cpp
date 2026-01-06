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
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = 1;
        int max_sum = -1e9, smallest_level = 1e9;

        while(!q.empty()){
            int sz = q.size();
            int current_level_sum = 0;
            while(sz--){
                TreeNode* parent = q.front();
                current_level_sum += parent->val;

                if(parent->left) q.push(parent->left);
                if(parent->right) q.push(parent->right);
                q.pop();
            }
            if(current_level_sum > max_sum){
                max_sum = current_level_sum;
                smallest_level = level;
            }
            level++;
        }
        return smallest_level;

    }
};