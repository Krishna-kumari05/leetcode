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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          vector<vector<int>>ans;
        queue<TreeNode* >q;
        if(root==NULL){
            return ans;
        }int cnt=0;
        q.push(root);
        while(!q.empty()){
            vector<int>level;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* l=q.front();
                q.pop();
                if(l->left){
                    q.push(l->left);
                }
                if(l->right){
                    q.push(l->right);
                }
                level.push_back(l->val);
            }
            if(cnt%2){
                reverse(level.begin(),level.end());
            }
            cnt++;
             ans.push_back(level);
        }
        return ans;
    }
};