/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */


class Solution {
    public:
    //Function to connect nodes at same level.
    void connect(Node *root) {
       queue<Node*> q;
       q.push(root);
       
       while(q.size()) {
           int n = q.size();
           vector<Node*> l;
           for(int i=0; i<n; i++) {
               Node* temp = q.front(); q.pop();
               l.push_back(temp);
               
               if(temp -> left) q.push(temp -> left);
               if(temp -> right) q.push(temp -> right);
           }
          for(int i=0; i<n-1; i++) l[i] -> nextRight = l[i + 1];
       }
    }    
      
};