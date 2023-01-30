/*
struct Node {
	int key;
	Node *left, *right;
};
*/

class Solution {
    int dfs(Node* root, int &ans) {
        if(!root) return 0;
        int l = dfs(root -> left, ans);
        int r = dfs(root -> right, ans);
        
        ans += abs(l) + abs(r);
        return root -> key + l + r - 1;
    }
    public:
    int distributeCandy(Node* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};