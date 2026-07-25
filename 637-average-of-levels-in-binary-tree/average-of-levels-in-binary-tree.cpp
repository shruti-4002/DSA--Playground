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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans;
           queue<TreeNode*>q;
        if(root==nullptr){
            return ans;
        }
        q.push(root);
        while(!q.empty()){
            int d=q.size();
            
            int count=0;
            long long sum=0;
            for(int x=0;x<d;x++){
               auto curr= q.front();
                sum+=curr->val;
                count++;
                q.pop();
                
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                if(curr->right!=nullptr){
                    q.push(curr->right);
                }


            }  
               double av=double(sum)/count;
               ans.push_back(av);


        }
        
        return ans;
    }
    
};