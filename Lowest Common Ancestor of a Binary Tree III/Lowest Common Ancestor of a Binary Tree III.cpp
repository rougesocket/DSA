/*************************************************************
    Following is the Binary Tree Node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode<T> *parent;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
            parent = NULL;
        }
    };

*************************************************************/

BinaryTreeNode<int>* lca(BinaryTreeNode<int>* n1, BinaryTreeNode<int>* n2,BinaryTreeNode<int>* p, BinaryTreeNode<int>* q){
    if(p==q)return p;
    if(p==0){
        return lca(n1,n2,n2,q);
    }
    else if(q==0){
        return lca(n1,n2,p,n1);
    }
    return lca(n1,n2,p->parent,q->parent);
}
BinaryTreeNode<int> *leastCommonAncestor(BinaryTreeNode<int> *n1, BinaryTreeNode<int> *n2){  
       BinaryTreeNode<int>* temp = lca(n1,n2,n1,n2);
       return temp;
}
