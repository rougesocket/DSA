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
    TreeNode* builder(vector<int>&preorder,int plo,int phi,vector<int>&inorder,int ilo,int ihi,unordered_map<int,int>&ump){
        if(plo>phi || ilo>ihi)return NULL;
        int pos = ump[preorder[plo]];
        int idx = pos-ilo;
        TreeNode* root = new TreeNode(preorder[plo]);
        root->left=builder(preorder,plo+1,plo+idx,inorder,ilo,pos-1,ump);
        root->right=builder(preorder,plo+idx+1,phi,inorder,pos+1,ihi,ump);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
     
        unordered_map<int,int> ump;
        for(int i=0;i<inorder.size();i++){
            ump[inorder[i]]=i;
        }
        return builder(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,ump);
    }
};
