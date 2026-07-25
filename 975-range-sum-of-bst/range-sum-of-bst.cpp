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

        int sum=0;
     void help(TreeNode* root, int low, int high) {
        if(root==nullptr){
            return ;
        }

       

        if(root->val<=high && root->val>=low){
            sum+=root->val;
        }

        if(root->val<=high){
           help(root->right,low,high);
        }

        if(root->val>=low){
            help(root->left,low,high);
        }

        

    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        help(root,low,high);
        return sum;
    }
};