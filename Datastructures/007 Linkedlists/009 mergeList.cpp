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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        ListNode* ansHead = new ListNode(0);
        ListNode* ansTail = ansHead;

        ListNode* curr1 = l1; ListNode* curr2 = l2;
        while(curr1 && curr2){

            if(curr1->val<=curr2->val){

                ansTail->next = curr1;
                ansTail = ansTail->next;
                curr1 = curr1->next;

                ansTail->next = NULL;


            }else{

                ansTail->next = curr2;
                ansTail = ansTail->next;
                curr2 = curr2->next;

                ansTail->next = NULL;


            }

        }

        if(curr1){
            ansTail->next = curr1;
        }
        if(curr2){
            ansTail->next = curr2;
        }

        return ansHead->next;

    }
};
