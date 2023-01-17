/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

class Solution {
    int dfs(Node* root, int &mx, int &ans) {
        if(!root) return 0;
        
        int l = dfs(root -> left, mx, ans);
        int r = dfs(root -> right, mx, ans);

        if(l && r) {
            if(__gcd(l, r) > mx) mx = __gcd(l, r), ans = root -> data;
            else if(__gcd(l, r) == mx) ans = max(ans, root -> data);
        }
        
        return root -> data;
;    }
public:
    int maxGCD( Node* root) {
        int mx = -1, ans = 0;
        dfs(root, mx, ans);
        
        return ans;
    }
};