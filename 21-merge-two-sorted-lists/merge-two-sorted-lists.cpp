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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        if(list1==NULL) return list2;
        if(list2==NULL) return list1;

        ListNode*l1 = (list1->val > list2->val) ? list2 : list1;  //l1 is smaller one
        ListNode*l2 = (list1->val > list2->val) ? list1 : list2;  //l2 is larger one
        
        ListNode*res = l1;

        while(l2!=NULL && l1!=NULL){
            ListNode*temp = NULL;
            while(l1!=NULL && l1->val <= l2->val){
                temp = l1;
                l1 = l1->next;
            }

            temp->next = l2;
            swap(l1,l2);
        }

        return res;
    }
};