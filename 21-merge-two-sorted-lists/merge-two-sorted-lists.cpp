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
        
        ListNode* first = list1;
        ListNode* second = list2;

        ListNode *dummy = new ListNode();
        ListNode *duplicateDummy = dummy;

        while(first != NULL && second != NULL){
            ListNode *newNode = new ListNode();

            if(first->val <= second->val) {
                newNode->val = first->val;
                first = first->next;
            } else {
                newNode->val = second->val;
                second = second->next;
            }
            duplicateDummy->next = newNode;
            duplicateDummy = duplicateDummy->next;
        }

        while(first != NULL){
            ListNode *newNode = new ListNode();
            newNode->val = first->val;
            first = first->next;
            duplicateDummy->next = newNode;
            duplicateDummy = duplicateDummy->next;
        }

        while(second != NULL){
            ListNode *newNode = new ListNode();
            newNode->val = second->val;
            second = second->next;
            duplicateDummy->next = newNode;
            duplicateDummy = duplicateDummy->next;
        }

        return dummy->next;
    }
};