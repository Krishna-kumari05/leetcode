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
    int maxPathSum(TreeNode* root) {
        int sum=INT_MIN;
        dfs(root ,sum);
        return  sum;
    }
    int dfs(TreeNode* root,int& sum){
         if(root==NULL){
            return 0;
        }
         int lh = max(0, dfs(root->left, sum));
        int rh = max(0, dfs(root->right, sum));

        sum=max((lh+rh+root->val),sum);
        return root->val + max(lh, rh);
    }
};