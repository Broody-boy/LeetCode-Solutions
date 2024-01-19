/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int length1 = 0, length2 = 0;

        ListNode* l1 = headA;
        ListNode* l2 = headB;

        while(l1!=NULL || l2!=NULL){        //Finding lengths of both linked lists in one go
            if(l1!=NULL){
                length1++;
                l1 = l1->next;
            }
            if(l2!=NULL){
                length2++;
                l2 = l2->next;
            }
        }

        int diff = abs(length2-length1);
        l1 = (length1>length2) ? headB : headA; //l1 is smaller one
        l2 = (length1>length2) ? headA : headB; //l2 is longer one

        for(int i = 0; i < diff; i++)       //Shredding the diff part from longer array's start
            l2 = l2->next;
        
        while(l1!=l2){                      //Iterate until match
            l1 = l1->next;
            l2 = l2->next;
        }

        return l1;                          //or l2

    }
};