/* Tree node structure  used in the program

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}; */

class Solution {
  public:
    vector<int> maximumValue(Node* node) {
        vector<int> ans;
        queue<Node*> q;
        q.push(node);
        
        while(q.size()) {
            int n = q.size(), mx = 0;
            while(n--) {
                Node* temp = q.front(); q.pop();
                mx = max(mx, temp -> data);
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
            ans.push_back(mx);
        }
        return ans;
    }
};