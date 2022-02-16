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
    
    // reverse the two node
    ListNode *change(ListNode* first)
    {
        ListNode *second = first->next;
        
        // exchange
        first->next = second->next;
        second->next = first;
        
        // return the linking node
        return second;
    }
    
    ListNode* swapPairs(ListNode* head) 
    {
        // list consists of 0 or 1 node
        if(head == NULL || head->next == NULL)
            return head;
        
        // track head node
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        head = dummy;
        
        // changing process
        while(dummy && dummy->next && dummy->next->next)
        {
            dummy->next = change(dummy->next);
            
            dummy = dummy->next->next;
        }
        
        // head was stored at dummy , so return head next
        return head->next;
    }
};
