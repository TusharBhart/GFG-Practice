/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
    Node* merge(Node* head1, Node* head2) {
        Node* dummy = new Node(0), *nh = dummy;
        
        while(head1 && head2) {
            if(head1 -> data <= head2 -> data) {
                dummy -> next = head1;
                head1 = head1 -> next;
            }
            else {
                dummy -> next = head2;
                head2 = head2 -> next;
            }
            dummy = dummy -> next;
        }
        if(head1) dummy -> next = head1;
        if(head2) dummy -> next = head2;
        
        return nh -> next;
    }
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k) {
        Node* head = arr[0];
        for(int i=1; i<k; i++) {
            head = merge(head, arr[i]);
        }
        return head;
    }
};