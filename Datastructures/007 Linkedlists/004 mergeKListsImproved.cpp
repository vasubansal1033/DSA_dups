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
    ListNode* mergeTwoLists(ListNode* head1, ListNode* head2){

        if(head2==nullptr)
            return head1;
        if(head1==nullptr)
            return head2;

        ListNode* mergeHead = new ListNode(0);
        ListNode* mergeTail = mergeHead;

        ListNode* curr1 = head1;
        ListNode* curr2 = head2;
        while(curr1 && curr2){

            if(curr1->val<=curr2->val){

                mergeTail->next = curr1;
                curr1 = curr1->next;
                mergeTail = mergeTail->next;
                mergeTail->next = nullptr;

            }else{

                mergeTail->next = curr2;
                curr2 = curr2->next;
                mergeTail = mergeTail->next;
                mergeTail->next = nullptr;

            }

        }

        if(curr1==nullptr){
            mergeTail->next = curr2;
            return mergeHead->next;
        }
        if(curr2==nullptr){
            mergeTail->next = curr1;
            return mergeHead->next;
        }

        return mergeHead->next;


    }
    ListNode* mergeKListsUtil(vector<ListNode*>& lists, int start, int last){

        if(start>=last)
            return lists[start];
        int mid = start+(last-start)/2;

        ListNode* h1 = mergeKListsUtil(lists, start, mid);
        ListNode* h2 = mergeKListsUtil(lists, mid+1, last);

        return mergeTwoLists(h1, h2);


    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==0)
            return nullptr;

        return mergeKListsUtil(lists, 0, lists.size()-1);
    }
};
