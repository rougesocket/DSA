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
        string ans = "";
        if(root==NULL)return ans;
        queue<TreeNode* > q;
        
        q.push(root);
        
        while(!q.empty()){
            root=q.front();
            q.pop();
            
            if(root==NULL)ans.append("#,");
            else{
                ans.append(to_string(root->val)+",");
                q.push(root->left);
                q.push(root->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0)return NULL;
        string temp;
        stringstream ss(data);
        getline(ss,temp,',');
        TreeNode* root = new TreeNode(stoi(temp));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            
            getline(ss,temp,',');
            if(temp=="#")curr->left = NULL;
            else{
                curr->left= new TreeNode(stoi(temp));
                q.push(curr->left);
            }
            
            getline(ss,temp,',');
            if(temp=="#")curr->right = NULL;
            else{
                curr->right= new TreeNode(stoi(temp));
                q.push(curr->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
