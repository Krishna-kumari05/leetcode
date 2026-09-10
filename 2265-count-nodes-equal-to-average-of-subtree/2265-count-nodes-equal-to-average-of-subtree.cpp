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
    int number = 0;

private:
    int sum(TreeNode* root, int &number, int &count) {

        if (root == NULL) {
            count = 0;
            return 0;
        }

        int leftCount = 0;
        int rightCount = 0;

        int leftSum = sum(root->left, number, leftCount);
        int rightSum = sum(root->right, number, rightCount);

        
        count = leftCount + rightCount + 1;

        
        int totalSum = leftSum + rightSum + root->val;

        
        if (totalSum / count == root->val) {
            number++;
        }

        return totalSum;
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        sum(root, number, count);
        return number;
    }
};