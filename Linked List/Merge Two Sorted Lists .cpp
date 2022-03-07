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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        // to track the head
        ListNode *dummy = new ListNode(-1);
        
        // prev pointer will join all the list
        ListNode *prev = dummy;
        ListNode *l1 = list1, *l2 = list2;
        
        // till both list exist
        while(l1 && l2)
        {
            // check which node is having less value
            if(l1->val <= l2->val)
            {
                prev->next = l1;
                l1 = l1->next;
                prev = prev->next;
            }
            else
            {
                prev->next = l2;
                l2 = l2->next;
                prev = prev->next;
            }
        }
        
        // if only list 1 exist
        if(l1)
            prev->next = l1;
        
        // if only list 2 exist
        if(l2)
            prev->next = l2;
        
        
        // return the first node just after dummy; that will be our head
        return dummy->next;
    }
};
