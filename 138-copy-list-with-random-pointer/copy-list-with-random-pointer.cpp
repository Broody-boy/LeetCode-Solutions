/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head == NULL) return NULL;

        Node*newHead = NULL;
        Node *trav = head;

        //creating the zig zag linked list
        while(trav!=NULL) {
            Node *next = trav->next;

            Node *clone = new Node(trav->val);
            if(newHead==NULL) newHead = clone;

            trav->next = clone;
            clone->next = next;
            //Above 2 lines make one "|/" operation.
            //After 2nd iteration, it will become |/|/.
            //After all iterations, it will become |/|/|/|/.

            trav = next; //Get ready for next iteration.
        }

        trav = head;

        while(trav!= NULL){
            trav->next->random = trav->random ? trav->random->next : NULL;
            trav = trav->next->next;
        }

        trav = head;

        while(trav != NULL){
            Node *clone = trav->next;
            Node *nextTrav = clone->next ? clone->next : NULL;
            Node *nextClone = nextTrav ? nextTrav->next : NULL;

            trav->next = nextTrav;
            clone->next = nextClone;
            trav = nextTrav;
        }

        return newHead;
    }
};