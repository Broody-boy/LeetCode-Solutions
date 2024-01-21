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

    bool hasCycle(ListNode *head) {

        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) return true;
        };

        return false;

    }

    ListNode *detectCycle(ListNode *head) {

        if(!hasCycle(head)) return NULL;
        //Now we are sure that cycle exists

        ListNode *slow = head;
        ListNode *fast = head;

        do{
            slow = slow->next;
            fast = fast->next->next;
        }while(slow != fast);

        slow = head;

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }

        return fast;
    }
};