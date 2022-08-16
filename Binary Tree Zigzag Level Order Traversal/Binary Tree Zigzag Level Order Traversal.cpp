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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int> > ans;
        if(root==NULL)return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool isrev=false;
        while(!q.empty()){
            
            int sz = q.size();
            vector<int> row(sz);
            for(int i=0;i<sz;i++){
                root = q.front();
                q.pop();
                int idx = (isrev)?sz-i-1:i;
                row[idx]= root->val;
                if(root->left)q.push(root->left);
                if(root->right)q.push(root->right);
            }
            ans.push_back(row);
            isrev=!isrev;
        }
        return ans;
    }
};
