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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return nullptr;
        }

        if(root->val>key){
          root->left=  deleteNode(root->left,key);
        }else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }else{

            //CASE1:
            if(root->left==nullptr && root->right==nullptr){
                delete root;
                return nullptr;
            }

            //CASE2:
            if(root->left==nullptr){
                TreeNode*temp=root->right;
                delete root;
                return temp;
            }

            if(root->right==nullptr){
                TreeNode*temp=root->left;
                delete root;
                return temp;
            }

            //CASE 3 
            TreeNode*parent=root;
            TreeNode*succ=root->right;

            while(succ->left!=nullptr){
                parent=succ;
                succ=succ->left;
            }

               root->val= succ->val;

            if(root==parent){
           
                root->right=succ->right;
                     delete succ;
            }else{
                
                parent->left=succ->right;
                delete succ;
            }

            
        }

            return root;

        

    }
};