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
    class linkedList{
    public:
        ListNode* head;
        linkedList(ListNode* head){
            this->head = head;
        }

        ListNode* getPrev(ListNode* curr){

            if(head->next==NULL) return NULL;

            ListNode* temp = head;
            while(temp && temp->next!=curr)
                temp = temp->next;
            return temp;

        }
        ListNode* getTail(){

            ListNode* temp_ = head;
            while(temp_->next)
                temp_ = temp_->next;
            return temp_;
        }

    };
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        if(l1->val==0) return l2;
        if(l2->val==0) return l1;

        // wrapper class
        linkedList list1(l1), list2(l2);

        // head and tail of result
        ListNode* head = new ListNode(0);
        // ListNode* tail = head;

        ListNode* t1 = list1.getTail();
        ListNode* t2 = list2.getTail();
        int carry = 0;
        while(t1 && t2){

            int sum = t1->val+t2->val+carry;

            // create a new node, and add to result
            ListNode* temp = new ListNode(sum%10);
            temp->next = head->next;
            head->next = temp;
            // tail = temp;

            carry = sum/10;

            // move the pointers
            t1 = list1.getPrev(t1);
            t2 = list2.getPrev(t2);

        }
        while(t1){

            int sum = t1->val+carry;

            ListNode* temp = new ListNode(sum%10);
            temp->next = head->next;
            head->next = temp;
            // tail = temp;

            carry = sum/10;

            // move the pointers
            t1 = list1.getPrev(t1);

        }
        while(t2){

            int sum = t2->val+carry;

            ListNode* temp = new ListNode(sum%10);
            temp->next = head->next;
            head->next = temp;
            // tail = temp;

            carry = sum/10;

            // move the pointers
            t2 = list2.getPrev(t2);

        }
        cout<<carry;
        if(carry!=0){
            ListNode* temp = new ListNode(carry);
            temp->next = head->next;
            head->next = temp;
            // tail = temp;
        }

        return head->next;

    }
};
