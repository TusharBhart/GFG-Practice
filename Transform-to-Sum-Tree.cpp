/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution {
    int dfs(Node* root) {
        if(!root) return 0;
        
        int l = dfs(root -> left);
        int r = dfs(root -> right);
        
        int a = root -> data;
        root -> data = l + r;
        return a + l + r;
    }
  public:
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node) {
        dfs(node);
    }
};