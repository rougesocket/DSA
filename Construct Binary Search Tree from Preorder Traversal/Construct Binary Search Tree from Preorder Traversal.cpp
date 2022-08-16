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
    TreeNode* builder(vector<int>& preorder,int plo,int phi,vector<int>&inorder,int ilo,int ihi,unordered_map<int,int>& ump){
        if(plo>phi || ilo>ihi)return NULL;
        TreeNode* root = new TreeNode(preorder[plo]);
        int pos = ump[preorder[plo]];
        int idx = pos-ilo;
        root->left = builder(preorder,plo+1,plo+idx,inorder,ilo,pos-1,ump);
        root->right = builder(preorder,plo+idx+1,phi,inorder,pos+1,ihi,ump);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder(preorder.begin(),preorder.end());
        unordered_map<int,int> ump;
        sort(inorder.begin(),inorder.end());
        for(int i=0;i<inorder.size();i++){
            ump[inorder[i]]=i;
        }
        return builder(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,ump);
    }
};

//Approach 2

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
    int idx=0;
    TreeNode* solve(vector<int>& preorder,int lim){
        if(idx>=preorder.size() || preorder[idx]>lim)return NULL;
        TreeNode* root;
        if(preorder[idx]<lim){
            root= new TreeNode(preorder[idx++]);
            root->left= solve(preorder,root->val);
            root->right=solve(preorder,lim);
        }
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return solve(preorder,INT_MAX);   
    }
};
