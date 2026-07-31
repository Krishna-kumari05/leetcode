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
  int findleft(TreeNode* root){
        int lheight=0;
        while(root->left!=NULL){
            lheight++;
            root=root->left;
        }
        return lheight;
            
        
  }
    int findright(TreeNode* root){
        int rheight=0;
        while(root->right!=NULL){
            root=root->right;
            rheight++;
        }
        return rheight;
    }
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh=findleft(root);
        int rh=findright(root);
        if(lh==rh){
            return (1<<(lh+1))-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
  
};