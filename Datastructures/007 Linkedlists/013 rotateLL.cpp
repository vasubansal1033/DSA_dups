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
    ListNode* rotateRight(ListNode* head, int k) {

        int size = 0;

        ListNode* curr = head;
        while(curr!=nullptr){
            size++;
            curr = curr->next;
        }

        if(size==0 || size==1 || k==0)
            return head;

        k = k%size;

        if(k==0)
            return head;

        ListNode* prev = head;
        for(int i=0; i<size-k-1; i++)
            prev = prev->next;
        curr = prev->next;

        ListNode* temp = curr;



        while(temp->next!=nullptr)
            temp = temp->next;

        prev->next = nullptr;
        temp->next = head;
        head = curr;
        return head;

    }
};
