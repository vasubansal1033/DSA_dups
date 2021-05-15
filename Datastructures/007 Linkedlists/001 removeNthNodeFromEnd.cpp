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

 // This algorithm works in a single pass
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head==NULL || head->next==NULL)
            return NULL;

        ListNode* ite1 = head;
        ListNode* ite2 = head;

        for(int i=0; i<n && ite2!=NULL; i++)
            ite2 = ite2->next;



        if(ite2==NULL){
            ListNode* temp = head;
            head = head->next;
            delete(temp);
            return head;
        }

        while(ite2->next!=NULL){
            ite1 = ite1->next;
            ite2 = ite2->next;
        }

        ListNode* temp = ite1->next;
        ite1->next = ite1->next->next;
        delete(temp);

        return head;

    }
};
