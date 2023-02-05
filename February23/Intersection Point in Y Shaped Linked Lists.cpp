/* Linked List Node
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
public:
    int intersectPoint(Node* head1, Node* head2) {
        Node* h1 = head1, *h2 = head2;
        while(1) {
            if(h1 == h2) return h1 -> data;
            h1 = h1 -> next;
            h2 = h2 -> next;
            if(!h1 && !h2) return -1;
            if(!h1) h1 = head2;
            if(!h2) h2 = head1;
        }
        return -1;
    }
};
