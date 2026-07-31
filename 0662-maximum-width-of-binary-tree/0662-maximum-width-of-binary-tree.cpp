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
    int widthOfBinaryTree(TreeNode* root) {
       long long ans=0;
        queue<pair<TreeNode* ,long long>>q;
        long long cnt=0;
        if(root==NULL){
            return 0;
        }
        q.push({root,cnt});
        while(!q.empty()){
            vector<long long>level;
            long long s=q.size();
              long long mini=q.front().second;

            for(long long i=0;i<s;i++){
                TreeNode* l=q.front().first;
                long long c=q.front().second-mini;

                if(l->left!=NULL){
                    cnt=2*c+1;
                    q.push({l->left,cnt});
                }
                if(l->right!=NULL){
                    cnt=2*c+2;
                    q.push({l->right,cnt});
                }
                level.push_back(q.front().second);
                q.pop();
            }
            long long m=level.size();
            ans=max(ans,level[m-1]-level[0]+1);
        }
        return ans;

    }
};