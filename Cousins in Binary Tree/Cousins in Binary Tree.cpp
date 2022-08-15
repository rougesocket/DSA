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
    vector<pair<int,int> > temp;
    void dfs(TreeNode* root ,int x,int y,int depth,int parent){
        if(root==NULL)return ;
        if(root->val==x || root->val==y){
            temp.push_back({depth,parent});
        }
        dfs(root->left,x,y,depth+1,root->val);
        dfs(root->right,x,y,depth+1,root->val);
    }
    bool isCousins(TreeNode* root, int x, int y) {
        
        dfs(root,x,y,0,0);
        return temp.size()==2 && temp[0].first==temp[1].first && temp[0].second!=temp[1].second;
    }
};
