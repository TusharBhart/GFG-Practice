/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    Node* find(Node* root, int t) {
        if(!root) return NULL;
        if(root -> data == t) return root;
        
        Node* l = find(root -> left, t);
        Node* r = find(root -> right, t);
        if(l) return l;
        if(r) return r;
        return NULL;
    }
    void dfs(Node* root, int l, long long int &ans) {
        if(!root) return;
        if(!l) ans += root -> data;
        
        dfs(root -> left, l - 1, ans);
        dfs(root -> right, l + 1, ans);
    }
public:
    long long int verticallyDownBST(Node *root,int target){
        Node* targetNode = find(root, target);
        if(!targetNode) return -1;
        
        long long int ans = 0;
        dfs(targetNode, 0, ans);
        return ans - target;
    }
};