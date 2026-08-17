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

bool dfs(TreeNode*root,set<int>&st,int x){
        if(root==nullptr){
            return false;
        }
        
        int need=x-(root->val);
        if(st.find(need)!=st.end()){
            return true;
        }

        st.insert(root->val);

        return dfs(root->left,st,x)||dfs(root->right,st,x);

    }


    bool findTarget(TreeNode* root, int k) {
          set<int>st;
        
        return dfs(root,st,k);
    
    
       
    }
};