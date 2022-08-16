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
    vector<int> ans;
    void solve(TreeNode* root,int level){
        
        if(root==NULL)return ;
        if(ans.size()==level)ans.push_back(root->val);
        solve(root->right,level+1);
        solve(root->left,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)return ans;
        solve(root,0);
        return ans;
    }
};


//approach 2

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL)return ans;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            int sz= q.size();
            for(int i=0;i<sz;i++){
                root = q.front();
                q.pop();
                if(i==0)ans.push_back(root->val);
                if(root->right)q.push(root->right);
                if(root->left)q.push(root->left);
            }
        }
        return ans;
    }
};
