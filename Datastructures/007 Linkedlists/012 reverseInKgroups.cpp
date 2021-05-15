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

    ListNode* reverseLL(ListNode* head, ListNode* tail){

        ListNode* newHead = new ListNode;
        while(head!=tail){

            ListNode* temp = head->next;
            head->next = newHead->next;
            newHead->next = head;
            head = temp;

        }

        return newHead->next;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        auto curr = head;
        for(int i=0; i<k; i++, curr = curr->next){
            if(curr == NULL)
                return head;

        }

        auto new_head = reverseLL(head, curr); // 3-2-1-4
        head->next = reverseKGroup(curr, k); // head still points at 1 only

        return new_head;

    }
};
