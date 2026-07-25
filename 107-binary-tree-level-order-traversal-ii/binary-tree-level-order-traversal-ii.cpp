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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        if(root==nullptr){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int d=q.size();
            vector<int>temp;
            for(int x=0;x<d;x++){
               auto curr= q.front();
               temp.push_back(curr->val);
                q.pop();
                
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                if(curr->right!=nullptr){
                    q.push(curr->right);
                }


            }  
                ans.push_back(temp);


        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};