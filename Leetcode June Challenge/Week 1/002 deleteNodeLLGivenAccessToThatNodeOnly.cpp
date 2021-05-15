/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// given that it's not the last node and distinct elements in linked list
class Solution {
public:
    void deleteNode(ListNode* node) {

        node->val = node->next->val;
        ListNode* temp = node->next;
        node->next = node->next->next;

        delete temp;

    }
};
