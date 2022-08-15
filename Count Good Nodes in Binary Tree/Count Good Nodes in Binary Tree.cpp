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
    int cnt = 0;
    void solve(TreeNode* root,int prev){
        if(root==NULL)return ;
        int val = root->val;
        if(prev<=val)cnt++;
        solve(root->left,max(prev,val));
        solve(root->right,max(prev,val));
    }
    int goodNodes(TreeNode* root) {
        if(root==NULL)return 0;
        solve(root,root->val);
        return cnt;
    }
};
