/*

class Node{
public:
    int val;
    Node *next;
    Node(int num){
        val=num;
        next=NULL;
    }
};

*/

class Solution{
public:
    Node *primeList(Node *head){
        vector<int> v(1e5 + 1), primes;
        for(int i=2; i<=sqrt(1e5); i++) {
            if(!v[i]) {
                for(int j=i*i; j<1e5; j += i) v[j] = 1;
            }
        }
        for(int i=2; i<v.size(); i++) {
            if(!v[i]) primes.push_back(i);
        }
        Node* temp = head;
        while(temp) {
            int p = lower_bound(primes.begin(), primes.end(), temp -> val) - primes.begin();
            int mn = primes[p];
            if(p > 0) {
                if(abs(primes[p - 1] - temp -> val) <= abs(primes[p] - temp -> val)) mn = primes[p - 1];
            }
            temp -> val = mn;
            temp = temp -> next;
        }
        
        return head;
    }
};