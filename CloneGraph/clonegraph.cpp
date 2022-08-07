/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node,Node* curr,unordered_map<int,Node* >& ump){
        ump[curr->val]=curr;
        for(auto x : node->neighbors){
            if(ump.find(x->val)==ump.end()){
                Node* temp = new Node(x->val);
                dfs(x,temp,ump);
            }
        }
        for(auto x : node->neighbors){
            curr->neighbors.push_back(ump[x->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        unordered_map<int,Node* > ump;
        Node* root = new Node(node->val);
        dfs(node,root,ump);
        return root;
    }
};
