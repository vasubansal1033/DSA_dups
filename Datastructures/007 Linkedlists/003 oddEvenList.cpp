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



 // first approach - not that good
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // one approach - delete the even placed node and append it at end
        // second approach - maintain two ll for even and odd

        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return head;

        ListNode* tail = head;

        while(tail->next!=NULL)
            tail = tail->next;

        ListNode* tail_ = tail;
        ListNode* headNext = head->next;
        ListNode* curr = head;

        while(curr!=tail_ && curr!=headNext){

            ListNode* temp = curr->next;
            curr->next = curr->next->next;

            tail->next = temp;
            tail = tail->next;
            tail->next = NULL;

            curr = curr->next;

        }

        return head;

    }
};



// second Solution

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
    ListNode* oddEvenList(ListNode* head) {

        // one approach - delete the even placed node and append it at end
        // second approach - maintain two ll for even and odd

        if(head==NULL || head->next==NULL || head->next->next==NULL)
            return head;

        ListNode* oddHead = new ListNode;
        ListNode* oddTail = oddHead;
        ListNode* evenHead = new ListNode;
        ListNode* evenTail = evenHead;

        bool isOdd = true;
        ListNode* curr = head;

        while(curr){

            if(isOdd){

                oddTail->next = curr;
                oddTail = oddTail->next;

            }else{

                evenTail->next = curr;
                evenTail = evenTail->next;

            }
            curr = curr->next;
            isOdd = !isOdd;

        }

        evenTail->next = NULL;
        oddTail->next = evenHead->next;

        return head;
    }
};
