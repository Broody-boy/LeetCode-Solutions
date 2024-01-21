/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverseLL(ListNode* head){
        if(head == NULL || head->next == NULL) return head;      

        ListNode* newHead = reverseLL(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

    ListNode* findKthNode(ListNode* head, int k){
        int i = 1;
        ListNode *kthNode = head;

        while(i!=k && kthNode!=NULL){
            kthNode = kthNode->next;
            i++;
        }

        return kthNode;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* nextNode = head;
        ListNode* prevLast = NULL;
        ListNode* temp = head;
        ListNode* kthNode = NULL;


        while(temp!=NULL){

            kthNode = findKthNode(temp, k);

            if(!kthNode){
                if(prevLast) prevLast->next = temp;
                break;
            }

            nextNode = kthNode->next;   //Preserve the next block
            
            kthNode->next = NULL;       //and make the block individual inked list:

            reverseLL(temp);
            temp->next = nextNode;

            if(temp == head)
                head = kthNode;  //For first group, update the head.
            else
                prevLast->next = kthNode;
            prevLast = temp;
            temp = nextNode;
        }

        return head;
    }
};