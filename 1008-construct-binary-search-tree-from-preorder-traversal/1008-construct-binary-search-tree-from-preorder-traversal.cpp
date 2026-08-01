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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        return bst(preorder,0,preorder.size()-1);
    }
    TreeNode* bst(vector<int> &preorder, int prestart,int preend){
        if(prestart > preend)
            return NULL;
        TreeNode* root= new TreeNode(preorder[prestart]);
        int lindex=findls(prestart+1,preend,root->val,preorder);
        root->left=bst(preorder,prestart+1,lindex-1);
        root->right=bst(preorder,lindex,preend);
        return root;

    }
    int findls(int start,int end,int val,vector<int>&preorder){
        for(int i=start;i<=end;i++){
            if(val<preorder[i]){
                return i;
            }
        }
        return end+1;
    }
};