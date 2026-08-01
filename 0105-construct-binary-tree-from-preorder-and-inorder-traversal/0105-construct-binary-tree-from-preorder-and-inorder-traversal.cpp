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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        TreeNode* root=tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mp);
        return root;
    }
    TreeNode* tree(vector<int>&preorder,int prestart,int preend,vector<int>&inorder,int inorderstart,int inorderend,map<int,int>&mp){
        if(prestart>preend || inorderstart>inorderend){
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[prestart]);
        int indexroot=mp[root->val];
        int numsleft=indexroot-inorderstart;
        root->left=tree(preorder,prestart+1,prestart+numsleft,inorder,inorderstart,indexroot-1,mp);
        root->right=tree(preorder,prestart+numsleft+1,preend,inorder,indexroot+1,inorderend,mp);
        return root;
    }
};