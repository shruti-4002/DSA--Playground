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
 
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root==nullptr){
            return 0;
        }

        int sum=0;
        int left=0;
        int right=0;

        if(root->val<=high && root->val>=low){
            sum+=root->val;
        }

        if(root->val<high){
            left=rangeSumBST(root->right,low,high);
        }

        if(root->val>low){
            right=rangeSumBST(root->left,low,high);
        }

        return sum+left+right;

    }
};