/*struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
    public:
     //Function to find first node if the linked list has a loop.
    int findFirstNode(Node* head) {
        Node* s = head, *f = head;
        
        while(f && f -> next) {
            s = s -> next;
            f = f -> next -> next;
            if(s == f) break;
        }
        if(!f || !f -> next) return -1;
        
        s = head;
        while(s != f) {
            s = s -> next;
            f = f -> next;
        }
        return s -> data;
    }
};