#include <iostream>
#include <vector>
using namespace std;

struct Node{
  int val = 0;
  Node* left = NULL;
  Node* right = NULL;

  Node(int val)
  {
    this->val = val;
  }
};

Node* head;
void dfs(Node* root){
    if(root==NULL)return ;
    dfs(root->left);
    root->left = head;
    head->right = root;
    head=head->right;
    dfs(root->right);
}
Node* bToDLL(Node* root){
    
    head=new Node(-1);
    Node* cp = head;
    dfs(root);
    cp=cp->right;
    delete(cp->left);
    cp->left = NULL;
    return cp;
}

// input_Section_====================================================================

void display(Node* node)
{
  Node* head = node;
  while (node != NULL) {
    cout << node->val << " ";
    node = node->right;
    if (node == head)
      break;
  }
}

Node* constructFromInOrder(vector<int>& inOrder, int si, int ei)
{
  if (si > ei)
    return NULL;
  int mid = (si + ei) / 2;
  Node* root = new Node(inOrder[mid]);

  root->left = constructFromInOrder(inOrder, si, mid - 1);
  root->right = constructFromInOrder(inOrder, mid + 1, ei);

  return root;
}

Node* constructFromInOrder(vector<int>& inOrder)
{
  return constructFromInOrder(inOrder, 0, inOrder.size() - 1);
}

void solve()
{
  int n;
  cin >> n;
  vector<int> in(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> in[i];
  }

  Node* root = constructFromInOrder(in);
  Node* head = bToDLL(root);
  display(head);
}

int main()
{
  solve();
  return 0;
}
