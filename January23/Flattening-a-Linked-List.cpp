/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

class Solution {
    Node* merge(Node* head1, Node* head2) {
        Node* dummy = new Node(0), *nh = dummy;
        
        while(head1 && head2) {
            if(head1 -> data <= head2 -> data) {
                dummy -> bottom = head1;
                dummy = dummy -> bottom;
                head1 = head1 -> bottom;
            }
            else {
                dummy -> bottom = head2;
                dummy = dummy -> bottom;
                head2 = head2 -> bottom;
            }
        }
        if(head1) dummy -> bottom = head1;
        if(head2) dummy -> bottom = head2;
        
        return nh -> bottom;
    }
public:
    Node *flatten(Node *root) {
        Node* temp = root;
        while(temp) {
            root = merge(root, temp -> next);
            temp = temp -> next;
        }
        return root;
    }
};