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
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> stk;
        ListNode* dummy = new ListNode(0);
        ListNode* ptr = dummy;
        ListNode* next_ptr = head;
        
        while (next_ptr != nullptr) {
            ListNode* temp_ptr = next_ptr;
            for (int i = 0; i < k && temp_ptr != nullptr; i++) {
                stk.push(temp_ptr);
                temp_ptr = temp_ptr->next;
            }
            
            if (stk.size() == k) {
                while (!stk.empty()) {
                    ptr->next = stk.top();
                    stk.pop();
                    ptr = ptr->next;
                }
                ptr->next = temp_ptr;
                next_ptr = temp_ptr;
            } else {
                ptr->next = next_ptr;
                break;
            }
        }
        
        return dummy->next;
    }
};