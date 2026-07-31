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
    void flatten(TreeNode* root) {
        stack<TreeNode* >st;
        if(root == NULL)
            return;
        st.push(root);
        TreeNode*  k;
        while(!st.empty()){
            k=st.top();
            st.pop();
           
            if(k->right!=NULL){
                st.push(k->right);
            }
             if(k->left!=NULL){
                st.push(k->left);    
            }
             if(!st.empty()){
                k->right=st.top();
             }
             k->left=NULL;
        }
    }
};