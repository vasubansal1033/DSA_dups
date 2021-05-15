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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size()==0)
            return NULL;

        // newHead node points to the starting node of the merged list
        // newTail pointer points to the tail of the merged list
        ListNode* newHead = new ListNode;
        ListNode* newTail = newHead;

        // Run an infinite loop
        while(1){

            // This pointer points to the minimum head value
            ListNode* minHead = new ListNode(INT_MAX);
            // To store the index of minimum head, so that it can be updated in list
            int minIndex = -1;
            // Count NULL pointers in the list, at the end this will equal the size of list
            int nullCount = 0;

            // loop to find the minimum val head
            for(int i=0; i<lists.size(); i++){

                if(lists[i]==NULL){
                    nullCount++;
                    // If every head is now NULL in the list, we merged the lists
                    if(nullCount==lists.size())
                        return newHead->next;
                    // ignore if NULL
                    continue;
                }


                if(minHead->val>lists[i]->val){
                    minHead = lists[i];
                    minIndex = i;
                }

            }

            // insert this minimum val node to our merged list
            // update the pointers for next iteration
            newTail->next = minHead;
            lists[minIndex] = minHead->next;
            newTail = newTail->next;
            newTail->next = NULL;


        }

        return newHead->next;
    }
};
