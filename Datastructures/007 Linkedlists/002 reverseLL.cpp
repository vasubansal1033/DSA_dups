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

// works in a single pass
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if(head==NULL || head->next==NULL)
            return head;

        ListNode* newHead;
        newHead = head;
        head = head->next;
        newHead->next = NULL;

        while(head!=NULL){

            ListNode* temp = head;
            head = head->next;
            temp->next = newHead;
            newHead = temp;
        }

        return newHead;

    }
};
