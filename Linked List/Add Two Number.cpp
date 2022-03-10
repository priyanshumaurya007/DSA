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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        // if any of the list is empty then return the other
        if(!l1)
            return l2;
        if(!l2)
            return l1;
        
        // to track the head of new list
        ListNode *dummy = new ListNode(-1);
        
        // curr pointer will create the list
        ListNode *curr = dummy;
        
        // carry and sum to calculate the node value
        int carry = 0, sum = 0;
        
        // loop runs till any list contains the node
        while(l1 || l2)
        {
            // calculate sum and carry
            sum = (l1 == NULL ? 0 : l1->val) + (l2 == NULL ? 0 : l2->val) + carry;
            carry = sum / 10;
            sum = sum % 10;
            
            // make new node
            curr->next = new ListNode(sum);
            curr = curr->next;
            
            // if list exist, go to next node
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
                
        }
        
        // if carry exist for last value then make a node for it
        if(carry>0)
            curr->next = new ListNode(carry);
        
        
        return dummy->next;
    }
};
