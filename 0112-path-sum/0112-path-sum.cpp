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
private:
    bool preorder(TreeNode* root, int target, int sum) {
        if (root == NULL) {
            return false;
        }

        sum += root->val;
        if (root->left == NULL && root->right == NULL) {
            return sum == target;
        }

        return preorder(root->left, target, sum) ||
               preorder(root->right, target, sum);
    }

public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return preorder(root, targetSum, 0);
    }
};