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
    ListNode *detectCycle(ListNode *head) {
        
    unordered_set<ListNode *> s;
    ListNode *temp = head;

    while(temp!=NULL && s.find(temp) == s.end()){
        s.insert(temp);
        temp=temp->next;
    }

    return (temp==NULL) ? NULL : temp; //or direct: return temp;

    }
};