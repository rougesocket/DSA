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
    void dfs(TreeNode* root,vector<int>& in){
        if(root==NULL)return ;
        dfs(root->left,in);
        in.push_back(root->val);
        dfs(root->right,in);
    }
    TreeNode* builder(vector<int>& in,int lo,int hi){
        if(lo>hi)return NULL;
        int mid = lo+(hi-lo)/2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = builder(in,lo,mid-1);
        root->right = builder(in,mid+1,hi);
        return root;
    }
    TreeNode* balanceBST(TreeNode* root) {
        
        vector<int> inorder;
        dfs(root,inorder);
        root = builder(inorder,0,inorder.size()-1); 
        return root;
    }
};
