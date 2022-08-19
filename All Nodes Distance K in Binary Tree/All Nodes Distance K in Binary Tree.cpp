/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,unordered_map<TreeNode*, TreeNode* >&parent){
        if(root==NULL)return;
        
        if(root->left)parent[root->left]=root;
        if(root->right)parent[root->right]=root;
        
        dfs(root->left,parent);
        dfs(root->right,parent);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        if(root==NULL || target==NULL)return {};
        unordered_map<TreeNode*,TreeNode* > ump;
        dfs(root,ump);
        vector<int> ans;
        queue<TreeNode* > q;
        q.push(target);
        int lvl=0;
        unordered_map<TreeNode*,bool> visited;
        visited[target]=true;
        while(!q.empty()){
            int sz = q.size();
            if(lvl++==k)break;
            for(int i=0;i<sz;i++){
                root = q.front();
                visited[root]=true;
                q.pop();
                if(root->left && !visited[root->left])q.push(root->left);
                if(root->right && !visited[root->right])q.push(root->right);
                if(ump[root] && !visited[ump[root]])q.push(ump[root]);
            }
        }
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};


//approach 2
void bfsloader(TreeNode* root,unordered_map<TreeNode*,TreeNode* > &parent){
        
    queue<TreeNode*>q;
    q.push(root);
    
    while(!q.empty()){
        int sz = q.size();
        
        for(int i=0;i<sz;i++){
            root=q.front();
            q.pop();
            
            if(root->left){
                q.push(root->left);
                parent[root->left]=root;
            }
            if(root->right){
                q.push(root->right);
                parent[root->right]=root;
            }
        }
    }
}
