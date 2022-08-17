class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)    {
        
        Node* ans = NULL;
        while(root){
            int curr = root->data;
            if(curr>x->data){
                ans = root;
                root=root->left;
            }
            else{
                root=root->right;
            }
        }
        return ans;
    }
};
