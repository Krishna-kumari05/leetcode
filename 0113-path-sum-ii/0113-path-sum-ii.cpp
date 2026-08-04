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
    vector<vector<int>>ans;
    vector<int>path;

    void preorder(TreeNode* root, int target, int sum) {
        if (root == NULL) {
            return ;
        }
        path.push_back(root->val);
        sum += root->val;

        if (root->left == NULL && root->right == NULL) {
            if(sum == target){
                ans.push_back(path);
            }
        }

        preorder(root->left, target, sum);
        preorder(root->right, target, sum);
        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        preorder(root,targetSum,0);return ans;
    }
};