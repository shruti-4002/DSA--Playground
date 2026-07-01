/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        if(root==nullptr){
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode*curr=q.front();
            q.pop();
           
            if(curr==nullptr){
                ans+="N,";
            }else{

                ans+=to_string(curr->val)+",";
                q.push(curr->left);
                 q.push(curr->right);


            }
            


            
           
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //string data=1,2,3,N,N,4,5,N,N,N,N
        if(data.size()==0){
            return nullptr;
        }
        vector<string>str;
        string temp="";
       for (char ch : data) {
    if (ch == ',') {
        str.push_back(temp); // Comma milte hi direct push
        temp = "";             // Reset temp
    } else {
        temp += ch;            // Character jodo
    }
}
        TreeNode*root=new TreeNode(stoi(str[0]));
        queue<TreeNode*>q;
        q.push(root);

        int i=1;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            //Left child
            if(i<str.size()){
            if(str[i]!="N"){
                node->left=new TreeNode(stoi(str[i]));
                q.push(node->left);
            }}
            i++;

            //Right;
            
             if(i<str.size() && str[i]!="N" ){
                node->right=new TreeNode(stoi(str[i]));
                q.push(node->right);
            }
            i++;
            

        }

return root;

    
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));